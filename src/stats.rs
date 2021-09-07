use libc::{c_void, FILE};

extern "C" {
    pub fn Sylvan_stats_init() -> c_void;
    pub fn Sylvan_stats_reset() -> c_void;
    // sylvan_stats_t is a gigantic struct with all performance counter data.
    // At the moment I don't have time to port the whole thing to Rust, so if you need it,
    // please do so yourself.
    // TODO: pub fn Sylvan_stats_snapshot(target: *mut sylvan_stats_t) -> c_void;
    pub fn Sylvan_stats_report(target: *mut FILE) -> c_void;
}
