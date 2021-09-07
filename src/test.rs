use crate::bdd::{Sylvan_and, Sylvan_xor};
use crate::common::{
    Sylvan_gc_disable, Sylvan_init_package, Sylvan_quit, Sylvan_register_quit, Sylvan_set_limits,
};
use crate::lace::{Lace_start, Lace_stop};
use crate::mtbdd::{
    Sylvan_init_bdd, Sylvan_ithvar, Sylvan_mtbdd_not, Sylvan_mtbdd_plus, Sylvan_mtbdd_times,
    Sylvan_nodecount,
};
use crate::MTBDD_TRUE;

static mut CALLED: bool = false;

extern "C" fn termination_handler() {
    unsafe {
        CALLED = true;
    }
}

#[test]
pub fn basic_functionality_test() {
    unsafe {
        Lace_start(0, 0); // auto-detect thread count

        // 2^26 = ~64MB, should be enough for this test.
        Sylvan_set_limits(1 << 26, 1, 5);
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

        assert_eq!(3, Sylvan_nodecount(a_and_b));
        assert_eq!(3, Sylvan_nodecount(not_a_or_b));
        assert_eq!(a_and_b, not_a_or_b);

        let mut big_bdd = MTBDD_TRUE;
        for i in 1..20 {
            let x = Sylvan_ithvar(i);
            let y = Sylvan_ithvar(2 * i);
            let x_iff_y = Sylvan_xor(x, y);
            big_bdd = Sylvan_and(big_bdd, x_iff_y);

            let reported = Sylvan_nodecount(big_bdd);
            assert!(reported > 0);
        }

        assert_eq!(4091, Sylvan_nodecount(big_bdd));

        Sylvan_quit();
        Lace_stop();

        assert!(CALLED);
    }
}
