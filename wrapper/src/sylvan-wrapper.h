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

// sylvan_ldd.h wrapper:

void Sylvan_init_ldd(void);
MDD Sylvan_lddmc_makenode(uint32_t value, MDD ifeq, MDD ifneq);
MDD Sylvan_lddmc_extendnode(MDD mdd, uint32_t value, MDD ifeq);
uint32_t Sylvan_lddmc_getvalue(MDD mdd);
MDD Sylvan_lddmc_getdown(MDD mdd);
MDD Sylvan_lddmc_getright(MDD mdd);
MDD Sylvan_lddmc_follow(MDD mdd, uint32_t value);
MDD Sylvan_lddmc_make_copynode(MDD ifeq, MDD ifneq);
int Sylvan_lddmc_iscopy(MDD mdd);
MDD Sylvan_lddmc_followcopy(MDD mdd);
void Sylvan_lddmc_protect(MDD* ptr);
void Sylvan_lddmc_unprotect(MDD* ptr);
size_t Sylvan_lddmc_count_protected(void);
MDD Sylvan_lddmc_ref(MDD dd);
void Sylvan_lddmc_deref(MDD dd);
size_t Sylvan_lddmc_count_refs(void);
void Sylvan_lddmc_gc_mark_rec(MDD mdd);
MDD Sylvan_lddmc_union(MDD a, MDD b);
MDD Sylvan_lddmc_minus(MDD a, MDD b);
MDD Sylvan_lddmc_zip(MDD a, MDD b, MDD *res);
MDD Sylvan_lddmc_intersect(MDD a, MDD b);
MDD Sylvan_lddmc_match(MDD a, MDD b, MDD proj);
MDD Sylvan_lddmc_union_cube(MDD a, uint32_t* values, size_t count);
int Sylvan_lddmc_member_cube(MDD a, uint32_t* values, size_t count);
MDD Sylvan_lddmc_cube(uint32_t* values, size_t count);
MDD Sylvan_lddmc_union_cube_copy(MDD a, uint32_t* values, int* copy, size_t count);
int Sylvan_lddmc_member_cube_copy(MDD a, uint32_t* values, int* copy, size_t count);
MDD Sylvan_lddmc_cube_copy(uint32_t* values, int* copy, size_t count);
MDD Sylvan_lddmc_relprod(MDD a, MDD b, MDD proj);
MDD Sylvan_lddmc_relprod_union(MDD a, MDD b, MDD meta, MDD un);
MDD Sylvan_lddmc_relprev(MDD a, MDD rel, MDD proj, MDD uni);
MDD Sylvan_lddmc_project(MDD mdd, MDD proj);
MDD Sylvan_lddmc_project_minus(MDD mdd, MDD proj, MDD avoid);
MDD Sylvan_lddmc_join(MDD a, MDD b, MDD a_proj, MDD b_proj);
void Sylvan_lddmc_printdot(MDD mdd);
void Sylvan_lddmc_fprintdot(FILE *out, MDD mdd);
void Sylvan_lddmc_fprint(FILE *out, MDD mdd);
void Sylvan_lddmc_print(MDD mdd);
void Sylvan_lddmc_printsha(MDD mdd);
void Sylvan_lddmc_fprintsha(FILE *out, MDD mdd);
void Sylvan_lddmc_getsha(MDD mdd, char *target); // at least 65 bytes...
lddmc_satcount_double_t Sylvan_lddmc_satcount_cached(MDD mdd);
long double Sylvan_lddmc_satcount(MDD mdd);
// void (*lddmc_enum_cb)(uint32_t*, size_t, void*)
// MDD (*lddmc_collect_cb)(uint32_t*, size_t, void*)
void Sylvan_lddmc_sat_all_par(MDD mdd, lddmc_enum_cb cb, void *context);
void Sylvan_lddmc_sat_all_nopar(MDD mdd, lddmc_enum_cb cb, void *context);
MDD Sylvan_lddmc_collect(MDD md, lddmc_collect_cb cb, void *context);
void Sylvan_lddmc_match_sat_par(MDD mdd, MDD match, MDD proj, lddmc_enum_cb cb, void *context);
int Sylvan_lddmc_sat_one(MDD mdd, uint32_t *values, size_t count);
MDD Sylvan_lddmc_sat_one_mdd(MDD mdd);
MDD Sylvan_lddmc_pick_cube(MDD mdd);
// int (*lddmc_visit_pre_cb)(MDD, void* context)
// int (*lddmc_visit_post_cb)(MDD, void* context)
// int (*lddmc_visit_init_context_cb)(void* context, void* parent, int is_down)
void Sylvan_lddmc_visit_par(MDD mdd, lddmc_visit_callbacks_t *cbs, size_t ctx_size, void *context);
void Sylvan_lddmc_visit_seq(MDD mdd, lddmc_visit_callbacks_t *cbs, size_t ctx_size, void *context);
size_t Sylvan_lddmc_nodecount(MDD mdd);
void Sylvan_lddmc_nodecount_levels(MDD mdd, size_t *variables);
// callback type: MDD (*lddmc_compose_cb)(MDD, void*)
MDD Sylvan_lddmc_compose(MDD mdd, lddmc_compose_cb cb, void *context, int depth);
size_t Sylvan_lddmc_serialize_add(MDD mdd);
size_t Sylvan_lddmc_serialize_get(MDD mdd);
MDD Sylvan_lddmc_serialize_get_reversed(size_t value);
void Sylvan_lddmc_serialize_reset(void);
void Sylvan_lddmc_serialize_totext(FILE *out);
void Sylvan_lddmc_serialize_tofile(FILE *out);
void Sylvan_lddmc_serialize_fromfile(FILE *in);
void Sylvan_lddmc_refs_pushptr(const MDD *ptr);
void Sylvan_lddmc_refs_popptr(size_t amount);
MDD Sylvan_lddmc_refs_push(MDD dd);
void Sylvan_lddmc_refs_pop(long amount);
void Sylvan_lddmc_refs_spawn(Task *t);
MDD Sylvan_lddmc_refs_sync(MDD dd);

#endif