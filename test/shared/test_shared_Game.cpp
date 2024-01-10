//
// Created by louis on 11/7/23.
//
#include <boost/test/unit_test.hpp>
#include "../../src/shared/state/Game.h"
using namespace state;
BOOST_AUTO_TEST_CASE(firstGameTest){
    Game game = Game();
    int target = 0;
    int value = 0;
    Card_type card_type = DARK;
    int location1 = 2;
    int location2 = 5;
    int location3 = 10;


    game.add_player();
    game.add_player();
    game.add_player();
    game.start_game();
    State state = game.get_state();
    BOOST_CHECK_EQUAL(state, state::Playing);
    game.next_state();
    game.next_state();
    game.next_state();
    game.next_state();
    game.next_state();
    game.next_state();
    game.add_dmg (target);
    game.draw (card_type);
    game.move_player (0, location1);
    game.move_player (1, location2);
    game.move_player (2, location3);
    game.active_board_effect (0);
    game.active_board_effect (1);
    game.active_board_effect (2);
    game.add_wound (0, value);
    game.heal (0, value);
    game.attack (0, 1);

    BOOST_TEST(1);
}