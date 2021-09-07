use crate::lace::{Task, WorkerP};
use crate::{MTBDD, MTBDDMAP};
use libc::{c_char, c_double, c_int, c_long, c_void, size_t, FILE};
use std::marker::{PhantomData, PhantomPinned};

pub type MTBDD_APPLY_OP = extern "C" fn(*mut WorkerP, *mut Task, *mut MTBDD, *mut MTBDD) -> MTBDD;
pub type MTBDD_APPLYP_OP =
    extern "C" fn(*mut WorkerP, *mut Task, *mut MTBDD, *mut MTBDD, size_t) -> MTBDD;
pub type MTBDD_UAPPLY_OP = extern "C" fn(*mut WorkerP, *mut Task, MTBDD, size_t) -> MTBDD;
pub type MTBDD_ABSTRACT_OP = extern "C" fn(*mut WorkerP, *mut Task, MTBDD, MTBDD, c_int) -> MTBDD;
pub type MTBDD_ENUM_CB =
    extern "C" fn(*mut WorkerP, *mut Task, *mut MTBDDEnumTrace, MTBDD, *mut c_void);
pub type MTBDD_EVAL_COMPOSE_CB = extern "C" fn(*mut WorkerP, *mut Task, MTBDD) -> MTBDD;
pub type MTBDD_VISIT_PRE_CB = extern "C" fn(*mut WorkerP, *mut Task, MTBDD, *mut c_void) -> c_int;
pub type MTBDD_VISIT_POST_CB = extern "C" fn(*mut WorkerP, *mut Task, MTBDD, *mut c_void);
pub type MTBDD_ENUM_FILTER_CB = extern "C" fn(MTBDD) -> c_int;

#[repr(C)]
pub struct MTBDDEnumTrace {
    pub prev: *mut MTBDDEnumTrace,
    pub var: u32,
    pub val: c_int,
}

/// An opaque C struct representing a skip list used during serialisation.
#[repr(C)]
pub struct SkipList {
    _data: [u8; 0],
    _marker: PhantomData<(*mut u8, PhantomPinned)>,
}

pub type SkipListPtr = *mut SkipList;

