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
    return sylvan_mt_has_custom_hash(type);
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
    return lddmc_refs_sync(dd);
}

/*
    sylvan_mtbdd.h wrapper:
 */

void Sylvan_init_mtbdd(void) {
    sylvan_init_mtbdd();
}

void Sylvan_init_bdd() {
    sylvan_init_bdd();
}

MTBDD Sylvan_mtbdd_makeleaf(uint32_t type, uint64_t value) {
    return mtbdd_makeleaf(type, value);
}

MTBDD Sylvan_mtbdd_makenode(uint32_t var, MTBDD low, MTBDD high) {
    return mtbdd_makenode(var, low, high);
}

MTBDD Sylvan_makenode(uint32_t var, MTBDD low, MTBDD high) {
    return sylvan_makenode(var, low, high);
}

int Sylvan_mtbdd_isleaf(MTBDD mtbdd) {
    return mtbdd_isleaf(mtbdd);
}

int Sylvan_mtbdd_isnode(MTBDD mtbdd) {
    return mtbdd_isnode(mtbdd);
}

uint32_t Sylvan_mtbdd_gettype(MTBDD leaf) {
    return mtbdd_gettype(leaf);
}

uint64_t Sylvan_mtbdd_getvalue(MTBDD leaf) {
    return mtbdd_getvalue(leaf);
}

uint32_t Sylvan_mtbdd_getvar(MTBDD node) {
    return mtbdd_getvar(node);
}

uint32_t Sylvan_var(MTBDD node) {
    return sylvan_var(node);
}

MTBDD Sylvan_mtbdd_getlow(MTBDD node) {
    return mtbdd_getlow(node);
}

MTBDD Sylvan_low(MTBDD node) {
    return sylvan_low(node);
}

MTBDD Sylvan_mtbdd_gethigh(MTBDD node) {
    return mtbdd_gethigh(node);
}

MTBDD Sylvan_high(MTBDD node) {
    return sylvan_high(node);
}

int Sylvan_mtbdd_hascomp(MTBDD dd) {
    return mtbdd_hascomp(dd);
}

MTBDD Sylvan_mtbdd_comp(MTBDD dd) {
    return mtbdd_comp(dd);
}

MTBDD Sylvan_mtbdd_not(MTBDD dd) {
    return mtbdd_not(dd);
}

MTBDD Sylvan_mtbdd_int64(int64_t value) {
    return mtbdd_int64(value);
}

MTBDD Sylvan_mtbdd_double(double value) {
    return mtbdd_double(value);
}

MTBDD Sylvan_mtbdd_fraction(int64_t numer, uint64_t denom) {
    return mtbdd_fraction(numer, denom);
}

int64_t Sylvan_mtbdd_getint64(MTBDD terminal) {
    return mtbdd_getint64(terminal);
}

double Sylvan_mtbdd_getdouble(MTBDD terminal) {
    return mtbdd_getdouble(terminal);
}

int32_t Sylvan_mtbdd_getnumer(MTBDD terminal) {
    return mtbdd_getnumer(terminal);
}

uint32_t Sylvan_mtbdd_getdenom(MTBDD terminal) {
    return mtbdd_getdenom(terminal);
}

MTBDD Sylvan_mtbdd_ithvar(uint32_t var) {
    return mtbdd_ithvar(var);
}

MTBDD Sylvan_ithvar(uint32_t var) {
    return sylvan_ithvar(var);
}

MTBDD Sylvan_mtbdd_set_empty() {
    return mtbdd_set_empty();
}

MTBDD Sylvan_set_empty() {
    return sylvan_set_empty();
}

int Sylvan_mtbdd_set_isempty(MTBDD set) {
    return mtbdd_set_isempty(set);
}

int Sylvan_set_isempty(MTBDD set) {
    return sylvan_test_isbdd(set);
}

uint32_t Sylvan_mtbdd_set_first(MTBDD set) {
    return mtbdd_set_first(set);
}

uint32_t Sylvan_set_first(MTBDD set) {
    return sylvan_set_first(set);
}

MTBDD Sylvan_mtbdd_set_next(MTBDD set) {
    return mtbdd_set_next(set);
}

MTBDD Sylvan_set_next(MTBDD set) {
    return sylvan_set_next(set);
}

MTBDD Sylvan_mtbdd_set_from_array(uint32_t* arr, size_t length) {
    return mtbdd_set_from_array(arr, length);
}

