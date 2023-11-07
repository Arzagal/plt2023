//
// Created by louis on 11/7/23.
//

#include <boost/test/unit_test.hpp>
#include "../../src/shared/state/Darknlight.h"
namespace state {
    BOOST_AUTO_TEST_CASE(firstDarknlightTest){
            Darknlight darkn = Darknlight();
            darkn.get_id ();
            darkn.play_effect ();
            BOOST_CHECK(1);
    }
}