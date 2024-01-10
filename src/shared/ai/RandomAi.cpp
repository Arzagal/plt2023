//
// Created by louis on 12/18/23.
//

#include <csignal>
#include <iostream>
#include <regex>
#include <wait.h>
#include "RandomAi.h"

namespace ai {
    RandomAi::RandomAi(state::Game *game, int playerNumber) {
        this->game = game;
        this->playerNumber = playerNumber;
    }

    void RandomAi::stateChanged(state::State state, int playerNum) {
        std::vector<int> neighbours;
        int i;
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
                case state::Attack :
                    neighbours = this->game->get_neighbours(playerNum);
                    if (!neighbours.empty()) {
                        i = 0;
                        while(!this->game->get_Player_liste()[i]->is_alive() && i<int(neighbours.size())-1){
                            i++;
                        }
                        this->game->attack(this->playerNumber, neighbours[i]);
                    }
                    this->game->next_state();
                    break;

                case state::Card_effect :
                    i = rand() % 4;
                    this->game->activate_card_effect(i);
                    this->game->next_state();
                    break;
                case state::Finished: case state::Starting:
                    break;
            }

        }
    }
}