MTBDD Sylvan_mtbdd_fromarray(uint32_t* arr, size_t length) {
    return mtbdd_fromarray(arr, length);
}

MTBDD Sylvan_mtbdd_set_fromarray(uint32_t* arr, size_t length) {
    return mtbdd_set_fromarray(arr, length);
}

MTBDD Sylvan_set_fromarray(uint32_t* arr, size_t length) {
    return sylvan_set_fromarray(arr, length);
}

void Sylvan_mtbdd_set_to_array(MTBDD set, uint32_t *arr) {
    mtbdd_set_to_array(set, arr);
}

void Sylvan_mtbdd_set_toarray(MTBDD set, uint32_t *arr) {
    mtbdd_set_toarray(set, arr);
}

void Sylvan_set_toarray(MTBDD set, uint32_t *arr) {
    sylvan_set_toarray(set, arr);
}

size_t Sylvan_mtbdd_set_count(MTBDD set) {
    return mtbdd_set_count(set);
}

size_t Sylvan_set_count(MTBDD set) {
    return sylvan_set_count(set);
}

MTBDD Sylvan_mtbdd_set_union(MTBDD set1, MTBDD set2) {
    return mtbdd_set_union(set1, set2);
}

MTBDD Sylvan_mtbdd_set_addall(MTBDD set1, MTBDD set2) {
    return mtbdd_set_addall(set1, set2);
}

MTBDD Sylvan_set_addall(MTBDD set1, MTBDD set2) {
    return sylvan_set_addall(set1, set2);
}

MTBDD Sylvan_mtbdd_set_minus(MTBDD set1, MTBDD set2) {
    return mtbdd_set_minus(set1, set2);
}

MTBDD Sylvan_mtbdd_set_removeall(MTBDD set1, MTBDD set2) {
    return mtbdd_set_removeall(set1, set2);
}

MTBDD Sylvan_set_removeall(MTBDD set1, MTBDD set2) {
    return sylvan_set_removeall(set1, set2);
}

int Sylvan_mtbdd_set_contains(MTBDD set, uint32_t var) {
    return mtbdd_set_contains(set, var);
}

int Sylvan_mtbdd_set_in(MTBDD set, uint32_t var) {
    return mtbdd_set_in(set, var);
}

int Sylvan_set_in(MTBDD set, uint32_t var) {
    return sylvan_set_in(set, var);
}

MTBDD Sylvan_mtbdd_set_add(MTBDD set, uint32_t var) {
    return mtbdd_set_addall(set, var);
}

MTBDD Sylvan_set_add(MTBDD set, uint32_t var) {
    return sylvan_set_add(set, var);
}

MTBDD Sylvan_mtbdd_set_remove(MTBDD set, uint32_t var) {
    return mtbdd_set_remove(set, var);
}

MTBDD Sylvan_set_remove(MTBDD set, uint32_t var) {
    return sylvan_set_remove(set, var);
}

void Sylvan_mtbdd_test_isset(MTBDD set) {
    mtbdd_test_isset(set);
}

void Sylvan_test_isset(MTBDD set) {
    sylvan_test_isbdd(set);
}

MTBDD Sylvan_mtbdd_cube(MTBDD variables, uint8_t *cube, MTBDD terminal) {
    return mtbdd_cube(variables, cube, terminal);
}

BDD Sylvan_mtbdd_union_cube(MTBDD mtbdd, MTBDD variables, uint8_t *cube, MTBDD terminal) {
    return mtbdd_union_cube(mtbdd, variables, cube, terminal);
}

double Sylvan_mtbdd_satcount(MTBDD dd, size_t nvars) {
    return mtbdd_satcount(dd, nvars);
}

size_t Sylvan_mtbdd_leafcount_more(const MTBDD *mtbdds, size_t count) {
    return mtbdd_leafcount_more(mtbdds, count);
}

size_t Sylvan_mtbdd_leafcount(MTBDD dd) {
    return mtbdd_leafcount(dd);
}

size_t Sylvan_mtbdd_nodecount_more(const MTBDD *mtbdds, size_t count) {
    return mtbdd_nodecount_more(mtbdds, count);
}

size_t Sylvan_mtbdd_nodecount(const MTBDD dd) {
    return mtbdd_nodecount(dd);
}

size_t Sylvan_nodecount(const MTBDD dd) {
    return sylvan_nodecount(dd);
}

MTBDD Sylvan_mtbdd_apply(MTBDD a, MTBDD b, mtbdd_apply_op op) {
    return mtbdd_apply(a, b, op);
}

