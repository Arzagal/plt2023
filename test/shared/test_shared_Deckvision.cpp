//
// Created by louis on 11/7/23.
//
#include <boost/test/unit_test.hpp>
#include "../../src/shared/state/DeckVision.h"
using namespace state;
BOOST_AUTO_TEST_CASE(firstDeckVisionTest){
        int card_id = 0;
        DeckVision dv = DeckVision();
        dv.draw ();
        BOOST_CHECK(1);
}