//
// Created by louis on 11/7/23.
//
//
// Created by louis on 11/7/23.
//


#include <boost/test/unit_test.hpp>
#include "../../src/shared/state/Board.h"
namespace state {
    BOOST_AUTO_TEST_CASE(firstBoard){
            Board* board = new Board();
            Player player = Player();
            int location = 0;
            board -> random_init();
            board-> move_player(player,location);
            std::vector <Player> neighbours = board-> get_neighbours(player);
            board-> get_effect(location);
            int loc = board-> get_location(player);
            BOOST_CHECK_EQUAL(loc, 0);
    }
}