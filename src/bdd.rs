use crate::lace::{Task, WorkerP};
use crate::{BDD, BDDMAP, BDDSET, BDDVAR, MTBDD};
use libc::{c_double, c_int, c_void, size_t, FILE};

pub type ENUM_CB = extern "C" fn(*mut WorkerP, *mut Task, *mut c_void, *mut BDDVAR, *mut u8, c_int);
pub type COLLECT_CB = extern "C" fn(*mut WorkerP, *mut Task, *mut c_void, *mut u8) -> BDD;

extern "C" {

    pub fn Sylvan_isconst(bdd: MTBDD) -> c_int;
    pub fn Sylvan_isnode(bdd: MTBDD) -> c_int;
    pub fn Sylvan_set_granularity(granularity: c_int) -> c_void;
    pub fn Sylvan_get_granularity() -> c_int;
    pub fn Sylvan_not(a: BDD) -> BDD;
    pub fn Sylvan_ite(a: BDD, b: BDD, c: BDD) -> BDD;
    pub fn Sylvan_and(a: BDD, b: BDD) -> BDD;
    pub fn Sylvan_xor(a: BDD, b: BDD) -> BDD;
    pub fn Sylvan_equiv(a: BDD, b: BDD) -> BDD;
    pub fn Sylvan_or(a: BDD, b: BDD) -> BDD;
    pub fn Sylvan_nand(a: BDD, b: BDD) -> BDD;
    pub fn Sylvan_nor(a: BDD, b: BDD) -> BDD;
    pub fn Sylvan_imp(a: BDD, b: BDD) -> BDD;
    pub fn Sylvan_invimp(a: BDD, b: BDD) -> BDD;
    pub fn Sylvan_biimp(a: BDD, b: BDD) -> BDD;
    pub fn Sylvan_diff(a: BDD, b: BDD) -> BDD;
    pub fn Sylvan_less(a: BDD, b: BDD) -> BDD;
    pub fn Sylvan_nithvar(var: u32) -> BDD;
    pub fn Sylvan_exists(a: BDD, vars: BDD) -> BDD;
    pub fn Sylvan_forall(a: BDD, vars: BDD) -> BDD;
    pub fn Sylvan_project(a: BDD, vars: BDD) -> BDD;
    pub fn Sylvan_and_exists(a: BDD, b: BDD, vars: BDDSET) -> BDD;
    pub fn Sylvan_and_project(a: BDD, b: BDD, vars: BDDSET) -> BDD;
    pub fn Sylvan_relprev(a: BDD, b: BDD, vars: BDDSET) -> BDD;
    pub fn Sylvan_relnext(a: BDD, b: BDD, vars: BDDSET) -> BDD;
    pub fn Sylvan_closure(a: BDD) -> BDD;
    pub fn Sylvan_constrain(f: BDD, c: BDD) -> BDD;
    pub fn Sylvan_restrict(f: BDD, c: BDD) -> BDD;
    pub fn Sylvan_compose(f: BDD, m: BDDMAP) -> BDD;
    pub fn Sylvan_satcount(bdd: BDD, variables: BDDSET) -> c_double;
    pub fn Sylvan_cube(variables: BDDSET, cube: *mut u8) -> BDD;
    pub fn Sylvan_union_cube(bdd: BDD, variables: BDDSET, cube: *mut u8) -> BDD;
    pub fn Sylvan_sat_one(bdd: BDD, variables: BDDSET, str: *mut u8) -> c_int;
    pub fn Sylvan_sat_one_bdd(bdd: BDD) -> BDD;
    pub fn Sylvan_pick_cube(bdd: BDD) -> BDD;
    pub fn Sylvan_sat_single(bdd: BDD, vars: BDDSET) -> BDD;
    pub fn Sylvan_pick_single_cube(bdd: BDD, vars: BDDSET) -> BDD;
    pub fn Sylvan_enum(bdd: BDD, vars: BDDSET, cb: ENUM_CB, context: *mut c_void) -> c_void;
    pub fn Sylvan_enum_par(bdd: BDD, vars: BDDSET, cb: ENUM_CB, context: *mut c_void) -> c_void;
    pub fn Sylvan_collect(bdd: BDD, vars: BDDSET, cb: COLLECT_CB, context: *mut c_void) -> BDD;
    pub fn Sylvan_pathcount(bdd: BDD) -> c_double;
    pub fn Sylvan_serialize_add(bdd: BDD) -> size_t;
    pub fn Sylvan_serialize_get(bdd: BDD) -> size_t;
    pub fn Sylvan_serialize_get_reversed(value: size_t) -> BDD;
    pub fn Sylvan_serialize_reset() -> c_void;
    pub fn Sylvan_serialize_totext(out: *mut FILE) -> c_void;
    pub fn Sylvan_serialize_tofile(out: *mut FILE) -> c_void;
    pub fn Sylvan_serialize_fromfile(input: *mut FILE) -> c_void;
    pub fn Sylvan_fprint(f: *mut FILE, bdd: BDD) -> c_void;
    pub fn Sylvan_print(bdd: BDD) -> c_void;

}
