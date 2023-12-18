#include "Player.h"
#include "Character.h"
#include "Darknlight.h"
#include "Teams.h"
#include <cstdlib>

namespace state {

    Player::Player(int number) : number(number), hp(std::rand() % 5 + 11), revealed(false), attackNumber(0) {
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

    void Player::active_board_effect() {
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

}