MTBDD Sylvan_mtbdd_applyp(MTBDD a, MTBDD b, size_t p, mtbdd_applyp_op op, uint64_t opid) {
    return mtbdd_applyp(a, b, p, op, opid);
}

MTBDD Sylvan_mtbdd_uapply(MTBDD dd, mtbdd_uapply_op op, size_t param) {
    return mtbdd_uapply(dd, op, param);
}

MTBDD Sylvan_mtbdd_abstract(MTBDD a, MTBDD v, mtbdd_abstract_op op) {
    return mtbdd_abstract(a, v, op);
}

MTBDD Sylvan_mtbdd_negate(MTBDD a) {
    return mtbdd_negate(a);
}

MTBDD Sylvan_mtbdd_cmpl(MTBDD a) {
    return mtbdd_cmpl(a);
}

MTBDD Sylvan_mtbdd_plus(MTBDD a, MTBDD b) {
    return mtbdd_plus(a, b);
}

MTBDD Sylvan_mtbdd_minus(MTBDD a, MTBDD b) {
    return mtbdd_minus(a, b);
}

MTBDD Sylvan_mtbdd_times(MTBDD a, MTBDD b) {
    return mtbdd_times(a, b);
}

MTBDD Sylvan_mtbdd_min(MTBDD a, MTBDD b) {
    return mtbdd_min(a, b);
}

MTBDD Sylvan_mtbdd_max(MTBDD a, MTBDD b) {
    return mtbdd_max(a, b);
}

MTBDD Sylvan_mtbdd_abstract_plus(MTBDD dd, MTBDD v) {
    return mtbdd_abstract_plus(dd, v);
}

MTBDD Sylvan_mtbdd_abstract_times(MTBDD dd, MTBDD v) {
    return mtbdd_abstract_times(dd, v);
}

MTBDD Sylvan_mtbdd_abstract_min(MTBDD dd, MTBDD v) {
    return mtbdd_abstract_min(dd, v);
}

MTBDD Sylvan_mtbdd_abstract_max(MTBDD dd, MTBDD v) {
    return mtbdd_abstract_max(dd, v);
}

MTBDD Sylvan_mtbdd_ite(MTBDD f, MTBDD g, MTBDD h) {
    return mtbdd_ite(f, g, h);
}

MTBDD Sylvan_mtbdd_and_abstract_plus(MTBDD a, MTBDD b, MTBDD vars) {
    return mtbdd_and_abstract_plus(a, b, vars);
}

MTBDD Sylvan_mtbdd_and_exists(MTBDD a, MTBDD b, MTBDD vars) {
    return mtbdd_and_exists(a, b, vars);
}

MTBDD Sylvan_mtbdd_and_abstract_max(MTBDD a, MTBDD b, MTBDD vars) {
    return mtbdd_and_abstract_max(a, b, vars);
}

MTBDD Sylvan_mtbdd_threshold_double(MTBDD dd, double value) {
    return mtbdd_threshold_double(dd, value);
}

MTBDD Sylvan_mtbdd_strict_threshold_double(MTBDD dd, double value) {
    return mtbdd_strict_threshold_double(dd, value);
}

MTBDD Sylvan_mtbdd_equal_norm_d(MTBDD a, MTBDD b, double epsilon) {
    return mtbdd_equal_norm_d(a, b, epsilon);
}

MTBDD Sylvan_mtbdd_equal_norm_rel_d(MTBDD a, MTBDD b, double epsilon) {
    return mtbdd_equal_norm_rel_d(a, b, epsilon);
}

MTBDD Sylvan_mtbdd_leq(MTBDD a, MTBDD b) {
    return mtbdd_leq(a, b);
}

MTBDD Sylvan_mtbdd_less(MTBDD a, MTBDD b) {
    return mtbdd_less(a, b);
}

MTBDD Sylvan_mtbdd_geq(MTBDD a, MTBDD b) {
    return mtbdd_geq(a, b);
}

MTBDD Sylvan_mtbdd_greater(MTBDD a, MTBDD b) {
    return mtbdd_greater(a, b);
}

MTBDD Sylvan_mtbdd_support(MTBDD dd) {
    return mtbdd_support(dd);
}

MTBDD Sylvan_support(MTBDD dd) {
    return sylvan_support(dd);
}

MTBDD Sylvan_mtbdd_compose(MTBDD dd, MTBDDMAP map) {
    return mtbdd_compose(dd, map);
}

