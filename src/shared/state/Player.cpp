//
// Created by louis on 10/24/23.
//
#include "Player.h"

#pragma clang diagnostic push
#pragma ide diagnostic ignored "UnreachableCode"
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
        switch(character){
        case Ellen : case Emi : case Franklin : case Fu_ka : case Georges : case Gregor :
            this->team = Hunter;
            break;
        case Liche : case Loup_Garou : case Metamorphe : case Momie : case Valkyrie : case Vampire :
            this->team = Shadow;
            break;
        default:
            this->team = Neutral;
            break;
        }
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

    std::string Player::getCharacter() {
        switch( this->character) {
            case (state::Agnes) :
                return "Agnes";
                break;
            case(state::Allie) :
                return "Allie";
                break;
            case(state::Bob) :
                return "Bob";
                break;
            case(state::Bryan) :
                return "Bryan";
                break;
            case(state::Catherine) :
                return "Catherine";
                break;
            case(state::Charles) :
                return "Charles";
                break;
            case(state::Daniel) :
                return "Daniel";
                break;
            case(state::David) :
                return "David";
                break;
            case(state::Ellen) :
                return "Ellen";
                break;
            case(state::Emi) :
                return "Emi";
                break;
            case(state::Franklin) :
                return "Franklin";
                break;
            case(state::Fu_ka) :
                return "Fu_ka";
                break;
            case(state::Georges) :
                return "Georges";
                break;
            case(state::Gregor) :
                return "Gregor";
                break;
            case(state::Liche) :
                return "Liche";
                break;
            case(state::Loup_Garou) :
                return "Loup_garou";
                break;
            case(state::Metamorphe) :
                return "Metamorphe";
                break;
            case(state::Momie) :
                return "Momie";
                break;
            case(state::Valkyrie) :
                return "Valkyrie";
            case(state::Vampire) :
                return "Vampire";
        }
        return "Error";
    }

    bool Player::isrevealed() {
        return this->revealed;
    }

    Teams Player::getTeams() {
        return this->team;
    }
}
#pragma clang diagnostic pop