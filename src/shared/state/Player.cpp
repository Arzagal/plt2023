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
        if (new_location >= 2 && new_location <= 10 || new_location == 0) {
            location = new_location;
        } else {
            // Gérez l'erreur (vous pouvez afficher un message, lancer une exception, etc.)
            std::cerr << "Error: Invalid location. Location should be between 2 and 10." << std::endl;
        }
    }

}
