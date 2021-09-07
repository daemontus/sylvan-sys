[![Crates.io](https://img.shields.io/crates/v/sylvan-sys?style=flat-square)](https://crates.io/crates/sylvan-sys)
[![Api Docs](https://img.shields.io/badge/docs-api-yellowgreen?style=flat-square)](https://docs.rs/sylvan-sys/)
[![Continuous integration](https://img.shields.io/github/workflow/status/daemontus/sylvan-sys/build?style=flat-square)](https://github.com/daemontus/sylvan-sys/actions?query=workflow%3Abuild)

# Rust Bindings for the Sylvan library

This crate provides unsafe Rust bindings for the parallel multi-terminal binary decision diagram library Sylvan. At the moment, the bindings are based on version `1.6.1` available [on Github](https://github.com/trolando/sylvan). The crate compiles on Linux and MacOS, and if you can build `sylvan` with Visual Studio, it should work on Windows as well (the problem is mostly correctly linking the `gmp` library).

> Keep in mind that you will need `cmake` and `gmp` (arbitrary precision numbers) to build Sylvan. Hopefully `gmp` will be soon optional, but for now it is necessary.

Since a lot of Sylvan's functionality is defined using preprocessor macros, there is a small wrapper library (`./wrapper/src`) which exports each macro as a function (this can incur a small performance penalty which should be mostly mitigated by enabling link time optimizations). The wrapper also prefixes each function/macro with `Sylvan_` so that they are clearly marked as part of Sylvan API. For documentation, see the original source code and [tutorial](https://trolando.github.io/sylvan/).  

**Completeness:** Most of the API should be fully reproduced here (including stuff like functions with callbacks). Some minor aspects (like the `sylvan_stats` struct or more advanced lace functionality) are missing, but if you need them, you can create an issues, and they can be added later.

**Correctness:** Unfortunately, Sylvan cannot be directly processed using `bindgen`, so the API was reproduced using a semi-automated method with a manual validation step (bunch of regexes that a human makes sure didn't break anything ;)). As such, it is possible that there are some minor problems that need to be sorted out. Please file an issue if you see any unexpected behaviour or segfaults.
