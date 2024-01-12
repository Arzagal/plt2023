#include <algorithm>
#include <iostream>
#include "Vision.h"

namespace state{
    Vision::Vision(int id) : card_id(id) {
        this->card_id = id;
        this->card_type = 2;
    }


    int Vision::get_id (){
        return this->card_id;
    }

    void Vision::activate_effect(int target, Game* game) {
        Player *targetPlayer = game->get_Player_liste()[target];
        switch (card_id) {
            case 1:
                if (targetPlayer->getTeams() == 2){
                    game->add_wound(target, 1);
                }
                break;
            case 2:
            case 3:
                if (targetPlayer->getTeams() == 0){
                    game->add_wound(target, 1);
                }
                break;
            case 4:
            case 5:
            case 6:
                if (targetPlayer->getTeams() == 1 || targetPlayer->getTeams() == 2 ){
                    game->add_wound(target, 1);
                }
                break;
            case 7:
                if (targetPlayer->getTeams() == 0 || targetPlayer->getTeams() == 2 ){
                    game->add_wound(target, 1);
                }
                break;
            case 8:
                if (targetPlayer->getTeams() == 0){
                    game->add_wound(target, 2);
                }
                break;
            case 9:
                if (targetPlayer->getTeams() == 1){
                    game->add_wound(target, 1);
                }
                break;
            case 10:
                if (targetPlayer->getTeams() == 0){
                    game->add_wound(target, 1);
                }
                break;
            case 11:
                if (targetPlayer->getTeams() == 1){
                    game->heal(target, 1);
                }
                break;
            case 12:
                if (targetPlayer->getTeams() == 1 || targetPlayer->getTeams() == 0){
                    game->add_wound(target, 1);
                }
                break;

            default:
                break;
        }
    }
}