MTBDD Sylvan_mtbdd_minimum(MTBDD dd) {
    return mtbdd_minimum(dd);
}

MTBDD Sylvan_mtbdd_maximum(MTBDD dd) {
    return mtbdd_maximum(dd);
}

MTBDD Sylvan_mtbdd_enum_first(MTBDD dd, MTBDD variables, uint8_t *arr, mtbdd_enum_filter_cb filter_cb) {
    return mtbdd_enum_first(dd, variables, arr, filter_cb);
}

MTBDD Sylvan_mtbdd_enum_next(MTBDD dd, MTBDD variables, uint8_t *arr, mtbdd_enum_filter_cb filter_cb) {
    return mtbdd_enum_next(dd, variables, arr, filter_cb);
}

MTBDD Sylvan_mtbdd_enum_all_first(MTBDD dd, MTBDD variables, uint8_t *arr, mtbdd_enum_filter_cb filter_cb) {
    return mtbdd_enum_all_first(dd, variables, arr, filter_cb);
}

MTBDD Sylvan_mtbdd_enum_all_next(MTBDD dd, MTBDD variables, uint8_t *arr, mtbdd_enum_filter_cb filter_cb) {
    return mtbdd_enum_all_next(dd, variables, arr, filter_cb);
}

void Sylvan_mtbdd_enum_par(MTBDD dd, mtbdd_enum_cb cb, void *context) {
    mtbdd_enum_par(dd, cb, context);
}

MTBDD Sylvan_mtbdd_eval_compose(MTBDD dd, MTBDD vars, mtbdd_eval_compose_cb cb) {
    return mtbdd_eval_compose(dd, vars, cb);
}

int Sylvan_mtbdd_test_isvalid(MTBDD mtbdd) {
    return mtbdd_test_isvalid(mtbdd);
}

int Sylvan_test_isbdd(MTBDD mtbdd) {
    return sylvan_test_isbdd(mtbdd);
}

void Sylvan_mtbdd_fprintdot(FILE *out, MTBDD mtbdd) {
    mtbdd_fprintdot(out, mtbdd);
}

void Sylvan_fprintdot(FILE *out, MTBDD mtbdd) {
    sylvan_fprintdot(out, mtbdd);
}

void Sylvan_mtbdd_printdot(MTBDD mtbdd) {
    mtbdd_printdot(mtbdd, NULL);
}

void Sylvan_printdot(MTBDD mtbdd) {
    sylvan_printdot(mtbdd, NULL);
}

void Sylvan_mtbdd_fprintdot_nc(FILE *out, MTBDD mtbdd) {
    mtbdd_fprintdot_nc(out, mtbdd);
}

void Sylvan_mtbdd_printdot_nc(MTBDD mtbdd) {
    mtbdd_printdot_nc(mtbdd, NULL);
}

void Sylvan_mtbdd_fprint_leaf(FILE *out, MTBDD leaf) {
    mtbdd_fprint_leaf(out, leaf);
}

void Sylvan_mtbdd_print_leaf(MTBDD leaf) {
    mtbdd_print_leaf(leaf);
}

char * Sylvan_mtbdd_leaf_to_str(MTBDD leaf, char *buf, size_t buflen) {
    return mtbdd_leaf_to_str(leaf, buf, buflen);
}

void Sylvan_mtbdd_printsha(MTBDD dd) {
    mtbdd_printsha(dd);
}

void Sylvan_printsha(MTBDD dd) {
    sylvan_printsha(dd);
}

void Sylvan_mtbdd_fprintsha(FILE *f, MTBDD dd) {
    mtbdd_fprintsha(f, dd);
}

void Sylvan_fprintsha(FILE *f, MTBDD dd) {
    sylvan_fprintsha(f, dd);
}

void Sylvan_mtbdd_getsha(MTBDD dd, char *target) {
    mtbdd_getsha(dd, target);
}

void Sylvan_getsha(MTBDD dd, char *target) {
    sylvan_getsha(dd, target);
}

void Sylvan_mtbdd_visit_seq(MTBDD dd, mtbdd_visit_pre_cb pre, mtbdd_visit_post_cb post, void *context) {
    mtbdd_visit_seq(dd, pre, post, context);
}

void Sylvan_mtbdd_visit_par(MTBDD dd, mtbdd_visit_pre_cb pre, mtbdd_visit_post_cb post, void *context) {
    mtbdd_visit_par(dd, pre, post, context);
}

