//
// Created by louis on 11/7/23.
//
#include <boost/test/unit_test.hpp>
#include "../../src/shared/state/Player.h"
#include "../../src/shared/state.h"
using namespace state;
    BOOST_AUTO_TEST_CASE(firstPlayerTest){
        int num1 = 0;
        int num2 = 1;
        Player player = Player(num1);
        Player target = Player(num2);
        Character character;
        Darknlight* card = new Darknlight();
        int hp;

        player.active_character_effect ();
        player.active_character_effect();
        player.reveal ();
        int hp_res = player.get_hp ();
        player.set_hp (hp);

        player.set_character (character);
        int get_number = player.get_number();
        std::vector <Darknlight*> equipped;
        equipped = player.get_equipped_card ();
        player.active_board_effect ();

        player.equipe_card (card);
        BOOST_CHECK(1);
    }
