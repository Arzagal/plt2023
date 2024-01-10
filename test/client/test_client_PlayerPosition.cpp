#include "/usr/include/boost/test/unit_test.hpp"
#include "../../src/client/render.h"

using namespace render;

BOOST_AUTO_TEST_CASE(FirstPlayPosi){
    float x1 = 1;
    float y1 = 1;
    int num1 = 1;
    PlayerPosition pp = PlayerPosition(x1, y1, num1);
    sf::Vector2f test1 = sf::Vector2f(x1, y1);

    BOOST_TEST(test1.x == pp.get_position().x);
    BOOST_TEST(test1.y == pp.get_position().y);
    BOOST_TEST(num1 == pp.getPlayerNum());

    float y2 = 0.5;
    float x2 = 0.5;
    int num2 = 0.5;
    pp.setPixelY(y2);
    pp.setPixelX(x2);
    pp.setPlayerNum(num2);

    BOOST_TEST(pp.getPixelX() == x2);
    BOOST_TEST(pp.getPixelY() == y2);
    BOOST_TEST(pp.getPlayerNum() == num2);
}