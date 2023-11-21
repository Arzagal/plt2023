//
// Created by louis on 10/24/23.
//
#include "Game.h"

namespace state{
    Game::Game (){
        this->state = Starting;
        this->turn = 0;
        this->player_number = 1;
    }
    void Game::add_player (){
        this->player_number++;
    }
    void Game::new_turn (){
        this->state = Playing;
        this->playing++;
        if(this->playing >= this->player_number){
            this->playing = 0;
        }
    }
    void Game::add_dmg (int target){
    }
    Card Game::draw (Card_type card_type){}

    State Game::get_state (){
        return this->state;
    }

    void Game::start_game (){}

    void Game::move_player (int player, int location){
        this->playerListe[]
    }

    void Game::active_board_effect (int active_player){}

    void Game::add_wound (int player, int value){
        this->damage_count[player] += value;
    }

    void Game::heal (int player, int value){
        this->damage_count[player] -= value;
        if(this->damage_count[player]<0){
            this->damage_count[player]=0;
        }
    }

    void Game::attack (int attacking, int attacked){
        int value = this->playerListe[attacking].get_attack();
        this->damage_count[attacked] += value;
    }

    int Game::get_active_player() {
        return this->playing;
    }

    int Game::get_number_player() {
        return this->player_number;
    }

    int Game::get_wounds(int PlayerNum) {
        return this->damage_count[PlayerNum];
    }

    std::vector<Player> Game::get_Player_liste() {
        return this->playerListe;
    }

    int Game::get_player_location(int PlayerNum) {
//        return this->playerListe[PlayerNum];
    }
}