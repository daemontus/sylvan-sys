use crate::lace::{Task, WorkerP};
use libc::{c_int, c_void, size_t};

pub type GC_HOOK_CB = extern "C" fn(*mut WorkerP, *mut Task);

extern "C" {

    pub fn Sylvan_init_package() -> c_void;
    pub fn Sylvan_set_sizes(
        min_tablesize: size_t,
        max_tablesize: size_t,
        min_cachesize: size_t,
        max_cachesize: size_t,
    ) -> c_void;
    pub fn Sylvan_set_limits(
        memory_cap: size_t,
        table_ratio: c_int,
        initial_ratio: c_int,
    ) -> c_void;
    pub fn Sylvan_quit() -> c_void;
    pub fn Sylvan_register_quit(cb: extern "C" fn()) -> c_void;
    pub fn Sylvan_table_usage(filled: *mut size_t, total: *mut size_t) -> c_void;
    pub fn Sylvan_gc() -> c_void;
    pub fn Sylvan_gc_enable() -> c_void;
    pub fn Sylvan_gc_disable() -> c_void;
    pub fn Sylvan_clear_cache() -> c_void;
    pub fn Sylvan_clear_and_mark() -> c_void;
    pub fn Sylvan_rehash_all() -> c_void;
    pub fn Sylvan_gc_hook_pregc(callback: GC_HOOK_CB) -> c_void;
    pub fn Sylvan_gc_hook_postgc(callback: GC_HOOK_CB) -> c_void;
    pub fn Sylvan_gc_hook_main(callback: GC_HOOK_CB) -> c_void;
    pub fn Sylvan_gc_add_mark(mark_cb: GC_HOOK_CB) -> c_void;

}
