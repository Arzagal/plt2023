#include "AttackCommand.h"
namespace engine{
    AttackCommand::AttackCommand(int target):Command() {
        this->target=target;
    }
    bool AttackCommand::execute(engine::Engine *engine) {
        int player=engine->get_display()->getGameState()->get_active_player();
        engine->get_display()->getGameState()->attack(player, target);
        engine->get_display()->getGameState()->next_state();
        engine->get_display()->getGameState()->notifyObserver(engine->get_display()->getGameState()->get_state(), engine->get_display()->getGameState()->get_active_player());
        return true;
    }
}
