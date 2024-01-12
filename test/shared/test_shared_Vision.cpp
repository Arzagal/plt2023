#include <boost/test/unit_test.hpp>
#include "../../src/shared/state/Vision.h"
using namespace state;
BOOST_AUTO_TEST_CASE(firstVisionTest){
    for (int id = 1; id <16; id++){
        Vision vision = Vision(id);
        int num = 0;
        Player target = Player(num);
        int get_id = vision.get_id();
        BOOST_CHECK_EQUAL(id, get_id);
        BOOST_CHECK(1);
    }
}
