//
// Created by louis on 11/7/23.
//
#include <boost/test/unit_test.hpp>
#include "../../src/shared/state/Game.h"
namespace state {
    BOOST_AUTO_TEST_CASE(firstGameTest){
            Game game =  Game();
            int target = 0;
            int value = 0;
            Card_type card_type;
            Player player = Player();
            int location = 0;
            Player active_player = Player();
            Player attacked = Player();
            Player attacking = Player();

            game.add_player ();
            game.new_turn ();
            game.add_dmg (target);
            game.draw (card_type);
            State state = game.get_state ();
            game.start_game ();
            game.move_player (player, location);
            game.active_board_effect (active_player);
            game.add_wound (player, value);
            game.heal (player, value);
            game.attack (attacking, attacked);
            BOOST_CHECK(1);
    }
}