//
// Created by franzozich on 18/12/23.
//
#include <iostream>
#include "MoveCommand.h"
namespace engine{
    MoveCommand::MoveCommand():Command(){

    }

    bool MoveCommand::execute(engine::Engine *engine) {
        int player=engine->get_display()->getGameState ()->get_active_player ();
        std::cout<<"Current Player"<<player<<"\n";
        engine->get_display()->getGameState()->move_player(player,rand() % 9 +2);
        engine->get_display()->getGameState()->notifyObserver(engine->get_display()->getGameState()->get_state(), engine->get_display()->getGameState()->get_active_player());

    }
}