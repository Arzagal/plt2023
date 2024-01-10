#include "NextCommand.h"
namespace engine{
    NextCommand::NextCommand() {
        
    }
    bool NextCommand::execute(engine::Engine *engine) {
        engine->get_display()->getGameState()->next_state();
        engine->get_display()->getGameState()->notifyObserver(engine->get_display()->getGameState()->get_state(), engine->get_display()->getGameState()->get_active_player());
        return true;
    }
}
