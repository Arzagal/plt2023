#include <iostream>
#include "CardCommand.h"
namespace engine{
    CardCommand::CardCommand(int target):Command() {
        this->target=target;
    }
    bool CardCommand::execute(engine::Engine *engine) {
        std::cout << "Activating card effect from command\n";
        engine->get_game()->activate_card_effect(target);
        engine->get_display()->getGameState()->next_state();
        engine->get_game()->notifyObserver(engine->get_game()->get_state(), engine->get_game()->get_active_player());
        return true;
    }
}
