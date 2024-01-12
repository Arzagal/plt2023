#include "Vision.h"

namespace state {

    int Vision::last_assigned_id = 0;
    Vision::Vision() {
        card_id = ++last_assigned_id;
    }

    void Vision::choose_target(std::vector<Player*>& playerListe) {
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

    int Vision::get_id() {
        return card_id;
    }

    void Vision::activate_effect() {
        switch (card_id) {
        case 1:
            std::cout << "Vous avez piochez la carte Vision Réconfortante." << std::endl;
            if (targetPlayer != nullptr) {
                if (targetPlayer->get_team() == 2){
                    targetPlayer->set_hp(targetPlayer->get_hp() - 1);
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
                if (targetPlayer->get_team() == 0){
                    targetPlayer->set_hp(targetPlayer->get_hp() + 1);
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
                std::cout << "La carte character du joueur ciblé est : " << characterToString(targetPlayer->getCharacter()) << std::endl;
            }
            break;
        case 6:
            std::cout << "Vous avez piochez la carte Vision Enivrante." << std::endl;
            if (targetPlayer != nullptr) {
                if (targetPlayer->get_team() == 1 || targetPlayer->get_team() == 2 ){
                    targetPlayer->set_hp(targetPlayer->get_hp() - 1);
                    std::cout << "Le joueur visé subit 1 blessure." << std::endl;
                } else {
                    std::cout << "Il ne se passe rien" << std::endl;
                }
            }
            break;
        case 7:
            std::cout << "Vous avez piochez la carte Vision Cupide." << std::endl;
            if (targetPlayer != nullptr) {
                if (targetPlayer->get_team() == 0 || targetPlayer->get_team() == 2 ){
                    targetPlayer->set_hp(targetPlayer->get_hp() - 1);
                    std::cout << "Le joueur visé subit 1 blessure." << std::endl;
                } else {
                    std::cout << "Il ne se passe rien" << std::endl;
                }
            }
            break;
        case 8:
            std::cout << "Vous avez piochez la carte Vision Purificatrice." << std::endl;
            if (targetPlayer != nullptr) {
                if (targetPlayer->get_team() == 0){
                    targetPlayer->set_hp(targetPlayer->get_hp() - 2);
                    std::cout << "Le joueur visé subit 2 blessures." << std::endl;
                } else {
                    std::cout << "Il ne se passe rien" << std::endl;
                }
            }
            break;
        case 9:
            std::cout << "Vous avez piochez la carte Vision Mortifère." << std::endl;
            if (targetPlayer != nullptr) {
                if (targetPlayer->get_team() == 1){
                    targetPlayer->set_hp(targetPlayer->get_hp() - 1);
                    std::cout << "Le joueur visé subit 1 blessure." << std::endl;
                } else {
                    std::cout << "Il ne se passe rien" << std::endl;
                }
            }
            break;
        case 10:
            std::cout << "Vous avez piochez la carte Vision Foudroyante." << std::endl;
            if (targetPlayer != nullptr) {
                if (targetPlayer->get_team() == 0){
                    targetPlayer->set_hp(targetPlayer->get_hp() - 1);
                    std::cout << "Le joueur visé subit 1 blessure." << std::endl;
                } else {
                    std::cout << "Il ne se passe rien" << std::endl;
                }
            }
            break;
        case 11:
            std::cout << "Vous avez piochez la carte Vision Divine." << std::endl;
            if (targetPlayer != nullptr) {
                if (targetPlayer->get_team() == 1){
                    targetPlayer->set_hp(targetPlayer->get_hp() + 1);
                    std::cout << "Le joueur visé soigne 1 blessure." << std::endl;
                } else {
                    std::cout << "Il ne se passe rien" << std::endl;
                }
            }
            break;
        case 12:
            std::cout << "Vous avez piochez la carte Vision Furtive." << std::endl;
            if (targetPlayer != nullptr) {
                if (targetPlayer->get_team() == 1 || targetPlayer->get_team() == 0){
                    targetPlayer->set_hp(targetPlayer->get_hp() - 1);
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
