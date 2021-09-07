//! This crate provides unsafe Rust bindings for the parallel multi-terminal binary decision
//! diagram library Sylvan. At the moment, the bindings are based on version `1.6.1` available
//! [on Github](https://github.com/trolando/sylvan). The crate compiles on Linux and MacOS, and
//! if you can build `sylvan` with Visual Studio, it should work on Windows as well (the problem
//! is mostly correctly linking the `gmp` library).
//!
//! > Keep in mind that you will need `cmake` and `gmp` (arbitrary precision numbers) to build
//! Sylvan. Hopefully `gmp` will be soon optional, but for now it is necessary.
//!
//! Since a lot of Sylvan's functionality is defined using preprocessor macros, there is a small
//! wrapper library (`./wrapper/src`) which exports each macro as a function (this can incur
//! a small performance penalty which should be mostly mitigated by enabling link time
//! optimizations). The wrapper also prefixes each function/macro with `Sylvan_` so that they are
//! clearly marked as part of Sylvan API. For documentation, see the original source
//! code and [tutorial](https://trolando.github.io/sylvan/).
//!
//! **Completeness:** Most of the API should be fully reproduced here (including stuff like
//! functions with callbacks). Some minor aspects (like the `sylvan_stats` struct or more advanced
//! lace functionality) are missing, but if you need them, you can create an issues, and they can
//! be added later.
//!
//! **Correctness:** Unfortunately, Sylvan cannot be directly processed using `bindgen`, so the API
//! was reproduced using a semi-automated method with a manual validation step (bunch of regexes
//! that a human makes sure didn't break anything ;)). As such, it is possible that there are some
//! minor problems that need to be sorted out. Please file an issue if you see any unexpected
//! behaviour or segfaults.

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
