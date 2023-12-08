//
// Created by louis on 10/24/23.
//
#include "Player.h"

namespace state{
    Player::Player (int number){
        this->attackNumber = 1;
        this->revealed = false;
        this->number = number;
    }

    void Player::active_character_effect (){}

    void Player::reveal (){
        this->revealed = true;
    }

    int Player::get_hp (){
        return this->hp;
    }
    void Player::set_hp (int hp){
        this->hp = hp;
    }

    void Player::set_character (Character character){
        this->character = character;
    }

    int Player::get_number (){
        return this->number;
    }
    std::vector<Darknlight*> Player::get_equipped_card (){
        return this->equipped_card;
    }
    void Player::active_board_effect (){}

    void Player::equipe_card (Darknlight* card){
        this->equipped_card.push_back(card);
    }

    int Player::get_attack() {
        return this->attackNumber;
    }
}