extern "C" {
    pub fn Sylvan_init_mtbdd() -> c_void;
    pub fn Sylvan_init_bdd() -> c_void;
    pub fn Sylvan_mtbdd_makeleaf(leaf_type: u32, value: u64) -> MTBDD;
    pub fn Sylvan_mtbdd_makenode(var: u32, low: MTBDD, high: MTBDD) -> MTBDD;
    pub fn Sylvan_makenode(var: u32, low: MTBDD, high: MTBDD) -> MTBDD;
    pub fn Sylvan_mtbdd_isleaf(mtbdd: MTBDD) -> c_int;
    pub fn Sylvan_mtbdd_isnode(mtbdd: MTBDD) -> c_int;
    pub fn Sylvan_mtbdd_gettype(leaf: MTBDD) -> u32;
    pub fn Sylvan_mtbdd_getvalue(leaf: MTBDD) -> u64;
    pub fn Sylvan_mtbdd_getvar(node: MTBDD) -> u32;
    pub fn Sylvan_var(node: MTBDD) -> u32;
    pub fn Sylvan_mtbdd_getlow(node: MTBDD) -> MTBDD;
    pub fn Sylvan_low(node: MTBDD) -> MTBDD;
    pub fn Sylvan_mtbdd_gethigh(node: MTBDD) -> MTBDD;
    pub fn Sylvan_high(node: MTBDD) -> MTBDD;
    pub fn Sylvan_mtbdd_hascomp(dd: MTBDD) -> c_int;
    pub fn Sylvan_mtbdd_comp(dd: MTBDD) -> MTBDD;
    pub fn Sylvan_mtbdd_not(dd: MTBDD) -> MTBDD;
    pub fn Sylvan_mtbdd_int64(value: i64) -> MTBDD;
    pub fn Sylvan_mtbdd_double(value: c_double) -> MTBDD;
    pub fn Sylvan_mtbdd_fraction(numer: i64, denom: u64) -> MTBDD;
    pub fn Sylvan_mtbdd_getint64(terminal: MTBDD) -> i64;
    pub fn Sylvan_mtbdd_getdouble(terminal: MTBDD) -> c_double;
    pub fn Sylvan_mtbdd_getnumer(terminal: MTBDD) -> i32;
    pub fn Sylvan_mtbdd_getdenom(terminal: MTBDD) -> u32;
    pub fn Sylvan_mtbdd_ithvar(var: u32) -> MTBDD;
    pub fn Sylvan_ithvar(var: u32) -> MTBDD;
    pub fn Sylvan_mtbdd_set_empty() -> MTBDD;
    pub fn Sylvan_set_empty() -> MTBDD;
    pub fn Sylvan_mtbdd_set_isempty(set: MTBDD) -> c_int;
    pub fn Sylvan_set_isempty(set: MTBDD) -> c_int;
    pub fn Sylvan_mtbdd_set_first(set: MTBDD) -> u32;
    pub fn Sylvan_set_first(set: MTBDD) -> u32;
    pub fn Sylvan_mtbdd_set_next(set: MTBDD) -> MTBDD;
    pub fn Sylvan_set_next(set: MTBDD) -> MTBDD;
    pub fn Sylvan_mtbdd_set_from_array(arr: *mut u32, length: size_t) -> MTBDD;
    pub fn Sylvan_mtbdd_fromarray(arr: *mut u32, length: size_t) -> MTBDD;
    pub fn Sylvan_mtbdd_set_fromarray(arr: *mut u32, length: size_t) -> MTBDD;
    pub fn Sylvan_set_fromarray(arr: *mut u32, length: size_t) -> MTBDD;
    pub fn Sylvan_mtbdd_set_to_array(set: MTBDD, arr: *mut u32) -> c_void;
    pub fn Sylvan_mtbdd_set_toarray(set: MTBDD, arr: *mut u32) -> c_void;
    pub fn Sylvan_set_toarray(set: MTBDD, arr: *mut u32) -> c_void;
    pub fn Sylvan_mtbdd_set_count(set: MTBDD) -> size_t;
    pub fn Sylvan_set_count(set: MTBDD) -> size_t;
    pub fn Sylvan_mtbdd_set_union(set1: MTBDD, set2: MTBDD) -> MTBDD;
    pub fn Sylvan_mtbdd_set_addall(set1: MTBDD, set2: MTBDD) -> MTBDD;
    pub fn Sylvan_set_addall(set1: MTBDD, set2: MTBDD) -> MTBDD;
    pub fn Sylvan_mtbdd_set_minus(set1: MTBDD, set2: MTBDD) -> MTBDD;
    pub fn Sylvan_mtbdd_set_removeall(set1: MTBDD, set2: MTBDD) -> MTBDD;
    pub fn Sylvan_set_removeall(set1: MTBDD, set2: MTBDD) -> MTBDD;
    pub fn Sylvan_mtbdd_set_contains(set: MTBDD, var: u32) -> c_int;
    pub fn Sylvan_mtbdd_set_in(set: MTBDD, var: u32) -> c_int;
    pub fn Sylvan_set_in(set: MTBDD, var: u32) -> c_int;
    pub fn Sylvan_mtbdd_set_add(set: MTBDD, var: u32) -> MTBDD;
    pub fn Sylvan_set_add(set: MTBDD, var: u32) -> MTBDD;
    pub fn Sylvan_mtbdd_set_remove(set: MTBDD, var: u32) -> MTBDD;
    pub fn Sylvan_set_remove(set: MTBDD, var: u32) -> MTBDD;
    pub fn Sylvan_mtbdd_test_isset(set: MTBDD) -> c_void;
    pub fn Sylvan_test_isset(set: MTBDD) -> c_void;
    pub fn Sylvan_mtbdd_cube(variables: MTBDD, cube: *mut u8, terminal: MTBDD) -> MTBDD;
    pub fn Sylvan_mtbdd_union_cube(
        mtbdd: MTBDD,
        variables: MTBDD,
        cube: *mut u8,
        terminal: MTBDD,
    ) -> MTBDD;
    pub fn Sylvan_mtbdd_satcount(dd: MTBDD, nvars: size_t) -> c_double;
    pub fn Sylvan_mtbdd_leafcount_more(mtbdds: *const MTBDD, count: size_t) -> size_t;
    pub fn Sylvan_mtbdd_leafcount(dd: MTBDD) -> size_t;
    pub fn Sylvan_mtbdd_nodecount_more(mtbdds: *const MTBDD, count: size_t) -> size_t;
    pub fn Sylvan_mtbdd_nodecount(dd: MTBDD) -> size_t;
    pub fn Sylvan_nodecount(dd: MTBDD) -> size_t;
    pub fn Sylvan_mtbdd_apply(a: MTBDD, b: MTBDD, op: MTBDD_APPLY_OP) -> MTBDD;
    pub fn Sylvan_mtbdd_applyp(
        a: MTBDD,
        b: MTBDD,
        p: size_t,
        op: MTBDD_APPLYP_OP,
        opid: u64,
    ) -> MTBDD;
    pub fn Sylvan_mtbdd_uapply(dd: MTBDD, op: MTBDD_UAPPLY_OP, param: size_t) -> MTBDD;
    pub fn Sylvan_mtbdd_abstract(a: MTBDD, v: MTBDD, op: MTBDD_ABSTRACT_OP) -> MTBDD;
    pub fn Sylvan_mtbdd_negate(a: MTBDD) -> MTBDD;
    pub fn Sylvan_mtbdd_cmpl(a: MTBDD) -> MTBDD;
    pub fn Sylvan_mtbdd_plus(a: MTBDD, b: MTBDD) -> MTBDD;
    pub fn Sylvan_mtbdd_minus(a: MTBDD, b: MTBDD) -> MTBDD;
    pub fn Sylvan_mtbdd_times(a: MTBDD, b: MTBDD) -> MTBDD;
    pub fn Sylvan_mtbdd_min(a: MTBDD, b: MTBDD) -> MTBDD;
    pub fn Sylvan_mtbdd_max(a: MTBDD, b: MTBDD) -> MTBDD;
    pub fn Sylvan_mtbdd_abstract_plus(dd: MTBDD, v: MTBDD) -> MTBDD;
    pub fn Sylvan_mtbdd_abstract_times(dd: MTBDD, v: MTBDD) -> MTBDD;
    pub fn Sylvan_mtbdd_abstract_min(dd: MTBDD, v: MTBDD) -> MTBDD;
    pub fn Sylvan_mtbdd_abstract_max(dd: MTBDD, v: MTBDD) -> MTBDD;
    pub fn Sylvan_mtbdd_ite(f: MTBDD, g: MTBDD, h: MTBDD) -> MTBDD;
    pub fn Sylvan_mtbdd_and_abstract_plus(a: MTBDD, b: MTBDD, vars: MTBDD) -> MTBDD;
    pub fn Sylvan_mtbdd_and_exists(a: MTBDD, b: MTBDD, vars: MTBDD) -> MTBDD;
    pub fn Sylvan_mtbdd_and_abstract_max(a: MTBDD, b: MTBDD, vars: MTBDD) -> MTBDD;
    pub fn Sylvan_mtbdd_threshold_double(dd: MTBDD, value: c_double) -> MTBDD;
    pub fn Sylvan_mtbdd_strict_threshold_double(dd: MTBDD, value: c_double) -> MTBDD;
    pub fn Sylvan_mtbdd_equal_norm_d(a: MTBDD, b: MTBDD, epsilon: c_double) -> MTBDD;
    pub fn Sylvan_mtbdd_equal_norm_rel_d(a: MTBDD, b: MTBDD, epsilon: c_double) -> MTBDD;
    pub fn Sylvan_mtbdd_leq(a: MTBDD, b: MTBDD) -> MTBDD;
    pub fn Sylvan_mtbdd_less(a: MTBDD, b: MTBDD) -> MTBDD;
    pub fn Sylvan_mtbdd_geq(a: MTBDD, b: MTBDD) -> MTBDD;
    pub fn Sylvan_mtbdd_greater(a: MTBDD, b: MTBDD) -> MTBDD;
    pub fn Sylvan_mtbdd_support(dd: MTBDD) -> MTBDD;
    pub fn Sylvan_support(dd: MTBDD) -> MTBDD;
    pub fn Sylvan_mtbdd_compose(dd: MTBDD, map: MTBDDMAP) -> MTBDD;
    pub fn Sylvan_mtbdd_minimum(dd: MTBDD) -> MTBDD;
    pub fn Sylvan_mtbdd_maximum(dd: MTBDD) -> MTBDD;
    pub fn Sylvan_mtbdd_enum_first(
        dd: MTBDD,
        variables: MTBDD,
        arr: *mut u8,
        filter_cb: MTBDD_ENUM_FILTER_CB,
    ) -> MTBDD;
    pub fn Sylvan_mtbdd_enum_next(
        dd: MTBDD,
        variables: MTBDD,
        arr: *mut u8,
        filter_cb: MTBDD_ENUM_FILTER_CB,
    ) -> MTBDD;
    pub fn Sylvan_mtbdd_enum_all_first(
        dd: MTBDD,
        variables: MTBDD,
        arr: *mut u8,
        filter_cb: MTBDD_ENUM_FILTER_CB,
    ) -> MTBDD;
    pub fn Sylvan_mtbdd_enum_all_next(
        dd: MTBDD,
        variables: MTBDD,
        arr: *mut u8,
        filter_cb: MTBDD_ENUM_FILTER_CB,
    ) -> MTBDD;
    pub fn Sylvan_mtbdd_enum_par(dd: MTBDD, cb: MTBDD_ENUM_CB, context: *mut c_void) -> c_void;
    pub fn Sylvan_mtbdd_eval_compose(dd: MTBDD, vars: MTBDD, cb: MTBDD_EVAL_COMPOSE_CB) -> MTBDD;
    pub fn Sylvan_mtbdd_test_isvalid(mtbdd: MTBDD) -> c_int;
    pub fn Sylvan_test_isbdd(mtbdd: MTBDD) -> c_int;
    pub fn Sylvan_mtbdd_fprintdot(out: *mut FILE, mtbdd: MTBDD) -> c_void;
    pub fn Sylvan_fprintdot(out: *mut FILE, mtbdd: MTBDD) -> c_void;
    pub fn Sylvan_mtbdd_printdot(mtbdd: MTBDD) -> c_void;
    pub fn Sylvan_printdot(mtbdd: MTBDD) -> c_void;
    pub fn Sylvan_mtbdd_fprintdot_nc(out: *mut FILE, mtbdd: MTBDD) -> c_void;
    pub fn Sylvan_mtbdd_printdot_nc(mtbdd: MTBDD) -> c_void;
    pub fn Sylvan_mtbdd_fprint_leaf(out: *mut FILE, leaf: MTBDD) -> c_void;
    pub fn Sylvan_mtbdd_print_leaf(leaf: MTBDD) -> c_void;
    pub fn Sylvan_mtbdd_leaf_to_str(leaf: MTBDD, buf: *mut c_char, buflen: size_t) -> *mut c_char;
    pub fn Sylvan_mtbdd_printsha(dd: MTBDD) -> c_void;
    pub fn Sylvan_printsha(dd: MTBDD) -> c_void;
    pub fn Sylvan_mtbdd_fprintsha(f: *mut FILE, dd: MTBDD) -> c_void;
    pub fn Sylvan_fprintsha(f: *mut FILE, dd: MTBDD) -> c_void;
    pub fn Sylvan_mtbdd_getsha(dd: MTBDD, target: *mut c_char) -> c_void;
    pub fn Sylvan_getsha(dd: MTBDD, target: *mut c_char) -> c_void;
    pub fn Sylvan_mtbdd_visit_seq(
        dd: MTBDD,
        pre: MTBDD_VISIT_PRE_CB,
        post: MTBDD_VISIT_POST_CB,
        context: *mut c_void,
    ) -> c_void;
    pub fn Sylvan_mtbdd_visit_par(
        dd: MTBDD,
        pre: MTBDD_VISIT_PRE_CB,
        post: MTBDD_VISIT_POST_CB,
        context: *mut c_void,
    ) -> c_void;
    pub fn Sylvan_mtbdd_writer_tobinary(file: *mut FILE, dds: *mut MTBDD, count: c_int) -> c_void;
    pub fn Sylvan_mtbdd_writer_totext(file: *mut FILE, dds: *mut MTBDD, count: c_int) -> c_void;
    pub fn Sylvan_mtbdd_writer_start() -> SkipListPtr;
    pub fn Sylvan_mtbdd_writer_add(sl: SkipListPtr, dd: MTBDD) -> c_void;
    pub fn Sylvan_mtbdd_writer_writebinary(out: *mut FILE, sl: SkipListPtr) -> c_void;
    pub fn Sylvan_mtbdd_writer_get(sl: SkipListPtr, dd: MTBDD) -> u64;
    pub fn Sylvan_mtbdd_writer_end(sl: SkipListPtr) -> c_void;
    pub fn Sylvan_mtbdd_reader_frombinary(file: *mut FILE, dds: *mut MTBDD, count: c_int) -> c_int;
    pub fn Sylvan_mtbdd_reader_readbinary(file: *mut FILE) -> *mut u64;
    pub fn Sylvan_mtbdd_reader_get(arr: *mut u64, identifier: u64) -> MTBDD;
    pub fn Sylvan_mtbdd_reader_end(arr: *mut u64) -> c_void;
    pub fn Sylvan_mtbdd_map_empty() -> MTBDD;
    pub fn Sylvan_map_empty() -> MTBDD;
    pub fn Sylvan_mtbdd_map_isempty(map: MTBDD) -> c_int;
    pub fn Sylvan_map_isempty(map: MTBDD) -> c_int;
    pub fn Sylvan_mtbdd_map_key(map: MTBDD) -> u32;
    pub fn Sylvan_map_key(map: MTBDD) -> u32;
    pub fn Sylvan_mtbdd_map_value(map: MTBDD) -> MTBDD;
    pub fn Sylvan_map_value(map: MTBDD) -> MTBDD;
    pub fn Sylvan_mtbdd_map_next(map: MTBDD) -> MTBDD;
    pub fn Sylvan_map_next(map: MTBDD) -> MTBDD;
    pub fn Sylvan_mtbdd_map_contains(map: MTBDDMAP, key: u32) -> c_int;
    pub fn Sylvan_map_contains(map: MTBDDMAP, key: u32) -> c_int;
    pub fn Sylvan_mtbdd_map_count(map: MTBDDMAP) -> size_t;
    pub fn Sylvan_map_count(map: MTBDDMAP) -> size_t;
    pub fn Sylvan_mtbdd_map_add(map: MTBDDMAP, key: u32, value: MTBDD) -> MTBDDMAP;
    pub fn Sylvan_map_add(map: MTBDDMAP, key: u32, value: MTBDD) -> MTBDDMAP;
    pub fn Sylvan_mtbdd_map_update(map1: MTBDDMAP, map2: MTBDDMAP) -> MTBDDMAP;
    pub fn Sylvan_mtbdd_map_addall(map1: MTBDDMAP, map2: MTBDDMAP) -> MTBDDMAP;
    pub fn Sylvan_map_addall(map1: MTBDDMAP, map2: MTBDDMAP) -> MTBDDMAP;
    pub fn Sylvan_mtbdd_map_remove(map: MTBDDMAP, key: u32) -> MTBDDMAP;
    pub fn Sylvan_map_remove(map: MTBDDMAP, key: u32) -> MTBDDMAP;
    pub fn Sylvan_mtbdd_map_removeall(map: MTBDDMAP, variables: MTBDD) -> MTBDDMAP;
    pub fn Sylvan_map_removeall(map: MTBDDMAP, variables: MTBDD) -> MTBDDMAP;
    pub fn Sylvan_mtbdd_gc_mark_rec(mtbdd: MTBDD) -> c_void;
    pub fn Sylvan_gc_mark_rec(mtbdd: MTBDD) -> c_void;
    pub fn Sylvan_mtbdd_protect(ptr: *mut MTBDD) -> c_void;
    pub fn Sylvan_protect(ptr: *mut MTBDD) -> c_void;
    pub fn Sylvan_mtbdd_unprotect(ptr: *mut MTBDD) -> c_void;
    pub fn Sylvan_unprotect(ptr: *mut MTBDD) -> c_void;
    pub fn Sylvan_mtbdd_count_protected() -> size_t;
    pub fn Sylvan_count_protected() -> size_t;
    pub fn Sylvan_mtbdd_ref(dd: MTBDD) -> MTBDD;
    pub fn Sylvan_ref(dd: MTBDD) -> MTBDD;
    pub fn Sylvan_mtbdd_deref(dd: MTBDD) -> c_void;
    pub fn Sylvan_deref(dd: MTBDD) -> c_void;
    pub fn Sylvan_mtbdd_count_refs() -> size_t;
    pub fn Sylvan_count_refs() -> size_t;
    pub fn Sylvan_mtbdd_refs_pushptr(ptr: *const MTBDD) -> c_void;
    pub fn Sylvan_refs_pushptr(ptr: *const MTBDD) -> c_void;
    pub fn Sylvan_mtbdd_refs_popptr(amount: size_t) -> c_void;
    pub fn Sylvan_refs_popptr(amount: size_t) -> c_void;
    pub fn Sylvan_mtbdd_refs_push(mtbdd: MTBDD) -> MTBDD;
    pub fn Sylvan_refs_push(mtbdd: MTBDD) -> MTBDD;
    pub fn Sylvan_mtbdd_refs_pop(amount: c_long) -> c_void;
    pub fn Sylvan_refs_pop(amount: c_long) -> c_void;
    pub fn Sylvan_mtbdd_refs_spawn(t: *mut Task) -> c_void;
    pub fn Sylvan_refs_spawn(t: *mut Task) -> c_void;
    pub fn Sylvan_mtbdd_refs_sync(mtbdd: MTBDD) -> MTBDD;
    pub fn Sylvan_refs_sync(mtbdd: MTBDD) -> MTBDD;
}
