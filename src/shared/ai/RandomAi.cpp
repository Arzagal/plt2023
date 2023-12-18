//
// Created by louis on 12/18/23.
//

#include "RandomAi.h"

namespace ai {
    void RandomAi::stateChanged(state::State state, int playerNum) {
        if (playerNum == this->playerNumber) {
            switch (state) {
                case (state::Playing) :
                    break;
                case (state::Move) :
                    this->game->move_player()
            }
        }
    }
}