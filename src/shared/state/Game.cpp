//
// Created by louis on 10/24/23.
//
#include "Game.h"

namespace state{
    Game::Game () : Observable(){
        this->state = Starting;
        this->turn = 0;
        this->player_number = 1;
        this->damage_count = std::vector<int>();
    }

    void Game::add_player (){
        if(this->state == Starting) {
            this->player_number++;
        }
    }

    void Game::new_turn (){
        this->state = Playing;
        this->playing++;
        if(this->playing >= this->player_number){
            this->playing = 0;
        }
        this->turn++;
        this->notifyObserver(this->state);
    }

    void Game::add_dmg (int target){
        this->damage_count[target]++;
        this->notifyObserver(this->state);
    }

    Card* Game::draw (int card_type){
        Card* res;
        if(card_type == DARK){
            res = this->deckD->draw();
        }
        else if(card_type == LIGHT){
            res = this->deckL->draw();
        }
        else if(card_type == VISION){
            res = this->deckV->draw();
        }
        else{
            res = nullptr;
        }
        this->notifyObserver(this->state);
        return res;
    }

    State Game::get_state (){
        return this->state;
    }

    void Game::start_game (){
        this->deckL = new DeckLight();
        this->deckV = new DeckVision();
        this->deckD = new DeckDark();
        this->board = new Board(player_number);
        for(int j =0; j<this->player_number; j++){
            Player *player = new Player(j);
            this->playerListe.push_back(player);
            this->damage_count.push_back(0);
//            player.set_character();
        }
        this->state = Playing;
        this->notifyObserver(this->state);
    }

    void Game::move_player (int player, int location){
        this->board->move_player(player, location);
        this->notifyObserver(this->state);
    }

    void Game::active_board_effect (int active_player){
        this->board->get_effect(this->board->get_location(active_player));
        this->notifyObserver(this->state);
    }

    void Game::add_wound (int player, int value){
        this->damage_count[player] += value;
        if(this->damage_count[player]>14){this->damage_count[player] = 14;}
        this->notifyObserver(this->state);
    }

    void Game::heal (int player, int value){
        this->damage_count[player] -= value;
        if(this->damage_count[player]<0){
            this->damage_count[player]=0;
        }
        this->notifyObserver(this->state);
    }

    void Game::attack (int attacking, int attacked){
        int value = this->playerListe[attacking]->get_attack();
        this->damage_count[attacked] += value;
        this->notifyObserver(this->state);
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

    std::vector<Player*> Game::get_Player_liste() {
        return this->playerListe;
    }

    int Game::get_player_location(int PlayerNum) {
        return this->board->get_location(PlayerNum);
    }
}