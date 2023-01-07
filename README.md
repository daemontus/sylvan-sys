[![Crates.io](https://img.shields.io/crates/v/sylvan-sys?style=flat-square)](https://crates.io/crates/sylvan-sys)
[![Api Docs](https://img.shields.io/badge/docs-api-yellowgreen?style=flat-square)](https://docs.rs/sylvan-sys/)
[![Continuous integration](https://img.shields.io/github/actions/workflow/status/daemontus/sylvan-sys/build.yml?branch=master&style=flat-square)](https://github.com/daemontus/sylvan-sys/actions?query=workflow%3Abuild)

# Rust Bindings for the Sylvan library

This crate provides unsafe Rust bindings for the parallel multi-terminal 
binary decision diagram library Sylvan. At the moment, the bindings are based on version `1.7.1` available [on Github](https://github.com/trolando/sylvan). The crate compiles on Linux and MacOS, and if you can build `sylvan` with Visual Studio, it should work on Windows as well (the problem is mostly correctly linking the `gmp` library).

> Keep in mind that you will need `cmake` and `gmp` (arbitrary precision numbers) to build Sylvan. Hopefully `gmp` will be soon optional, but for now it is necessary.

Since a lot of Sylvan's functionality is defined using preprocessor macros, there is a small wrapper library (`./wrapper/src`) which exports each macro as a function (this can incur a small performance penalty which should be mostly mitigated by enabling link time optimizations). The wrapper also prefixes each function/macro with `Sylvan_` so that they are clearly marked as part of Sylvan API. For documentation, see the original source code and [tutorial](https://trolando.github.io/sylvan/).

```rust
unsafe fn main() {
    Lace_start(0, 0); // auto-detect thread count
    
    // 2MB memory limit should be enough for a small test:
    Sylvan_set_limits(1 << 21, 1, 5);
    Sylvan_init_package();
    Sylvan_init_bdd();
    Sylvan_gc_disable();
    Sylvan_register_quit(termination_handler);

    // Check that the basic identity (a & b) <=> !(!a | !b) holds.
    let a = Sylvan_ithvar(1);
    let b = Sylvan_ithvar(2);

    let not_a = Sylvan_mtbdd_not(a);
    let not_b = Sylvan_mtbdd_not(b);

    let a_and_b = Sylvan_mtbdd_times(a, b);
    let not_a_or_b = Sylvan_mtbdd_not(Sylvan_mtbdd_plus(not_a, not_b));

    // The BDD has three nodes:
    assert_eq!(3, Sylvan_nodecount(a_and_b));
    // And the identity holds:
    assert_eq!(a_and_b, not_a_or_b);

    Sylvan_quit();
    Lace_stop();
}
```

A slightly more involved example is also available in the `test.rs` module.

**Completeness:** Most of the API should be fully reproduced here (including 
stuff like functions with callbacks). Some minor aspects (like the 
`sylvan_stats` struct or more advanced lace functionality) are missing, but 
if you need them, you can create an issues, and they can be added later. 
**Since `1.7.0`, Sylvan also includes an implementation of ZDDs. For now, 
this is not included in this wrapper, but feel free to make a PR :)

**Correctness:** Unfortunately, Sylvan cannot be directly processed using `bindgen`, so the API was reproduced using a semi-automated method with a manual validation step (bunch of regexes that a human makes sure didn't break anything ;)). As such, it is possible that there are some minor problems that need to be sorted out. Please file an issue if you see any unexpected behaviour or segfaults.
