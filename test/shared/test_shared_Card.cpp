#include <boost/test/unit_test.hpp>
#include "../../src/shared/state/Card.h"
using namespace state;
BOOST_AUTO_TEST_CASE(firstCardTest){
        Card card = Card ();
        card.activate_effect ();
        BOOST_CHECK(1);
}
