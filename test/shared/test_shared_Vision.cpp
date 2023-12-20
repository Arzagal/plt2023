//
// Created by louis on 11/7/23.
//
#include <boost/test/unit_test.hpp>
#include "../../src/shared/state/Vision.h"
using namespace state;
BOOST_AUTO_TEST_CASE(firstVisionTest){
        Vision vision = Vision(1);
        int num = 0;
        Player target = Player(num);
        vision.choose_target (target);
        int get_id = vision.get_id();
        BOOST_CHECK(1);
}
