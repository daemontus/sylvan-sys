extern crate cmake;

use cmake::Config;
use std::env;
use std::io::ErrorKind;
use std::path::{Path, PathBuf};
use std::process::Command;
use MD5Status::{Mismatch, Unknown};

const PACKAGE_URL: &str = "https://github.com/trolando/sylvan/archive/refs/tags/v1.6.1.tar.gz";
const PACKAGE_MD5: &str = "b6fbb2a782ba38cff44152c7478665ca";

#[derive(Debug)]
enum FetchError {
    CommandError(std::process::ExitStatus),
    IOError(std::io::Error),
    PathExists,
}

enum MD5Status {
    Match,
    Mismatch,
    Unknown,
}

impl From<std::io::Error> for FetchError {
    fn from(err: std::io::Error) -> FetchError {
        FetchError::IOError(err)
    }
}

/// Run a command and return (stdout, stderr) if exit status is success.
fn run_command(cmd: &mut Command) -> Result<(String, String), FetchError> {
    let output = cmd.output()?;

    return if output.status.success() {
        Ok((
            String::from_utf8(output.stdout).unwrap(),
            String::from_utf8(output.stderr).unwrap(),
        ))
    } else {
        eprintln!("Command {:?} exited with status {}", cmd, output.status);
        Err(FetchError::CommandError(output.status))
    };
}

/// Fetch a file from a URL if it does not already exist in out_dir and verify its md5sum if possible.
fn fetch_package(out_dir: &str, url: &str, md5: &str) -> Result<(PathBuf, MD5Status), FetchError> {
    let out_path = Path::new(&out_dir);
    let target_path = out_path.join(Path::new(url).file_name().unwrap());
    let target_path_str = target_path.clone().into_os_string().into_string().unwrap();

    match target_path.metadata() {
        Err(error) if error.kind() == ErrorKind::NotFound => {
            // Path does not exist! Start download...
            println!("Downloading {} to {}", url, target_path_str);
            let mut command = Command::new("curl");
            command.args(&["-L", url, "-o", target_path_str.as_str()]);
            run_command(&mut command)?;
        }
        Ok(data) if data.is_file() => {
            println!("{} exists. Skipping download.", target_path_str);
        }
        Ok(_) => return Err(FetchError::PathExists),
        Err(error) => return Err(FetchError::from(error)),
    }

    // Now run md5 sum check:
    let mut command_1 = Command::new("md5sum");
    command_1.arg(target_path.clone());
    let mut command_2 = Command::new("md5");
    command_2.arg(target_path.clone());
    let md5_result = run_command(&mut command_1).or_else(|_| run_command(&mut command_2));

    let md5_status = match md5_result {
        Err(_) => MD5Status::Unknown,
        Ok((output, _)) if output.contains(md5) => MD5Status::Match,
        _ => MD5Status::Mismatch,
    };

    Ok((target_path, md5_status))
}

fn main() -> Result<(), String> {
    let build_sylvan = env::var_os("CARGO_FEATURE_BUILD_SYLVAN").is_some();
    if !build_sylvan {
        // If silent build is active, don't do anything.
        return Ok(());
    }

    let out_dir = env::var("OUT_DIR")
        .map_err(|_| "Environmental variable `OUT_DIR` not defined.".to_string())?;

    let (tar_path, md5_status) = fetch_package(&out_dir, PACKAGE_URL, PACKAGE_MD5)
        .map_err(|e| format!("Error downloading Sylvan package: {:?}.", e))?;
    let tar_path_str = tar_path.to_str().unwrap().to_string();

    match md5_status {
        Unknown => eprintln!("WARNING: MD5 not computed. Package validation skipped."),
        Mismatch => return Err("Sylvan package MD5 hash mismatch.".to_string()),
        _ => (),
    }

    // Get sylvan.tar.gz path without extensions.
    let sylvan_path = tar_path.with_extension("").with_extension("");
    let sylvan_path_str = sylvan_path.clone().into_os_string().into_string().unwrap();

    if !sylvan_path.exists() {
        // Create the destination directory.
        std::fs::create_dir_all(sylvan_path.clone())
            .map_err(|e| format!("Cannot create Sylvan directory: {:?}", e))?;
    }

    // un-tar package, ignoring the name of the top level folder, dumping into sylvan_path instead.
    let mut tar_command = Command::new("tar");
    tar_command.args(&[
        "xf",
        &tar_path_str,
        "--strip-components=1",
        "-C",
        &sylvan_path_str,
    ]);
    run_command(&mut tar_command).map_err(|e| format!("Error decompressing CUDD: {:?}", e))?;

    let mut cfg = Config::new(sylvan_path);
    cfg.define("BUILD_STATIC_LIBS", "ON");
    cfg.define("BUILD_SHARED_LIBS", "OFF");
    let build_output = cfg.build();

    let wrapper_path = PathBuf::from("wrapper");
    let mut cfg = Config::new(wrapper_path);

    let is_debug = env::var_os("DEBUG").unwrap_or_else(|| "true".into());
    if is_debug == "true" {
        cfg.cflag("-Werror");
    }
    cfg.define("SYLVAN", build_output.clone());
    cfg.build();

    println!(
        "cargo:rustc-link-search=native={}",
        build_output.join("lib").display()
    );
    println!("cargo:rustc-link-lib=static=sylvan");
    println!("cargo:rustc-link-lib=static=wrapper");

    Ok(())
}
