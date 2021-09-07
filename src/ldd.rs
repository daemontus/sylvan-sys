use crate::lace::{Task, WorkerP};
use crate::MDD;
use libc::{c_char, c_double, c_int, c_long, c_void, size_t, FILE};

pub type LDDMC_ENUM_CB = extern "C" fn(*mut WorkerP, *mut Task, *mut u32, size_t, *mut c_void);
pub type LDDMC_COLLECT_CB =
    extern "C" fn(*mut WorkerP, *mut Task, *mut u32, size_t, *mut c_void) -> MDD;
pub type LDDMC_VISIT_PRE_CB = extern "C" fn(*mut WorkerP, *mut Task, MDD, *mut c_void) -> c_int;
pub type LDDMC_VISIT_POST_CB = extern "C" fn(*mut WorkerP, *mut Task, MDD, *mut c_void);
pub type LDDMC_VISIT_INIT_CONTEXT_CB =
    extern "C" fn(*mut WorkerP, *mut Task, *mut c_void, *mut c_void, c_int);
pub type LDDMC_COMPOSE_CB = extern "C" fn(*mut WorkerP, *mut Task, MDD, *mut c_void) -> MDD;

#[repr(C)]
pub struct LDDMCCallbacks {
    pub pre: LDDMC_VISIT_PRE_CB,
    pub post: LDDMC_VISIT_POST_CB,
    pub context: LDDMC_VISIT_INIT_CONTEXT_CB,
}

