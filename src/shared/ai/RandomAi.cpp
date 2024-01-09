//
// Created by louis on 12/18/23.
//

#include "RandomAi.h"

namespace ai {
    RandomAi::RandomAi(state::Game *game, int playerNumber) {
        this->game = game;
        this->playerNumber = playerNumber;
    }

    void RandomAi::stateChanged(state::State state, int playerNum) {
        if (playerNum == this->playerNumber) {
            switch (state) {
                case state::Playing :
                    this->game->next_state();
                    break;
                case state::Move :
                    this->game->move_player(this->playerNumber, rand()%6 + rand()%4 + 2);
                    this->game->next_state();
                    break;
                case state::Location_effect :
                    this->game->next_state();
                    break;
                case state::Attack : {
                    std::vector<int> neighbours = this->game->get_neighbours(playerNum);
                    if (neighbours.empty()) {
                        this->game->attack(this->playerNumber, neighbours[0]);
                    }
                    this->game->next_state();
                    break;
                }
                case state::Card_effect :
                    if(this->playerNumber == this->game->get_number_player()){
                        this->game->activate_card_effect(this->playerNumber-1);
                    }
                    else{
                        this->game->activate_card_effect(this->playerNumber+1);
                    }
                    this->game->next_state();
                case state::Finished:
                    this->game->next_state();
                    break;

                case state::Starting:
                    break;
            }
        }
    }
}