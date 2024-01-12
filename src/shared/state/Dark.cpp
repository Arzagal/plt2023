#include "Dark.h"

namespace state {

    int Dark::last_assigned_id = 0;

    Dark::Dark() {
        card_id = ++last_assigned_id;
    }

    void Dark::choose_target(std::vector<Player*>& playerListe) {
        int targetNumber;
        std::cout << "Choisissez le numéro du joueur cible : ";
        std::cin >> targetNumber;
        std::cin.ignore();

        auto targetIt = std::find_if(playerListe.begin(), playerListe.end(),
            [targetNumber](const auto& player) {
                return player->get_number() == targetNumber;
            });

        if (targetIt != playerListe.end()) {
            targetPlayer = *targetIt;
            std::cout << "Vous avez choisi le joueur " << targetNumber << " comme cible." << std::endl;
        } else {
            std::cout << "Numéro de joueur invalide." << std::endl;
            // Gérez l'erreur comme vous le souhaitez
        }
    }

    int Dark::get_id() {
        return card_id;
    }

    void Dark::activate_effect(std::vector<Player*>& playerListe, int active_player) {
        // Implémentez la logique d'activation de l'effet pour la classe Dark
        int alea;
        int choice;
        switch (card_id) {
        case 1:
            std::cout << "Vous avez piochez la carte Dynamite." << std::endl;
            alea = static_cast<state::Character>(std::rand() % 9 + 2);
            std::cout << "Le resultat du lancé est : " << alea << "." << std::endl;
            std::cout << "Effet spécial : Infliger 3 points de dégâts à tous les joueurs à la localisation 3." << std::endl;
            for (auto& player : playerListe) {
                if (player->get_location() == alea) {
                    player->set_hp(player->get_hp() - 3);
                    std::cout << "3 points de dégâts infligés au joueur " << player->get_number() << "." << std::endl;
                }
            }
            break;
        case 2:
        case 3:
            std::cout << "Vous avez pioché la carte Chauve-Souris Vampire." << std::endl;
            choose_target(playerListe);
            if (targetPlayer != nullptr) {
                targetPlayer->set_hp(targetPlayer->get_hp() - 2);
                std::cout << "Vous infligez 2 points de dégâts au joueur " << targetPlayer->get_number() << "." << std::endl;
                // Vous pouvez également infliger 2 points de dégâts au joueur qui a pioché la carte
                playerListe[active_player]->set_hp(playerListe[active_player]->get_hp() + 2);
                std::cout << "Vous vous êtes soigné de 2 points de vie en piochant la carte." << std::endl;
            }
            break;
        case 4:
        case 5:
            std::cout << "Vous avez pioché la carte Quite ou Double." << std::endl;
            choose_target(playerListe);
            choice = static_cast<state::Character>(std::rand() % 2);
            if (choice == 0){
                if (targetPlayer != nullptr) {
                    targetPlayer->set_hp(targetPlayer->get_hp() - 5);
                    std::cout << "Vous infligez 2 points de dégâts au joueur " << targetPlayer->get_number() << "." << std::endl;
                }
            }else {
                playerListe[active_player]->set_hp(playerListe[active_player]->get_hp() - 5);
                std::cout << "Vous vous êtes soigné de 2 points de vie en piochant la carte." << std::endl;
            }
            
            break;
        case 6:
        case 7:
            std::cout << "Vous avez piochez la carte Rituel Diabolique." << std::endl;
            std::cout << "Si vous vous révèlez et qui vous êtes un Shadow vous pouvez soigner toutes vos blessurs.\nSi voulez vous vous révèler taper 1 : ";
            std::cin >> choice;
            std::cin.ignore();
            if (choice == 1){
                if (active_player == 2) {
                    if(playerListe[1]->getCharacter() == Momie || playerListe[1]->getCharacter() == Metamorphe){
                        playerListe[1]->set_hp(11);
                    }else if(playerListe[1]->getCharacter() == Valkyrie || playerListe[1]->getCharacter() == Vampire){
                        playerListe[1]->set_hp(13);
                    }else if(playerListe[1]->getCharacter() == Liche || playerListe[1]->getCharacter() == Loup_Garou){
                        playerListe[1]->set_hp(14);
                    }
                }else if (active_player == 4){
                    if(playerListe[3]->getCharacter() == Momie || playerListe[3]->getCharacter() == Metamorphe){
                        playerListe[3]->set_hp(11);
                    }else if(playerListe[3]->getCharacter() == Valkyrie || playerListe[3]->getCharacter() == Vampire){
                        playerListe[3]->set_hp(13);
                    }else if(playerListe[3]->getCharacter() == Liche || playerListe[3]->getCharacter() == Loup_Garou){
                        playerListe[3]->set_hp(14);
                    }
                } else {
                    std::cout << "Il" << std::endl;
                }
            }else {
                std::cout << "Vous avez choisi de ne pas vous reveler." << std::endl;
            }
            break;
        case 8:
            std::cout << "Vous avez piochez la carte Mitrailleuse Funeste." << std::endl;
            std::cout << "Effet spécial : Infliger 1 point de dégât à tous les joueurs à la localisation 8." << std::endl;
            for (auto& player : playerListe) {
                if (player->get_location() == 8) {
                    player->set_hp(player->get_hp() - 1);
                    std::cout << "1 point de dégât infligé au joueur " << player->get_number() << "." << std::endl;
                }
            }
            break;
        case 9:
        case 10:
            std::cout << "Vous avez piochez la carte Mitrailleuse Funeste." << std::endl;
            std::cout << "Effet spécial : Infliger 1 point de dégât à tous les joueurs à la localisation 8." << std::endl;
            for (auto& player : playerListe) {
                if (player->get_location() == 8) {
                    player->set_hp(player->get_hp() - 1);
                    std::cout << "1 point de dégât infligé au joueur " << player->get_number() << "." << std::endl;
                }
            }
        case 11:
        case 12:
            std::cout << "Vous avez piochez la carte Poupée Démoniaque." << std::endl;
            choose_target(playerListe);
            if (targetPlayer != nullptr) {
                targetPlayer->set_hp(targetPlayer->get_hp() - 2);
                std::cout << "Vous infligez 2 points de dégâts au joueur " << targetPlayer->get_number() << "." << std::endl;
            }
            break;
        
        default:
            break;
        }
    }

}