void Sylvan_mtbdd_writer_tobinary(FILE *file, MTBDD *dds, int count) {
    mtbdd_writer_tobinary(file, dds, count);
}

void Sylvan_mtbdd_writer_totext(FILE *file, MTBDD *dds, int count) {
    mtbdd_writer_totext(file, dds, count);
}

sylvan_skiplist_t Sylvan_mtbdd_writer_start(void) {
    return mtbdd_writer_start();
}

void Sylvan_mtbdd_writer_add(sylvan_skiplist_t sl, MTBDD dd) {
    mtbdd_writer_add(sl, dd);
}

void Sylvan_mtbdd_writer_writebinary(FILE *out, sylvan_skiplist_t sl) {
    mtbdd_writer_writebinary(out, sl);
}

uint64_t Sylvan_mtbdd_writer_get(sylvan_skiplist_t sl, MTBDD dd) {
    return mtbdd_writer_get(sl, dd);
}

void Sylvan_mtbdd_writer_end(sylvan_skiplist_t sl) {
    mtbdd_writer_end(sl);
}

int Sylvan_mtbdd_reader_frombinary(FILE *file, MTBDD *dds, int count) {
    return mtbdd_reader_frombinary(file, dds, count);
}

uint64_t * Sylvan_mtbdd_reader_readbinary(FILE *file) {
    return mtbdd_reader_readbinary(file);
}

MTBDD Sylvan_mtbdd_reader_get(uint64_t* arr, uint64_t identifier) {
    return mtbdd_reader_get(arr, identifier);
}

void Sylvan_mtbdd_reader_end(uint64_t *arr) {
    mtbdd_reader_end(arr);
}

MTBDD Sylvan_mtbdd_map_empty() {
    return mtbdd_map_empty();
}

MTBDD Sylvan_map_empty() {
    return sylvan_map_empty();
}

int Sylvan_mtbdd_map_isempty(MTBDD map) {
    return mtbdd_map_isempty(map);
}

int Sylvan_map_isempty(MTBDD map) {
    return sylvan_map_isempty(map);
}

uint32_t Sylvan_mtbdd_map_key(MTBDD map) {
    return mtbdd_map_key(map);
}

uint32_t Sylvan_map_key(MTBDD map) {
    return sylvan_map_key(map);
}

MTBDD Sylvan_mtbdd_map_value(MTBDD map) {
    return mtbdd_map_value(map);
}

MTBDD Sylvan_map_value(MTBDD map) {
    return sylvan_map_value(map);
}

MTBDD Sylvan_mtbdd_map_next(MTBDD map) {
    return mtbdd_map_next(map);
}

MTBDD Sylvan_map_next(MTBDD map) {
    return sylvan_map_next(map);
}

int Sylvan_mtbdd_map_contains(MTBDDMAP map, uint32_t key) {
    return mtbdd_map_contains(map, key);
}

int Sylvan_map_contains(MTBDDMAP map, uint32_t key) {
    return sylvan_map_contains(map, key);
}

size_t Sylvan_mtbdd_map_count(MTBDDMAP map) {
    return mtbdd_map_count(map);
}

size_t Sylvan_map_count(MTBDDMAP map) {
    return sylvan_map_count(map);
}

MTBDDMAP Sylvan_mtbdd_map_add(MTBDDMAP map, uint32_t key, MTBDD value) {
    return mtbdd_map_add(map, key, value);
}

MTBDDMAP Sylvan_map_add(MTBDDMAP map, uint32_t key, MTBDD value) {
    return sylvan_map_add(map, key, value);
}

MTBDDMAP Sylvan_mtbdd_map_update(MTBDDMAP map1, MTBDDMAP map2) {
    return mtbdd_map_update(map1, map2);
}

MTBDDMAP Sylvan_mtbdd_map_addall(MTBDDMAP map1, MTBDDMAP map2) {
    return mtbdd_map_addall(map1, map2);
}

MTBDDMAP Sylvan_map_addall(MTBDDMAP map1, MTBDDMAP map2) {
    return sylvan_map_addall(map1, map2);
}

MTBDDMAP Sylvan_mtbdd_map_remove(MTBDDMAP map, uint32_t key) {
    return mtbdd_map_remove(map, key);
}

MTBDDMAP Sylvan_map_remove(MTBDDMAP map, uint32_t key) {
    return sylvan_map_remove(map, key);
}

