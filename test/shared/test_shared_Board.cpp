//
// Created by louis on 11/7/23.
//



#include <boost/test/unit_test.hpp>
#include "../../src/shared/state/Board.h"
#include "../../src/shared/state.h"

using namespace state;
BOOST_AUTO_TEST_CASE(firstBoard){
        int len = 1;
        Board* board = new Board(len);
        int num = 0;
        int location = 0;
        board -> random_init();
        board-> move_player(num,location);
        std::vector <int> neighbours = board-> get_neighbours(num);
        board-> get_effect(location);
        int loc = board-> get_location(num);
        BOOST_TEST(1);
}
