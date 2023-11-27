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
            int num1 = 0;
            int num2 = 1;
            Card_type card_type;
            Player player = Player(num1);
            int location = 0;
            Player active_player = Player(num1);
            Player attacked = Player(num2);
            Player attacking = Player(num1);

            game.add_player ();
            game.new_turn ();
            game.add_dmg (target);
            game.draw (card_type);
            State state = game.get_state ();
            game.start_game ();
            game.move_player (player.get_number(), location);
            game.active_board_effect (active_player.get_number());
            game.add_wound (player.get_number(), value);
            game.heal (player.get_number(), value);
            game.attack (attacking.get_number(), attacked.get_number());
            BOOST_CHECK(1);
    }
}