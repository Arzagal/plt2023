#include <iostream>
#include "Darknlight.h"

namespace state{
    Darknlight::Darknlight(int id, int card_type) : card_id(id), card_type(card_type){
    }

    int Darknlight:: get_id (){
        return this->card_id;
    }

    void Darknlight:: activate_effect (int target, Game* game) {
        if(this->card_type == 1) {
            srand(time(NULL));
            int alea;
            int choice;
            switch (card_id) {
                case 1:
                case 2:
                case 3:
                    alea = rand() % 6;
                    for (int player =0; player < game->get_number_player(); player++) {
                        if (game->get_player_location(player) == alea) {
                            game->add_wound(player, 3);
                        }
                    }
                    break;
                case 4:
                case 5:
                case 6:
                    if (target != NULL) {
                        game->add_wound(target, 2);
                        game->heal(game->get_active_player(), 2);
                    }
                    break;
                case 7:
                case 8:
                case 9:
                    choice = rand() % 2;
                    if (choice == 0){
                            game->add_wound(target, 5);
                    }else {
                        game->add_wound(game->get_active_player(), 5);
                    }

                    break;
                case 10:
                case 11:
                case 12:
                case 13:
                    for (int player =0; player <game->get_number_player(); player++) {
                        if (game->get_player_location(player) == 3) {
                            game->add_wound(player,1);
                        }
                    }
                    break;
                case 14:
                case 15:
                case 16:
                        game->add_wound(target, 2);
                    break;

                default:
                    break;
            }
        }
        else if(this->card_type == 0){
            srand(time(NULL));
            int alea;
            int choice;
            switch (card_id) {
                case 1:
                case 2:
                case 3:
                    alea = rand() % 6;
                    for (int player =0; player < game->get_number_player(); player++) {
                        if (game->get_player_location(player) == alea) {
                            game->heal(player, 3);
                        }
                    }
                    break;
                case 4:
                case 5:
                case 6:
                    game->heal(game->get_active_player(), rand() % 6);
                    break;
                case 7:
                case 8:
                case 9:
                    choice = rand() % 2;
                    if (choice == 0){
                            game->heal(target, 2);
                    }else {
                        game->heal(game->get_active_player(), 2);
                    }

                    break;
                case 10:
                case 11:
                case 12:
                    for (int player =0; player <game->get_number_player(); player++) {
                        if (game->get_player_location(player) == 2) {
                            game->add_wound(player,1);
                            game->heal(player, 2);
                        }
                    }
                    break;
                case 13:
                case 14:
                case 15:
                case 16:
                        game->heal(game->get_active_player(), 2);
                    break;

                default:
                    break;
            }
        }
    }

    int Darknlight::get_card_type() {
        return this->card_type;
    }

    void Darknlight::set_card_type(int type) {
        this->card_type = type;
    }

    void Darknlight::set_id(int id) {
        this->card_id = id;
    }

    bool Darknlight::is_equipment() {
        return this->is_equipped;
    }


}