extern "C" {
    pub fn Sylvan_init_ldd() -> c_void;
    pub fn Sylvan_lddmc_makenode(value: u32, ifeq: MDD, ifneq: MDD) -> MDD;
    pub fn Sylvan_lddmc_extendnode(mdd: MDD, value: u32, ifeq: MDD) -> MDD;
    pub fn Sylvan_lddmc_getvalue(mdd: MDD) -> u32;
    pub fn Sylvan_lddmc_getdown(mdd: MDD) -> MDD;
    pub fn Sylvan_lddmc_getright(mdd: MDD) -> MDD;
    pub fn Sylvan_lddmc_follow(mdd: MDD, value: u32) -> MDD;
    pub fn Sylvan_lddmc_make_copynode(ifeq: MDD, ifneq: MDD) -> MDD;
    pub fn Sylvan_lddmc_iscopy(mdd: MDD) -> c_int;
    pub fn Sylvan_lddmc_followcopy(mdd: MDD) -> MDD;
    pub fn Sylvan_lddmc_protect(ptr: *mut MDD) -> c_void;
    pub fn Sylvan_lddmc_unprotect(ptr: *mut MDD) -> c_void;
    pub fn Sylvan_lddmc_count_protected() -> size_t;
    pub fn Sylvan_lddmc_ref(dd: MDD) -> MDD;
    pub fn Sylvan_lddmc_deref(dd: MDD) -> c_void;
    pub fn Sylvan_lddmc_count_refs() -> size_t;
    pub fn Sylvan_lddmc_gc_mark_rec(mdd: MDD) -> c_void;
    pub fn Sylvan_lddmc_union(a: MDD, b: MDD) -> MDD;
    pub fn Sylvan_lddmc_minus(a: MDD, b: MDD) -> MDD;
    pub fn Sylvan_lddmc_zip(a: MDD, b: MDD, res: *mut MDD) -> MDD;
    pub fn Sylvan_lddmc_intersect(a: MDD, b: MDD) -> MDD;
    pub fn Sylvan_lddmc_match(a: MDD, b: MDD, proj: MDD) -> MDD;
    pub fn Sylvan_lddmc_union_cube(a: MDD, values: *mut u32, count: size_t) -> MDD;
    pub fn Sylvan_lddmc_member_cube(a: MDD, values: *mut u32, count: size_t) -> c_int;
    pub fn Sylvan_lddmc_cube(values: *mut u32, count: size_t) -> MDD;
    pub fn Sylvan_lddmc_union_cube_copy(
        a: MDD,
        values: *mut u32,
        copy: *mut c_int,
        count: size_t,
    ) -> MDD;
    pub fn Sylvan_lddmc_member_cube_copy(
        a: MDD,
        values: *mut u32,
        copy: *mut c_int,
        count: size_t,
    ) -> c_int;
    pub fn Sylvan_lddmc_cube_copy(values: *mut u32, copy: *mut c_int, count: size_t) -> MDD;
    pub fn Sylvan_lddmc_relprod(a: MDD, b: MDD, proj: MDD) -> MDD;
    pub fn Sylvan_lddmc_relprod_union(a: MDD, b: MDD, meta: MDD, un: MDD) -> MDD;
    pub fn Sylvan_lddmc_relprev(a: MDD, rel: MDD, proj: MDD, uni: MDD) -> MDD;
    pub fn Sylvan_lddmc_project(mdd: MDD, proj: MDD) -> MDD;
    pub fn Sylvan_lddmc_project_minus(mdd: MDD, proj: MDD, avoid: MDD) -> MDD;
    pub fn Sylvan_lddmc_join(a: MDD, b: MDD, a_proj: MDD, b_proj: MDD) -> MDD;
    pub fn Sylvan_lddmc_printdot(mdd: MDD) -> c_void;
    pub fn Sylvan_lddmc_fprintdot(out: *mut FILE, mdd: MDD) -> c_void;
    pub fn Sylvan_lddmc_fprint(out: *mut FILE, mdd: MDD) -> c_void;
    pub fn Sylvan_lddmc_print(mdd: MDD) -> c_void;
    pub fn Sylvan_lddmc_printsha(mdd: MDD) -> c_void;
    pub fn Sylvan_lddmc_fprintsha(out: *mut FILE, mdd: MDD) -> c_void;
    pub fn Sylvan_lddmc_getsha(mdd: MDD, target: *mut c_char) -> c_void;
    pub fn Sylvan_lddmc_satcount_cached(mdd: MDD) -> c_double;
    /*
       Due to missing support in Rust, we can't really safely work with C-style f128 values.
       pub fn Sylvan_lddmc_satcount(mdd: MDD) -> f128;
    */
    pub fn Sylvan_lddmc_sat_all_par(mdd: MDD, cb: LDDMC_ENUM_CB, context: *mut c_void) -> c_void;
    pub fn Sylvan_lddmc_sat_all_nopar(mdd: MDD, cb: LDDMC_ENUM_CB, context: *mut c_void) -> c_void;
    pub fn Sylvan_lddmc_collect(md: MDD, cb: LDDMC_COLLECT_CB, context: *mut c_void) -> MDD;
    pub fn Sylvan_lddmc_match_sat_par(
        mdd: MDD,
        to_match: MDD,
        proj: MDD,
        cb: LDDMC_ENUM_CB,
        context: *mut c_void,
    ) -> c_void;
    pub fn Sylvan_lddmc_sat_one(mdd: MDD, values: *mut u32, count: size_t) -> c_int;
    pub fn Sylvan_lddmc_sat_one_mdd(mdd: MDD) -> MDD;
    pub fn Sylvan_lddmc_pick_cube(mdd: MDD) -> MDD;
    pub fn Sylvan_lddmc_visit_par(
        mdd: MDD,
        cbs: *mut LDDMCCallbacks,
        ctx_size: size_t,
        context: *mut c_void,
    ) -> c_void;
    pub fn Sylvan_lddmc_visit_seq(
        mdd: MDD,
        cbs: *mut LDDMCCallbacks,
        ctx_size: size_t,
        context: *mut c_void,
    ) -> c_void;
    pub fn Sylvan_lddmc_nodecount(mdd: MDD) -> size_t;
    pub fn Sylvan_lddmc_nodecount_levels(mdd: MDD, variables: *mut size_t) -> c_void;
    pub fn Sylvan_lddmc_compose(
        mdd: MDD,
        cb: LDDMC_COMPOSE_CB,
        context: *mut c_void,
        depth: c_int,
    ) -> MDD;
    pub fn Sylvan_lddmc_serialize_add(mdd: MDD) -> size_t;
    pub fn Sylvan_lddmc_serialize_get(mdd: MDD) -> size_t;
    pub fn Sylvan_lddmc_serialize_get_reversed(value: size_t) -> MDD;
    pub fn Sylvan_lddmc_serialize_reset() -> c_void;
    pub fn Sylvan_lddmc_serialize_totext(out: *mut FILE) -> c_void;
    pub fn Sylvan_lddmc_serialize_tofile(out: *mut FILE) -> c_void;
    pub fn Sylvan_lddmc_serialize_fromfile(input: *mut FILE) -> c_void;
    pub fn Sylvan_lddmc_refs_pushptr(ptr: *const MDD) -> c_void;
    pub fn Sylvan_lddmc_refs_popptr(amount: size_t) -> c_void;
    pub fn Sylvan_lddmc_refs_push(dd: MDD) -> MDD;
    pub fn Sylvan_lddmc_refs_pop(amount: c_long) -> c_void;
    pub fn Sylvan_lddmc_refs_spawn(t: *mut Task) -> c_void;
    pub fn Sylvan_lddmc_refs_sync(dd: MDD) -> MDD;
}
