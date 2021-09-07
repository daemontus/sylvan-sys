use libc::{c_char, c_int, c_void, size_t, FILE};

pub type MT_HASH_CB = extern "C" fn(u64, u64) -> u64;
pub type MT_EQUALS_CB = extern "C" fn(u64, u64) -> c_int;
pub type MT_CREATE_CB = extern "C" fn(*mut u64);
pub type MT_DESTROY_CB = extern "C" fn(u64);
pub type MT_TO_STR_CB = extern "C" fn(c_int, u64, *mut c_char, size_t) -> *mut c_char;
pub type MT_WRITE_BINARY_CB = extern "C" fn(*mut FILE, u64) -> c_int;
pub type MT_READ_BINARY_CB = extern "C" fn(*mut FILE, *mut u64) -> c_int;

extern "C" {

    pub fn Sylvan_init_mt() -> c_void;
    pub fn Sylvan_mt_create_type() -> u32;
    pub fn Sylvan_mt_set_hash(terminal_type: u32, hash_cb: MT_HASH_CB) -> c_void;
    pub fn Sylvan_mt_set_equals(terminal_type: u32, equals_cb: MT_EQUALS_CB) -> c_void;
    pub fn Sylvan_mt_set_create(terminal_type: u32, create_cb: MT_CREATE_CB) -> c_void;
    pub fn Sylvan_mt_set_destroy(terminal_type: u32, destroy_cb: MT_DESTROY_CB) -> c_void;
    pub fn Sylvan_mt_set_to_str(terminal_type: u32, to_str_cb: MT_TO_STR_CB) -> c_void;
    pub fn Sylvan_mt_set_write_binary(
        terminal_type: u32,
        write_binary_cb: MT_WRITE_BINARY_CB,
    ) -> c_void;
    pub fn Sylvan_mt_set_read_binary(
        terminal_type: u32,
        read_binary_cb: MT_READ_BINARY_CB,
    ) -> c_void;
    pub fn Sylvan_mt_has_custom_hash(terminal_type: u32) -> c_int;
    pub fn Sylvan_mt_hash(terminal_type: u32, value: u64, seed: u64) -> u64;
    pub fn Sylvan_mt_to_str(
        complement: c_int,
        terminal_type: u32,
        value: u64,
        buf: *mut c_char,
        buflen: size_t,
    ) -> *mut c_char;
    pub fn Sylvan_mt_write_binary(terminal_type: u32, value: u64, out: *mut FILE) -> c_int;
    pub fn Sylvan_mt_read_binary(terminal_type: u32, value: *mut u64, input: *mut FILE) -> c_int;

}
