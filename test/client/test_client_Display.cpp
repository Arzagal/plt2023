//
// Created by louis on 11/27/23.
//
#include "/usr/include/boost/test/unit_test.hpp"
#include "../../src/client/render.h"
#include <SFML/Graphics.hpp>

using namespace render;
using namespace state;
BOOST_AUTO_TEST_CASE(DisplayTest){
    sf::RenderWindow window;
    sf::Sprite bg;
    Game *game = new Game();
    Display display = Display(window, bg, game);
    game->start_game();
    display.getGameState()->start_game();
    Darknlight* cardL = new Darknlight();
    cardL->set_card_type(0);
    Darknlight* cardD = new Darknlight();
    cardD->set_card_type(1);
    BOOST_CHECK_EQUAL(display.getGameState(), game);
    display.getGameState()->get_Player_liste()[0]->set_character(state::Agnes);
    display.getGameState()->get_Player_liste()[0]->equipe_card(cardL);
    display.getGameState()->get_Player_liste()[0]->equipe_card(cardD);
    display.refresh();
    display.getGameState()->get_Player_liste()[0]->reveal();
    display.refresh();
    display.draw_playing_card(1,0);
    display.draw_playing_card(1,1);
    display.draw_playing_card(1,2);
    display.draw_playing_card(-1,0);
    BOOST_CHECK(1);
}