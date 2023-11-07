//
// Created by louis on 11/7/23.
//


#include <boost/test/unit_test.hpp>
#include "../../src/shared/state/Card.h"
namespace state {
    BOOST_AUTO_TEST_CASE(firstCardTest){
            Card card = Card ();
            card.activate_effect ();
            BOOST_CHECK(1);
    }
}