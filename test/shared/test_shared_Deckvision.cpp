#include <boost/test/unit_test.hpp>
#include "../../src/shared/state/DeckVision.h"
using namespace state;
BOOST_AUTO_TEST_CASE(firstDeckVisionTest){
        DeckVision dv = DeckVision();
        dv.draw ();
        BOOST_CHECK(1);
}