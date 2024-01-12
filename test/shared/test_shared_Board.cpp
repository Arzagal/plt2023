#include <boost/test/unit_test.hpp>
#include "../../src/shared/state/Board.h"
#include "../../src/shared/state.h"

using namespace state;
BOOST_AUTO_TEST_CASE(firstBoard){
    int len = 4;
    Board* board = new Board(len);
    int num = 0;
    int location = 0;
    board-> move_player(0,location);
    board-> move_player(1,location);
    board-> move_player(2,2);
    board-> move_player(3,4);
    std::vector <int> neighbours1 = board-> get_neighbours(num);
    board-> move_player(0,2);
    std::vector <int> neighbours2 = board-> get_neighbours(num);
    board-> move_player(0,4);
    std::vector <int> neighbours3 = board-> get_neighbours(num);
    int loc = board-> get_location(num);
    BOOST_CHECK_EQUAL(loc, location);
    BOOST_CHECK(board->are_neighbours(0,3));
    BOOST_TEST(1);
}
