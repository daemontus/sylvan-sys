#ifndef SYLVAN_WRAPPER_H
#define SYLVAN_WRAPPER_H

/*
    Since half of sylvan is implemented in C macros, a decision was made to create
    a wrapper file which will re-export everything in sylvan header files, but
    using a function-based API so that everything is visible through the FFI layer.

    Also, we generally do not re-export types as these can be (relatively) easily
    recovered from sylvan header files.
*/

// sylvan_common.h wrapper:
void Sylvan_init_package(void);
void Sylvan_set_sizes(size_t min_tablesize, size_t max_tablesize, size_t min_cachesize, size_t max_cachesize);
void Sylvan_set_limits(size_t memory_cap, int table_ratio, int initial_ratio);
void Sylvan_quit(void);
void Sylvan_register_quit(quit_cb cb);
void Sylvan_table_usage(size_t *filled, size_t *total);
void Sylvan_gc();
void Sylvan_gc_enable(void);
void Sylvan_gc_disable(void);
//void Sylvan_gc_test();    Can only happen *inside* a Lace task.
void Sylvan_clear_cache();
void Sylvan_clear_and_mark();
void Sylvan_rehash_all();
// Expanded macro hint for convenience:
// typedef void (*GC_HOOK_CB)(WorkerP *, Task *);
void Sylvan_gc_hook_pregc(gc_hook_cb callback);
void Sylvan_gc_hook_postgc(gc_hook_cb callback);
void Sylvan_gc_hook_main(gc_hook_cb callback);
void Sylvan_gc_add_mark(gc_hook_cb mark_cb);

// sylvan_stats.h wrapper:

void Sylvan_stats_init();
void Sylvan_stats_reset();
void Sylvan_stats_snapshot(sylvan_stats_t *target);
void Sylvan_stats_report(FILE* target);

// sylvan_mt.h wrapper:

void Sylvan_init_mt(void);
uint32_t Sylvan_mt_create_type(void);
void Sylvan_mt_set_hash(uint32_t type, sylvan_mt_hash_cb hash_cb);
void Sylvan_mt_set_equals(uint32_t type, sylvan_mt_equals_cb equals_cb);
void Sylvan_mt_set_create(uint32_t type, sylvan_mt_create_cb create_cb);
void Sylvan_mt_set_destroy(uint32_t type, sylvan_mt_destroy_cb destroy_cb);
void Sylvan_mt_set_to_str(uint32_t type, sylvan_mt_to_str_cb to_str_cb);
void Sylvan_mt_set_write_binary(uint32_t type, sylvan_mt_write_binary_cb write_binary_cb);
void Sylvan_mt_set_read_binary(uint32_t type, sylvan_mt_read_binary_cb read_binary_cb);
int Sylvan_mt_has_custom_hash(uint32_t type);
uint64_t Sylvan_mt_hash(uint32_t type, uint64_t value, uint64_t seed);
char *Sylvan_mt_to_str(int complement, uint32_t type, uint64_t value, char *buf, size_t buflen);
int Sylvan_mt_write_binary(uint32_t type, uint64_t value, FILE *out);
int Sylvan_mt_read_binary(uint32_t type, uint64_t *value, FILE *in);

// sylvan_bdd.h wrapper:

int Sylvan_isconst(MTBDD bdd);
int Sylvan_isnode(MTBDD bdd);
void Sylvan_set_granularity(int granularity);
int Sylvan_get_granularity(void);
BDD Sylvan_not(BDD a);
BDD Sylvan_ite(BDD a, BDD b, BDD c);
BDD Sylvan_and(BDD a, BDD b);
BDD Sylvan_xor(BDD a, BDD b);
BDD Sylvan_equiv(BDD a, BDD b);
BDD Sylvan_or(BDD a, BDD b);
BDD Sylvan_nand(BDD a, BDD b);
BDD Sylvan_nor(BDD a, BDD b);
BDD Sylvan_imp(BDD a, BDD b);
BDD Sylvan_invimp(BDD a, BDD b);
BDD Sylvan_biimp(BDD a, BDD b);
BDD Sylvan_diff(BDD a, BDD b);
BDD Sylvan_less(BDD a, BDD b);
BDD Sylvan_nithvar(uint32_t var);
BDD Sylvan_exists(BDD a, BDD vars);
BDD Sylvan_forall(BDD a, BDD vars);
BDD Sylvan_project(BDD a, BDD vars);
BDD Sylvan_and_exists(BDD a, BDD b, BDDSET vars);
BDD Sylvan_and_project(BDD a, BDD b, BDDSET vars);
BDD Sylvan_relprev(BDD a, BDD b, BDDSET vars);
BDD Sylvan_relnext(BDD a, BDD b, BDDSET vars);
BDD Sylvan_closure(BDD a);
BDD Sylvan_constrain(BDD f, BDD c);
BDD Sylvan_restrict(BDD f, BDD c);
BDD Sylvan_compose(BDD f, BDDMAP m);
double Sylvan_satcount(BDD bdd, BDDSET variables);
BDD Sylvan_cube(BDDSET variables, uint8_t *cube);
BDD Sylvan_union_cube(BDD bdd, BDDSET variables, uint8_t* cube);
int Sylvan_sat_one(BDD bdd, BDDSET variables, uint8_t* str);
BDD Sylvan_sat_one_bdd(BDD bdd);
BDD Sylvan_pick_cube(BDD bdd);
BDD Sylvan_sat_single(BDD bdd, BDDSET vars);
BDD Sylvan_pick_single_cube(BDD bdd, BDDSET vars);
void Sylvan_enum(BDD bdd, BDDSET vars, enum_cb cb, void* context);
void Sylvan_enum_par(BDD bdd, BDDSET vars, enum_cb cb, void* context);
BDD Sylvan_collect(BDD bdd, BDDSET vars, sylvan_collect_cb cb, void* context);
double Sylvan_pathcount(BDD bdd);
size_t Sylvan_serialize_add(BDD bdd);
size_t Sylvan_serialize_get(BDD bdd);
BDD Sylvan_serialize_get_reversed(size_t value);
void Sylvan_serialize_reset(void);
void Sylvan_serialize_totext(FILE *out);
void Sylvan_serialize_tofile(FILE *out);
void Sylvan_serialize_fromfile(FILE *in);
void Sylvan_fprint(FILE *f, BDD bdd);
void Sylvan_print(BDD bdd);

#endif