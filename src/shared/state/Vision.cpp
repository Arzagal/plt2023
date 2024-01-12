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
                std::cout << "Vous avez piochez la carte Vision Réconfortante." << std::endl;
                if (targetPlayer != nullptr) {
                    if (targetPlayer->getTeams() == 2){
                        game->add_wound(target, 1);
                        std::cout << "Le joueur visé subit 1 blessure." << std::endl;
                    } else {
                        std::cout << "Il ne se passe rien" << std::endl;
                    }
                }
                break;
            case 2:
            case 3:
                std::cout << "Vous avez piochez la carte Vision Lugubre." << std::endl;
                if (targetPlayer != nullptr) {
                    if (targetPlayer->getTeams() == 0){
                        game->add_wound(target, 1);
                        std::cout << "Le joueur visé soigne 1 blessure." << std::endl;
                    } else {
                        std::cout << "Il ne se passe rien" << std::endl;
                    }
                }
                break;
            case 4:
            case 5:
                std::cout << "Vous avez piochez la carte Vision Suprême." << std::endl;
                if (targetPlayer != nullptr) {
                    std::cout << "La carte character du joueur ciblé est : " << targetPlayer->getCharacter() << std::endl;
                }
                break;
            case 6:
                std::cout << "Vous avez piochez la carte Vision Enivrante." << std::endl;
                if (targetPlayer != nullptr) {
                    if (targetPlayer->getTeams() == 1 || targetPlayer->getTeams() == 2 ){
                        game->add_wound(target, 1);
                        std::cout << "Le joueur visé subit 1 blessure." << std::endl;
                    } else {
                        std::cout << "Il ne se passe rien" << std::endl;
                    }
                }
                break;
            case 7:
                std::cout << "Vous avez piochez la carte Vision Cupide." << std::endl;
                if (targetPlayer != nullptr) {
                    if (targetPlayer->getTeams() == 0 || targetPlayer->getTeams() == 2 ){
                        game->add_wound(target, 1);
                        std::cout << "Le joueur visé subit 1 blessure." << std::endl;
                    } else {
                        std::cout << "Il ne se passe rien" << std::endl;
                    }
                }
                break;
            case 8:
                std::cout << "Vous avez piochez la carte Vision Purificatrice." << std::endl;
                if (targetPlayer != nullptr) {
                    if (targetPlayer->getTeams() == 0){
                        game->add_wound(target, 2);
                        std::cout << "Le joueur visé subit 2 blessures." << std::endl;
                    } else {
                        std::cout << "Il ne se passe rien" << std::endl;
                    }
                }
                break;
            case 9:
                std::cout << "Vous avez piochez la carte Vision Mortifère." << std::endl;
                if (targetPlayer != nullptr) {
                    if (targetPlayer->getTeams() == 1){
                        game->add_wound(target, 1);
                        std::cout << "Le joueur visé subit 1 blessure." << std::endl;
                    } else {
                        std::cout << "Il ne se passe rien" << std::endl;
                    }
                }
                break;
            case 10:
                std::cout << "Vous avez piochez la carte Vision Foudroyante." << std::endl;
                if (targetPlayer != nullptr) {
                    if (targetPlayer->getTeams() == 0){
                        game->add_wound(target, 1);
                        std::cout << "Le joueur visé subit 1 blessure." << std::endl;
                    } else {
                        std::cout << "Il ne se passe rien" << std::endl;
                    }
                }
                break;
            case 11:
                std::cout << "Vous avez piochez la carte Vision Divine." << std::endl;
                if (targetPlayer != nullptr) {
                    if (targetPlayer->getTeams() == 1){
                        game->heal(target, 1);
                        std::cout << "Le joueur visé soigne 1 blessure." << std::endl;
                    } else {
                        std::cout << "Il ne se passe rien" << std::endl;
                    }
                }
                break;
            case 12:
                std::cout << "Vous avez piochez la carte Vision Furtive." << std::endl;
                if (targetPlayer != nullptr) {
                    if (targetPlayer->getTeams() == 1 || targetPlayer->getTeams() == 0){
                        game->add_wound(target, 1);
                        std::cout << "Le joueur visé subit 1 blessure." << std::endl;
                    } else {
                        std::cout << "Il ne se passe rien" << std::endl;
                    }
                }
                break;

            default:
                break;
        }
    }
}