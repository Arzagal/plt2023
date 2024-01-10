#include "/usr/include/boost/test/unit_test.hpp"
#include "../../src/client/render.h"

using namespace render;

BOOST_AUTO_TEST_CASE(FirstCardPosi){
    float x1 = 1;
    float y1 = 1;
    float angle1 = 1;
    CardPosition cp = CardPosition(x1, y1, angle1);
    sf::Vector2f test1 = sf::Vector2f(x1, y1);

    BOOST_TEST(test1.x == cp.get_position().x);
    BOOST_TEST(test1.y == cp.get_position().y);
    BOOST_TEST(angle1 == cp.getAngle());

    float y2 = 0.5;
    float x2 = 0.5;
    float angle2 = 0.5;
    cp.setPixelY(y2);
    cp.setPixelX(x2);
    cp.setAngle(angle2);
    BOOST_TEST(cp.getPixelX() == x2);
    BOOST_TEST(cp.getPixelY() == y2);
    BOOST_TEST(cp.getAngle() == angle2);
}