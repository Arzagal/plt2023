#include "Player.h"
#include "Character.h"
#include "Darknlight.h"
#include "Game.h"
#include "Teams.h"
#include <cstdlib>

namespace state {

    Player::Player(int number) : number(number), hp(hp), revealed(false), attackNumber(0) {
    }

    void Player::active_character_effect() {
    }

    void Player::reveal() {
        revealed = true;
    }

    int Player::get_hp() {
        return hp;
    }

    void Player::set_hp(int new_hp) {
        hp = new_hp;
    }

    void Player::set_character(Character new_character) {
        character = new_character;
    }

    int Player::get_number() {
        return number;
    }

    std::vector<Darknlight*> Player::get_equipped_card() {
        return equipped_card;
    }

    void Player::active_board_effect(std::vector<Player*>& playerListe) {
        switch(location) {
            case 2: 
                break;
            case 3: 
                break;
            case 4: 
                break;
            case 5: 
                break;
            case 6: 
                break;
            case 7: 
                break;
            case 8: 
                break;
            case 9: 
                int choice;
                int target;
                std::cout << "Vous pouvez infliger 2 blessures (taper 1) ou soigner 1 blessure (taper 2) à un joueur : ";
                std::cin >> choice;
                std::cout << "Rentrer le joueur visé : ";
                std::cin >> target;
                std::cin.ignore();
                if (choice == 1){
                    for (auto& player : playerListe) {
                        if (player->get_number() == target) {
                            player->set_hp(player->get_hp() - 2);
                            std::cout << "Vous avez infligé 2 blessures au joueur " << target << "." << std::endl;
                            break;
                        }
                    }
                }else {
                    for (auto& player : playerListe) {
                        if (player->get_number() == target) {
                            player->set_hp(player->get_hp() + 1);
                            std::cout << "Vous avez soigné 1 blessure   au joueur " << target << "." << std::endl;
                            break;
                        }
                    }
                }

                break;
            case 10: 
                break;

            default: break;
        }
    }

    void Player::equipe_card(Darknlight* card) {
        equipped_card.push_back(card);
    }

    int Player::get_attack() {
        return attackNumber;
    }

    bool Player::isrevealed() {
        return revealed;
    }

    Character Player::getCharacter() {
        return character;
    }

    void Player::set_team(Teams new_team) {
        team = new_team;
    }

    Teams Player::get_team() const {
        return team;
    }

    int Player::get_location() const {
        return location;
    }

    void Player::set_location(int new_location) {
        // Assurez-vous que la nouvelle localisation est dans la plage spécifiée (entre 2 et 10)
        if (new_location >= 2 && new_location <= 10) {
            location = new_location;
        } else {
            // Gérez l'erreur (vous pouvez afficher un message, lancer une exception, etc.)
            std::cerr << "Error: Invalid location. Location should be between 2 and 10." << std::endl;
        }
    }

}
