//
// Created by louis on 10/24/23.
//
#include "Player.h"

namespace state{
    Player::Player ( ){}
    void Player::move (){}
    void Player::attack (int target){}
    void Player::active_character_effect (){}
    void Player::show_character_effect (){}
    void Player::reveal (){}
    int Player::get_hp (){}
    void Player::set_hp (int hp){}

    void Player::set_character (Character character){}
    int Player::get_number (){}
    std::vector<Darknlight> Player::get_equipped_card (){}
    void Player::active_board_effect (){}

    void Player::equipe_card (Darknlight card){}

}