//
// Created by franzozich on 18/12/23.
//
#include "AttackCommand.h"
namespace engine{
    AttackCommand::AttackCommand(int target):Command() {
        this->target=target;
    }
    bool AttackCommand::execute(engine::Engine *engine) {
        engine->get_display()->getGameState()->add_wound(target,rand() % 9 +2);
        engine->get_display()->getGameState()->notifyObserver(engine->get_display()->getGameState()->get_state(), engine->get_display()->getGameState()->get_active_player());

    }
}
