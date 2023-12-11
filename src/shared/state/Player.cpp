// Include necessary headers
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include "Character.h"
#include "Darknlight.h"

namespace state {

    Player::Player()
        : hp(0), revealed(false), number(0) {}

    void Player::move() {
        auto seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::srand(static_cast<unsigned int>(seed));

        int previousSecteur = number;
        int newSecteur;

        do {
            newSecteur = std::rand() % 9 + 2;

            std::cout << character << " a lancé un dé et est maintenant dans le secteur : " << newSecteur << std::endl;

        } while (newSecteur == previousSecteur);

        number = newSecteur;
    }

    void Player::attack(Player target) {
        auto seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::srand(static_cast<unsigned int>(seed));

        int damage = std::rand() % 10;

        target.set_hp(target.get_hp() - damage);

        std::cout << character << " a infligé " << damage << " points de dégâts!" << std::endl;
    }

    void Player::active_character_effect() {
    }

    void Player::show_character_effect() {
    }

    void Player::reveal() {
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

    std::vector<Darknlight> Player::get_equipped_card() {
        return equipped_card;
    }

    void Player::active_board_effect() {
    }

    void Player::equipe_card(Darknlight card) {
        equipped_card.push_back(card);
    }

}
