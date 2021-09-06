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

/*
    sylvan_ldd.h wrapper:
 */

void Sylvan_init_ldd(void) {
    sylvan_init_ldd();
}

MDD Sylvan_lddmc_makenode(uint32_t value, MDD ifeq, MDD ifneq) {
    return lddmc_makenode(value, ifeq, ifneq);
}

MDD Sylvan_lddmc_extendnode(MDD mdd, uint32_t value, MDD ifeq) {
    return lddmc_extendnode(mdd, value, ifeq);
}

uint32_t Sylvan_lddmc_getvalue(MDD mdd) {
    return lddmc_getvalue(mdd);
}

MDD Sylvan_lddmc_getdown(MDD mdd) {
    return lddmc_getdown(mdd);
}

MDD Sylvan_lddmc_getright(MDD mdd) {
    return lddmc_getright(mdd);
}

MDD Sylvan_lddmc_follow(MDD mdd, uint32_t value) {
    return lddmc_follow(mdd, value);
}

MDD Sylvan_lddmc_make_copynode(MDD ifeq, MDD ifneq) {
    return lddmc_make_copynode(ifeq, ifneq);
}

int Sylvan_lddmc_iscopy(MDD mdd) {
    return lddmc_iscopy(mdd);
}

MDD Sylvan_lddmc_followcopy(MDD mdd) {
    return lddmc_followcopy(mdd);
}

void Sylvan_lddmc_protect(MDD* ptr) {
    lddmc_protect(ptr);
}

void Sylvan_lddmc_unprotect(MDD* ptr) {
    lddmc_unprotect(ptr);
}

size_t Sylvan_lddmc_count_protected(void) {
    return lddmc_count_protected();
}

MDD Sylvan_lddmc_ref(MDD dd) {
    return lddmc_ref(dd);
}

void Sylvan_lddmc_deref(MDD dd) {
    lddmc_deref(dd);
}

size_t Sylvan_lddmc_count_refs(void) {
    return lddmc_count_refs();
}

void Sylvan_lddmc_gc_mark_rec(MDD mdd) {
    lddmc_gc_mark_rec(mdd);
}

MDD Sylvan_lddmc_union(MDD a, MDD b) {
    return lddmc_union(a, b);
}

MDD Sylvan_lddmc_minus(MDD a, MDD b) {
    return lddmc_minus(a, b);
}

MDD Sylvan_lddmc_zip(MDD a, MDD b, MDD *res) {
    return lddmc_zip(a, b, res);
}

MDD Sylvan_lddmc_intersect(MDD a, MDD b) {
    return lddmc_intersect(a, b);
}

MDD Sylvan_lddmc_match(MDD a, MDD b, MDD proj) {
    return lddmc_match(a, b, proj);
}

MDD Sylvan_lddmc_union_cube(MDD a, uint32_t* values, size_t count) {
    return lddmc_union_cube(a, values, count);
}

int Sylvan_lddmc_member_cube(MDD a, uint32_t* values, size_t count) {
    return lddmc_member_cube(a, values, count);
}

MDD Sylvan_lddmc_cube(uint32_t* values, size_t count) {
    return lddmc_cube(values, count);
}

MDD Sylvan_lddmc_union_cube_copy(MDD a, uint32_t* values, int* copy, size_t count) {
    return lddmc_union_cube_copy(a, values, copy, count);
}

int Sylvan_lddmc_member_cube_copy(MDD a, uint32_t* values, int* copy, size_t count) {
    return lddmc_member_cube_copy(a, values, copy, count);
}

MDD Sylvan_lddmc_cube_copy(uint32_t* values, int* copy, size_t count) {
    return lddmc_cube_copy(values, copy, count);
}

MDD Sylvan_lddmc_relprod(MDD a, MDD b, MDD proj) {
    return lddmc_relprod(a, b, proj);
}

MDD Sylvan_lddmc_relprod_union(MDD a, MDD b, MDD meta, MDD un) {
    return lddmc_relprod_union(a, b, meta, un);
}

MDD Sylvan_lddmc_relprev(MDD a, MDD rel, MDD proj, MDD uni) {
    return lddmc_relprev(a, rel, proj, uni);
}

MDD Sylvan_lddmc_project(MDD mdd, MDD proj) {
    return lddmc_project(mdd, proj);
}

MDD Sylvan_lddmc_project_minus(MDD mdd, MDD proj, MDD avoid) {
    return lddmc_project_minus(mdd, proj, avoid);
}

MDD Sylvan_lddmc_join(MDD a, MDD b, MDD a_proj, MDD b_proj) {
    return lddmc_join(a, b, a_proj, b_proj);
}

void Sylvan_lddmc_printdot(MDD mdd) {
    lddmc_printdot(mdd);
}

void Sylvan_lddmc_fprintdot(FILE *out, MDD mdd) {
    lddmc_fprintdot(out, mdd);
}

