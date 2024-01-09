//
// Created by louis on 11/7/23.
//
#include <boost/test/unit_test.hpp>
#include "../../src/shared/state/DeckDark.h"
using namespace state;
BOOST_AUTO_TEST_CASE(firstDeckDarkTest){
    DeckDark dk = DeckDark();
    dk.draw ();
    BOOST_CHECK(1);
}