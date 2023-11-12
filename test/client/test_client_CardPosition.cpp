//
// Created by louis on 11/12/23.
//
#include <boost/test/unit_test.hpp>
#include "../../src/client/render.h"

namespace render {
    BOOST_AUTO_TEST_CASE(firstCardPos) {
        float X = 0;
        float Y = 0;
        float angle = 0;
        CardPosition* cardPositionTest = new CardPosition(X, Y, angle);
        float Y2 = cardPositionTest->get_pixelY();
        float X2 = cardPositionTest->get_pixelX();
        float angle2 = cardPositionTest->get_angle();
        cardPositionTest->set_pixelY(Y);
        cardPositionTest->set_pixelX(X);
        cardPositionTest->set_angle(angle);
        BOOST_CHECK_EQUAL(X, X2);
        BOOST_CHECK_EQUAL(Y, Y2);
        BOOST_CHECK_EQUAL(angle, angle2);
    }
}