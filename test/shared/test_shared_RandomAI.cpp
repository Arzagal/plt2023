//
// Created by louis on 1/10/24.
//
#include <boost/test/unit_test.hpp>
#include "../../src/shared/ai.h"

using namespace ai;
using namespace state;
BOOST_AUTO_TEST_CASE(firstPlayerTest) {
    Game *game = new Game();
    game->add_player();
    game->add_player();
    game->add_player();
    ai::RandomAi *ai1 = new ai::RandomAi(game, 0);
    ai::RandomAi *ai2 = new ai::RandomAi(game, 1);
    ai::RandomAi *ai3 = new ai::RandomAi(game, 2);
    ai::RandomAi *ai4 = new ai::RandomAi(game, 3);

    game->registerObserver(ai1);
    game->registerObserver(ai2);
    game->registerObserver(ai3);
    game->registerObserver(ai4);

    game->start_game();
}