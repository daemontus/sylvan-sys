#include <sylvan.h>
#include <sylvan-wrapper.h>

/*
    sylvan_common.h wrapper:
 */

void Sylvan_init_package(void) {
    sylvan_init_package();
}

void Sylvan_set_sizes(size_t min_tablesize, size_t max_tablesize, size_t min_cachesize, size_t max_cachesize) {
    sylvan_set_sizes(min_tablesize, max_tablesize, min_cachesize, max_cachesize);
}

void Sylvan_set_limits(size_t memory_cap, int table_ratio, int initial_ratio) {
    sylvan_set_limits(memory_cap, table_ratio, initial_ratio);
}

void Sylvan_quit(void) {
    sylvan_quit();
}

void Sylvan_register_quit(quit_cb cb) {
    sylvan_register_quit(cb);
}

void Sylvan_table_usage(size_t *filled, size_t *total) {
    sylvan_table_usage(filled, total);
}

void Sylvan_gc() {
    sylvan_gc();
}

void Sylvan_gc_enable(void) {
    sylvan_gc_enable();
}

void Sylvan_gc_disable(void) {
    sylvan_gc_disable();
}

//void Sylvan_gc_test()

void Sylvan_clear_cache() {
    sylvan_clear_cache();
}

void Sylvan_clear_and_mark() {
    sylvan_clear_and_mark();
}

void Sylvan_rehash_all() {
    sylvan_rehash_all();
}

void Sylvan_gc_hook_pregc(gc_hook_cb callback) {
    sylvan_gc_hook_pregc(callback);
}

void Sylvan_gc_hook_postgc(gc_hook_cb callback) {
    sylvan_gc_hook_postgc(callback);
}

void Sylvan_gc_hook_main(gc_hook_cb callback) {
    sylvan_gc_hook_main(callback);
}

void Sylvan_gc_add_mark(gc_hook_cb mark_cb) {
    sylvan_gc_add_mark(mark_cb);
}

/*
    sylvan_stats.h wrapper:
 */

void Sylvan_stats_init() {
    sylvan_stats_init();
}

void Sylvan_stats_reset() {
    sylvan_stats_reset();
}

void Sylvan_stats_snapshot(sylvan_stats_t *target) {
    sylvan_stats_snapshot(target);
}

void Sylvan_stats_report(FILE* target) {
    sylvan_stats_report(target);
}

/*
    sylvan_mt.h wrapper:
 */

void Sylvan_init_mt(void) {
    sylvan_init_mt();
}

uint32_t Sylvan_mt_create_type(void) {
    return sylvan_mt_create_type();
}

void Sylvan_mt_set_hash(uint32_t type, sylvan_mt_hash_cb hash_cb) {
    sylvan_mt_set_hash(type, hash_cb);
}

void Sylvan_mt_set_equals(uint32_t type, sylvan_mt_equals_cb equals_cb) {
    sylvan_mt_set_equals(type, equals_cb);
}

void Sylvan_mt_set_create(uint32_t type, sylvan_mt_create_cb create_cb) {
    sylvan_mt_set_create(type, create_cb);
}

void Sylvan_mt_set_destroy(uint32_t type, sylvan_mt_destroy_cb destroy_cb) {
    sylvan_mt_set_destroy(type, destroy_cb);
}

void Sylvan_mt_set_to_str(uint32_t type, sylvan_mt_to_str_cb to_str_cb) {
    sylvan_mt_set_to_str(type, to_str_cb);
}

void Sylvan_mt_set_write_binary(uint32_t type, sylvan_mt_write_binary_cb write_binary_cb) {
    sylvan_mt_set_write_binary(type, write_binary_cb);
}

void Sylvan_mt_set_read_binary(uint32_t type, sylvan_mt_read_binary_cb read_binary_cb) {
    Sylvan_mt_set_read_binary(type, read_binary_cb);
}

int Sylvan_mt_has_custom_hash(uint32_t type) {
    sylvan_mt_has_custom_hash(type);
}

uint64_t Sylvan_mt_hash(uint32_t type, uint64_t value, uint64_t seed) {
    return sylvan_mt_hash(type, value, seed);
}

char *Sylvan_mt_to_str(int complement, uint32_t type, uint64_t value, char *buf, size_t buflen) {
    return sylvan_mt_to_str(complement, type, value, buf, buflen);
}

int Sylvan_mt_write_binary(uint32_t type, uint64_t value, FILE *out) {
    return sylvan_mt_write_binary(type, value, out);
}

int Sylvan_mt_read_binary(uint32_t type, uint64_t *value, FILE *in) {
    return sylvan_mt_read_binary(type, value, in);
}

/*
    sylvan_bdd.h wrapper:
 */

int Sylvan_isconst(MTBDD bdd) {
    return sylvan_isconst(bdd);
}

int Sylvan_isnode(MTBDD bdd) {
    return sylvan_isnode(bdd);
}

void Sylvan_set_granularity(int granularity) {
    sylvan_set_granularity(granularity);
}

int Sylvan_get_granularity(void) {
    return sylvan_get_granularity();
}

BDD Sylvan_not(BDD a) {
    return sylvan_not(a);
}

