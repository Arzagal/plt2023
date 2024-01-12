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
                    std::cout << "Vous avez piochez la carte Dynamite." << std::endl;
                    alea = rand() % 6;
                    std::cout << "Le resultat du lancé est : " << alea << "." << std::endl;
                    std::cout << "Effet spécial : Infliger 3 points de dégâts à tous les joueurs à la localisation 3." << std::endl;
                    for (int player =0; player < game->get_number_player(); player++) {
                        if (game->get_player_location(player) == alea) {
                            game->add_wound(player, 3);
                            std::cout << "3 points de dégâts infligés au joueur " << player << "." << std::endl;
                        }
                    }
                    break;
                case 2:
                case 3:
                    std::cout << "Vous avez pioché la carte Chauve-Souris Vampire." << std::endl;
                    if (target != NULL) {
                        game->add_wound(target, 2);
                        std::cout << "Vous infligez 2 points de dégâts au joueur " << target << "." << std::endl;
                        // Vous pouvez également infliger 2 points de dégâts au joueur qui a pioché la carte
                        game->heal(game->get_active_player(), 2);
                        std::cout << "Vous vous êtes soigné de 2 points de vie en piochant la carte." << std::endl;
                    }
                    break;
                case 4:
                case 5:
                    std::cout << "Vous avez pioché la carte Quitte ou Double." << std::endl;
                    choice = rand() % 2;
                    if (choice == 0){
                            game->add_wound(target, 5);
                            std::cout << "Vous infligez 2 points de dégâts au joueur " << target<< "." << std::endl;
                    }else {
                        game->add_wound(game->get_active_player(), 5);
                        std::cout << "Vous vous êtes soigné de 2 points de vie en piochant la carte." << std::endl;
                    }

                    break;
                case 6:
                case 7:
                case 8: case 10:
                    std::cout << "Vous avez piochez la carte Mitrailleuse Funeste." << std::endl;
                    std::cout << "Effet spécial : Infliger 1 point de dégât à tous les joueurs à la localisation 8." << std::endl;
                    for (int player =0; player <game->get_number_player(); player++) {
                        if (game->get_player_location(player) == 3) {
                            game->add_wound(player,1);
                            std::cout << "1 point de dégât infligé au joueur " << player << "." << std::endl;
                        }
                    }
                    break;
                case 9:
                case 11:
                case 12:
                    std::cout << "Vous avez piochez la carte Poupée Démoniaque." << std::endl;
                        game->add_wound(target, 2);
                        std::cout << "Vous infligez 2 points de dégâts au joueur " << target << "." << std::endl;
                    break;

                default:
                    break;
            }
            }
        else if(this->card_type == 0){
            game->heal(target, 1);
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