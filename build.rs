extern crate cmake;

use cmake::Config;
use std::env;
use std::path::PathBuf;

fn main() -> Result<(), String> {
    let build_sylvan = env::var_os("CARGO_FEATURE_BUILD_SYLVAN").is_some();
    if !build_sylvan {
        // If silent build is active, don't do anything.
        return Ok(());
    }

    let out_dir = env::var("OUT_DIR")
        .map_err(|_| "Environmental variable `OUT_DIR` not defined.".to_string())?;

    let wrapper_path = PathBuf::from("wrapper");
    let mut cfg = Config::new(wrapper_path);

    let is_debug = env::var_os("DEBUG").unwrap_or_else(|| "true".into());
    if is_debug == "true" {
        cfg.cflag("-Werror");
    }
    cfg.build();

    println!(
        "cargo:rustc-link-search=native={}",
        PathBuf::from(out_dir).join("lib").display()
    );
    println!("cargo:rustc-link-lib=static=lace");
    println!("cargo:rustc-link-lib=static=sylvan");
    println!("cargo:rustc-link-lib=static=wrapper");

    Ok(())
}
