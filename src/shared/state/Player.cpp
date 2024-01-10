#include "Player.h"

namespace state{
    Player::Player (int number){
        this->attackNumber = 1;
        this->revealed = false;
        this->isAlive = true;
        this->number = number;
        this->hp = 14;
    }

    void Player::active_character_effect (){}

    void Player::reveal (){
        this->revealed = true;
    }

    int Player::get_hp (){
        return this->hp;
    }
    void Player::set_hp (int HP){
        this->hp = HP;
    }

    void Player::set_character (Character characte){
        this->character = characte;
        switch(this->character){
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
            case(state::Allie) :
                return "Allie";
            case(state::Bob) :
                return "Bob";
            case(state::Bryan) :
                return "Bryan";
            case(state::Catherine) :
                return "Catherine";
            case(state::Charles) :
                return "Charles";
            case(state::Daniel) :
                return "Daniel";
            case(state::David) :
                return "David";
            case(state::Ellen) :
                return "Ellen";
            case(state::Emi) :
                return "Emi";
            case(state::Franklin) :
                return "Franklin";
            case(state::Fu_ka) :
                return "Fu_ka";
            case(state::Georges) :
                return "Georges";
            case(state::Gregor) :
                return "Gregor";
            case(state::Liche) :
                return "Liche";
            case(state::Loup_Garou) :
                return "Loup_garou";
            case(state::Metamorphe) :
                return "Metamorphe";
            case(state::Momie) :
                return "Momie";
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

    bool Player::is_alive() {
        return this->isAlive;
    }

    void Player::kill() {
        this->isAlive = false;
    }
}
