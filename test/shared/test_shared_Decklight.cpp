//
// Created by louis on 11/7/23.
//
#include <boost/test/unit_test.hpp>
#include "../../src/shared/state/DeckLight.h"
using namespace state;
BOOST_AUTO_TEST_CASE(firstDecklightTest){
        int card_id = 0;
        DeckLight dl = DeckLight();
        dl.remove (card_id);
        dl.draw ();
        BOOST_CHECK(1);
}