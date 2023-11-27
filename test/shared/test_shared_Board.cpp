//
// Created by louis on 11/7/23.
//
//
// Created by louis on 11/7/23.
//


#include <boost/test/unit_test.hpp>
#include "../../src/shared/state/Board.h"
#include "../../src/shared/state.h"

namespace state {
    BOOST_AUTO_TEST_CASE(firstBoard){
            Board* board = new Board();
            int num = 0;
            Player player = Player(num);
            int location = 0;
            board -> random_init();
            board-> move_player(player.get_number(),location);
            std::vector <int> neighbours = board-> get_neighbours(player.get_number());
            board-> get_effect(location);
            int loc = board-> get_location(player.get_number());
            BOOST_CHECK_EQUAL(loc, 0);
    }
}