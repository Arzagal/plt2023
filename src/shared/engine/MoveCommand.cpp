#include <iostream>
#include <random>
#include "MoveCommand.h"
namespace engine{
    MoveCommand::MoveCommand():Command(){

    }

    bool MoveCommand::execute(engine::Engine *engine) {
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::default_random_engine randomness(seed);
        std::uniform_int_distribution<int> distribution6(0, 6-1);
        std::uniform_int_distribution<int> distribution4(0, 4-1);
        // Generate a random integer.
        int randomInt6 = distribution6(randomness);
        int randomInt4 = distribution6(randomness);

        int player=engine->get_display()->getGameState ()->get_active_player ();
        std::cout<<"Current Player"<<player<<"\n";
        engine->get_display()->getGameState()->move_player(player,randomInt6 + randomInt4 +2);
        engine->get_display()->getGameState()->next_state();
        engine->get_display()->getGameState()->notifyObserver(engine->get_display()->getGameState()->get_state(), engine->get_display()->getGameState()->get_active_player());
        return true;
    }
}