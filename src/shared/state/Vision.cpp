//
// Created by louis on 10/24/23.
//
#include <algorithm>
#include "Vision.h"

namespace state{
    Vision::Vision(int id) : card_id(id) {}


    int Vision::get_id (){
        return this->card_id;
    }

    void Vision::activate_effect(Player* target, Game* game) {
        switch(this->card_id){
            case(1) :
                if(std::find(this->effect[this->card_id]->teamtargets.begin(),this->effect[this->card_id]->teamtargets.end(), game->get_Player_liste()[target]->getTeams())
                != this->effect[this->card_id]->teamtargets.end()){
                    if(game->get_wounds(target) != 0){
                        game->heal(target, this->effect[this->card_id]->damage);
                    }
                    else{
                        game->add_wound(target, this->effect[this->card_id]->damage);
                    }
                }
        }
    }
}