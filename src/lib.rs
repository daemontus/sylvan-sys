// Allow non-idiomatic names in the whole crate.
#![allow(non_camel_case_types)]
#![allow(non_snake_case)]
extern crate libc;

/// Wraps the `sylvan_bdd.h` declarations.
pub mod bdd;
/// Wraps the `sylvan_common.h` declarations.
pub mod common;
/// Wrapper for the essential parts of the `lace.h` interface.
pub mod lace;
/// Wraps the `sylvan_ldd.h` declarations.
pub mod ldd;
/// Wraps the `sylvan_mt.h` declarations.
pub mod mt;
/// Wraps the `sylvan_mtbdd.h` declarations.
pub mod mtbdd;
/// Wraps the `sylvan_stats.h` declarations.
pub mod stats;

#[cfg(test)]
mod test;

pub type MDD = u64;
pub type MTBDD = u64;
pub type BDDVAR = u32;

pub type MTBDDMAP = MTBDD;
pub type BDD = MTBDD;
pub type BDDMAP = MTBDD;
pub type BDDSET = MTBDD;

pub const MTBDD_COMPLEMENT: MTBDD = 0x8000000000000000;
pub const MTBDD_FALSE: MTBDD = 0;
pub const MTBDD_TRUE: MTBDD = 0x8000000000000000;
pub const MTBDD_INVALID: MTBDD = 0xffffffffffffffff;

pub const SYLVAN_COMPLEMENT: MTBDD = MTBDD_COMPLEMENT;
pub const SYLVAN_FALSE: MTBDD = MTBDD_FALSE;
pub const SYLVAN_TRUE: MTBDD = MTBDD_TRUE;
pub const SYLVAN_INVALID: MTBDD = MTBDD_INVALID;