MTBDDMAP Sylvan_mtbdd_map_removeall(MTBDDMAP map, MTBDD variables) {
    return mtbdd_map_removeall(map, variables);
}

MTBDDMAP Sylvan_map_removeall(MTBDDMAP map, MTBDD variables) {
    return sylvan_map_removeall(map, variables);
}

void Sylvan_mtbdd_gc_mark_rec(MTBDD mtbdd) {
    mtbdd_gc_mark_rec(mtbdd);
}

void Sylvan_gc_mark_rec(MTBDD mtbdd) {
    sylvan_gc_mark_rec(mtbdd);
}

void Sylvan_mtbdd_protect(MTBDD* ptr) {
    mtbdd_protect(ptr);
}

void Sylvan_protect(MTBDD* ptr) {
    sylvan_protect(ptr);
}

void Sylvan_mtbdd_unprotect(MTBDD* ptr) {
    mtbdd_unprotect(ptr);
}

void Sylvan_unprotect(MTBDD* ptr) {
    sylvan_unprotect(ptr);
}

size_t Sylvan_mtbdd_count_protected(void) {
    return mtbdd_count_protected();
}

size_t Sylvan_count_protected(void) {
    return sylvan_count_protected();
}

MTBDD Sylvan_mtbdd_ref(MTBDD dd) {
    return mtbdd_ref(dd);
}

MTBDD Sylvan_ref(MTBDD dd) {
    return sylvan_ref(dd);
}

void Sylvan_mtbdd_deref(MTBDD dd) {
    mtbdd_deref(dd);
}

void Sylvan_deref(MTBDD dd) {
    sylvan_deref(dd);
}

size_t Sylvan_mtbdd_count_refs(void) {
    return mtbdd_count_refs();
}

size_t Sylvan_count_refs(void) {
    return sylvan_count_refs();
}

void Sylvan_mtbdd_refs_pushptr(const MTBDD *ptr) {
    mtbdd_refs_pushptr(ptr);
}

void Sylvan_refs_pushptr(const MTBDD *ptr) {
    bdd_refs_pushptr(ptr);
}

void Sylvan_mtbdd_refs_popptr(size_t amount) {
    mtbdd_refs_popptr(amount);
}

void Sylvan_refs_popptr(size_t amount) {
    bdd_refs_popptr(amount);
}

MTBDD Sylvan_mtbdd_refs_push(MTBDD mtbdd) {
    return mtbdd_refs_push(mtbdd);
}

MTBDD Sylvan_refs_push(MTBDD mtbdd) {
    return bdd_refs_push(mtbdd);
}

void Sylvan_mtbdd_refs_pop(long amount) {
    mtbdd_refs_pop(amount);
}

void Sylvan_refs_pop(long amount) {
    bdd_refs_pop(amount);
}

void Sylvan_mtbdd_refs_spawn(Task *t) {
    mtbdd_refs_spawn(t);
}

void Sylvan_refs_spawn(Task *t) {
    bdd_refs_spawn(t);
}

MTBDD Sylvan_mtbdd_refs_sync(MTBDD mtbdd) {
    return mtbdd_refs_sync(mtbdd);
}

MTBDD Sylvan_refs_sync(MTBDD mtbdd) {
    return bdd_refs_sync(mtbdd);
}

/*
    lace.h wrapper:
 */

void Lace_set_verbosity(int level) {
    lace_set_verbosity(level);
}

void Lace_set_stacksize(size_t stacksize) {
    lace_set_stacksize(stacksize);
}

size_t Lace_get_stacksize(void) {
    return lace_get_stacksize();
}

unsigned int Lace_get_pu_count(void) {
    return lace_get_pu_count();
}

void Lace_start(unsigned int n_workers, size_t dqsize) {
    lace_start(n_workers, dqsize);
}

void Lace_suspend(void) {
    lace_suspend();
}

void Lace_resume(void) {
    lace_resume();
}

void Lace_stop(void) {
    lace_stop();
}

void Lace_barrier(void) {
    lace_barrier();
}

unsigned int Lace_workers(void) {
    return lace_workers();
}

WorkerP *Lace_get_worker(void) {
    return lace_get_worker();
}

Task *Lace_get_head(WorkerP *worker) {
    return lace_get_head(worker);
}

void Lace_run_task(Task *task) {
    lace_run_task(task);
}

void Lace_run_newframe(Task *task) {
    lace_run_newframe(task);
}

void Lace_run_together(Task *task) {
    lace_run_together(task);
}