void Sylvan_lddmc_fprint(FILE *out, MDD mdd) {
    lddmc_fprint(out, mdd);
}

void Sylvan_lddmc_print(MDD mdd) {
    lddmc_print(mdd);
}

void Sylvan_lddmc_printsha(MDD mdd) {
    lddmc_printsha(mdd);
}

void Sylvan_lddmc_fprintsha(FILE *out, MDD mdd) {
    lddmc_fprintsha(out, mdd);
}

void Sylvan_lddmc_getsha(MDD mdd, char *target) {
    lddmc_getsha(mdd, target);
}

lddmc_satcount_double_t Sylvan_lddmc_satcount_cached(MDD mdd) {
    return lddmc_satcount_cached(mdd);
}

long double Sylvan_lddmc_satcount(MDD mdd) {
    return lddmc_satcount(mdd);
}

// void (*lddmc_enum_cb)(uint32_t*, size_t, void*)
// MDD (*lddmc_collect_cb)(uint32_t*, size_t, void*)
void Sylvan_lddmc_sat_all_par(MDD mdd, lddmc_enum_cb cb, void *context) {
    lddmc_sat_all_par(mdd, cb, context);
}

void Sylvan_lddmc_sat_all_nopar(MDD mdd, lddmc_enum_cb cb, void *context) {
    lddmc_sat_all_nopar(mdd, cb, context);
}

MDD Sylvan_lddmc_collect(MDD md, lddmc_collect_cb cb, void *context) {
    return lddmc_collect(md, cb, context);
}

void Sylvan_lddmc_match_sat_par(MDD mdd, MDD match, MDD proj, lddmc_enum_cb cb, void *context) {
    return lddmc_match_sat_par(mdd, match, proj, cb, context);
}

int Sylvan_lddmc_sat_one(MDD mdd, uint32_t *values, size_t count) {
    return lddmc_sat_one(mdd, values, count);
}

MDD Sylvan_lddmc_sat_one_mdd(MDD mdd) {
    return lddmc_sat_one_mdd(mdd);
}

MDD Sylvan_lddmc_pick_cube(MDD mdd) {
    return lddmc_pick_cube(mdd);
}

// int (*lddmc_visit_pre_cb)(MDD, void* context)
// int (*lddmc_visit_post_cb)(MDD, void* context)
// int (*lddmc_visit_init_context_cb)(void* context, void* parent, int is_down)
void Sylvan_lddmc_visit_par(MDD mdd, lddmc_visit_callbacks_t *cbs, size_t ctx_size, void *context) {
    lddmc_visit_par(mdd, cbs, ctx_size, context);
}

void Sylvan_lddmc_visit_seq(MDD mdd, lddmc_visit_callbacks_t *cbs, size_t ctx_size, void *context) {
    lddmc_visit_seq(mdd, cbs, ctx_size, context);
}

size_t Sylvan_lddmc_nodecount(MDD mdd) {
    return lddmc_nodecount(mdd);
}

void Sylvan_lddmc_nodecount_levels(MDD mdd, size_t *variables) {
    lddmc_nodecount_levels(mdd, variables);
}

// callback type: MDD (*lddmc_compose_cb)(MDD, void*)
MDD Sylvan_lddmc_compose(MDD mdd, lddmc_compose_cb cb, void *context, int depth) {
    return lddmc_compose(mdd, cb, context, depth);
}

size_t Sylvan_lddmc_serialize_add(MDD mdd) {
    return lddmc_serialize_add(mdd);
}

size_t Sylvan_lddmc_serialize_get(MDD mdd) {
    return lddmc_serialize_get(mdd);
}

MDD Sylvan_lddmc_serialize_get_reversed(size_t value) {
    return lddmc_serialize_get_reversed(value);
}

void Sylvan_lddmc_serialize_reset(void) {
    lddmc_serialize_reset();
}

void Sylvan_lddmc_serialize_totext(FILE *out) {
    lddmc_serialize_totext(out);
}

void Sylvan_lddmc_serialize_tofile(FILE *out) {
    lddmc_serialize_tofile(out);
}

void Sylvan_lddmc_serialize_fromfile(FILE *in) {
    lddmc_serialize_fromfile(in);
}

void Sylvan_lddmc_refs_pushptr(const MDD *ptr) {
    lddmc_refs_pushptr(ptr);
}

void Sylvan_lddmc_refs_popptr(size_t amount) {
    lddmc_refs_popptr(amount);
}

MDD Sylvan_lddmc_refs_push(MDD dd) {
    return lddmc_refs_push(dd);
}

void Sylvan_lddmc_refs_pop(long amount) {
    lddmc_refs_pop(amount);
}

void Sylvan_lddmc_refs_spawn(Task *t) {
    lddmc_refs_spawn(t);
}

MDD Sylvan_lddmc_refs_sync(MDD dd) {
    lddmc_refs_sync(dd);
}