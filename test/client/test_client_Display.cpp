//
// Created by louis on 11/27/23.
//
#include "/usr/include/boost/test/unit_test.hpp"
#include "../../src/client/render.h"
#include <SFML/Graphics.hpp>

using namespace render;

BOOST_AUTO_TEST_CASE(DisplayTest){
    sf::RenderWindow window;
    sf::Sprite bg;
    Display display = Display(window, bg);
    display.getGameState()->start_game();
    display.refresh();
    display.draw_playing_card(0,0);
    BOOST_CHECK(1);
}