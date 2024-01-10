#include <boost/test/unit_test.hpp>
#include "../../src/shared/state/Darknlight.h"
using namespace state;
BOOST_AUTO_TEST_CASE(firstDarknlightTest){
    Darknlight darkn = Darknlight(1,1);
    darkn.set_id(12);
    darkn.set_card_type(0);
    int id = darkn.get_id ();
    int type = darkn.get_card_type();
    BOOST_CHECK_EQUAL(id, 12);
    BOOST_CHECK_EQUAL(type, 0);
    BOOST_CHECK(1);
}