BDD Sylvan_ite(BDD a, BDD b, BDD c) {
    return sylvan_ite(a, b, c);
}

BDD Sylvan_and(BDD a, BDD b) {
    return sylvan_and(a, b);
}

BDD Sylvan_xor(BDD a, BDD b) {
    return sylvan_xor(a, b);
}

BDD Sylvan_equiv(BDD a, BDD b) {
    return sylvan_equiv(a, b);
}

BDD Sylvan_or(BDD a, BDD b) {
    return sylvan_or(a, b);
}

BDD Sylvan_nand(BDD a, BDD b) {
    return sylvan_nand(a, b);
}

BDD Sylvan_nor(BDD a, BDD b) {
    return sylvan_nor(a, b);
}

BDD Sylvan_imp(BDD a, BDD b) {
    return sylvan_imp(a, b);
}

BDD Sylvan_invimp(BDD a, BDD b) {
    return sylvan_invimp(a, b);
}

BDD Sylvan_biimp(BDD a, BDD b) {
    return sylvan_biimp(a, b);
}

BDD Sylvan_diff(BDD a, BDD b) {
    return sylvan_diff(a, b);
}

BDD Sylvan_less(BDD a, BDD b) {
    return sylvan_less(a, b);
}

BDD Sylvan_nithvar(uint32_t var) {
    return sylvan_nithvar(var);
}

BDD Sylvan_exists(BDD a, BDD vars) {
    return sylvan_exists(a, vars);
}

BDD Sylvan_forall(BDD a, BDD vars) {
    return sylvan_forall(a, vars);
}

BDD Sylvan_project(BDD a, BDD vars) {
    return sylvan_project(a, vars);
}

BDD Sylvan_and_exists(BDD a, BDD b, BDDSET vars) {
    return sylvan_and_exists(a, b, vars);
}

BDD Sylvan_and_project(BDD a, BDD b, BDDSET vars) {
    return sylvan_and_project(a, b, vars);
}

BDD Sylvan_relprev(BDD a, BDD b, BDDSET vars) {
    return sylvan_relprev(a, b, vars);
}

BDD Sylvan_relnext(BDD a, BDD b, BDDSET vars) {
    return sylvan_relnext(a, b, vars);
}

BDD Sylvan_closure(BDD a) {
    return sylvan_closure(a);
}

BDD Sylvan_constrain(BDD f, BDD c) {
    return sylvan_constrain(f, c);
}

BDD Sylvan_restrict(BDD f, BDD c) {
    return sylvan_restrict(f, c);
}

BDD Sylvan_compose(BDD f, BDDMAP m) {
    return sylvan_compose(f, m);
}

double Sylvan_satcount(BDD bdd, BDDSET variables) {
    return sylvan_satcount(bdd, variables);
}

BDD Sylvan_cube(BDDSET variables, uint8_t *cube) {
    return sylvan_cube(variables, cube);
}

BDD Sylvan_union_cube(BDD bdd, BDDSET variables, uint8_t* cube) {
    return sylvan_union_cube(bdd, variables, cube);
}

int Sylvan_sat_one(BDD bdd, BDDSET variables, uint8_t* str) {
    return sylvan_sat_one(bdd, variables, str);
}

BDD Sylvan_sat_one_bdd(BDD bdd) {
    return sylvan_sat_one_bdd(bdd);
}

BDD Sylvan_pick_cube(BDD bdd) {
    return sylvan_pick_cube(bdd);
}

BDD Sylvan_sat_single(BDD bdd, BDDSET vars) {
    return sylvan_sat_single(bdd, vars);
}

BDD Sylvan_pick_single_cube(BDD bdd, BDDSET vars) {
    return sylvan_pick_single_cube(bdd, vars);
}

void Sylvan_enum(BDD bdd, BDDSET vars, enum_cb cb, void* context) {
    sylvan_enum(bdd, vars, cb, context);
}

void Sylvan_enum_par(BDD bdd, BDDSET vars, enum_cb cb, void* context) {
    sylvan_enum_par(bdd, vars, cb, context);
}

BDD Sylvan_collect(BDD bdd, BDDSET vars, sylvan_collect_cb cb, void* context) {
    return sylvan_collect(bdd, vars, cb, context);
}

double Sylvan_pathcount(BDD bdd) {
    return sylvan_pathcount(bdd);
}

size_t Sylvan_serialize_add(BDD bdd) {
    return sylvan_serialize_add(bdd);
}

size_t Sylvan_serialize_get(BDD bdd) {
    return sylvan_serialize_get(bdd);
}

BDD Sylvan_serialize_get_reversed(size_t value) {
    return sylvan_serialize_get_reversed(value);
}

void Sylvan_serialize_reset(void) {
    sylvan_serialize_reset();
}

void Sylvan_serialize_totext(FILE *out) {
    sylvan_serialize_totext(out);
}

void Sylvan_serialize_tofile(FILE *out) {
    sylvan_serialize_tofile(out);
}

void Sylvan_serialize_fromfile(FILE *in) {
    sylvan_serialize_fromfile(in);
}

void Sylvan_fprint(FILE *f, BDD bdd) {
    sylvan_fprint(f, bdd);
}

void Sylvan_print(BDD bdd) {
    sylvan_print(bdd);
}