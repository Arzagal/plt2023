//
// Created by louis on 10/24/23.
//
#include <algorithm>
#include "Vision.h"

namespace state{
    Vision::Vision(int id) : card_id(id) {}

    void Vision::choose_target (Player target) {}

    int Vision::get_id (){
        return this->card_id;
    }

    void Vision::activate_effect(int target) {
        switch(this->card_id){
            case(1) :
                if(std::find(this->effect->teamtargets.begin(),this->effect->teamtargets.end(), this->game->get_Player_liste()[target]->getTeams())
                != this->effect->teamtargets.end()){
                    if(this->game->get_wounds(target) != 0){
                        this->game->heal(target, this->effect->damage);
                    }
                    else{
                        this->game->add_wound(target, this->effect->damage);
                    }
                }
        }
    }
}