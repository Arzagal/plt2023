//
// Created by louis on 10/24/23.
//
#include "Game.h"
#include <iostream>
#include "algorithm"

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
        this->playing++;
        if(this->playing >= this->player_number){
            this->playing = 0;
        }
        this->turn++;
        if(!this->playerListe[this->playing]->is_alive()){
            this->new_turn();
        }
    }

    void Game::add_dmg (int target){
        this->damage_count[target]++;
    }

    Card* Game::draw (int card_type){
        this->state = Card_effect;
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
        this->actualCard = res;
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
        std::vector<state::Character> usedChara; //Keeping the already assigned characters,
        for(int j =0; j<this->player_number; j++){
            Player *player = new Player(j);
            this->playerListe.push_back(player);
            this->damage_count.push_back(0);
            state::Character testChara = static_cast<state::Character>(rand() % Vampire);
            while((std::find(usedChara.begin(), usedChara.end(), testChara))!=usedChara.end()){
                testChara = static_cast<state::Character>(rand() % Vampire);
            }
            player->set_character(testChara);
            usedChara.push_back(testChara);
        }
        this->next_state();
    }

    void Game::move_player (int player, int location){ //FIXME
        int trueloc = 0;
        switch(location){ // Go to the right location (depending on the dice value)
            case(2) : case(3) : trueloc = 0; break;
            case(4) : case(5): trueloc = 1; break;
            case(6) : case(7) : trueloc = 2; break;
            case(8) : trueloc = 3; break;
            case(9) : trueloc = 4; break;
            case(10) : trueloc = 5; break;
            default : std::cerr << "The movement should be the result of a d6 and d4 launch";
        }
        this->board->move_player(player, trueloc);
    }

    void Game::active_board_effect (int active_player){
        this->board->get_effect(this->board->get_location(active_player), this);
    }

    void Game::add_wound (int player, int value){
        this->damage_count[player] += value;
        if(this->damage_count[player]>14){this->damage_count[player] = 14;}
    }

    void Game::heal (int player, int value){
        this->damage_count[player] -= value;
        if(this->damage_count[player]<0){
            this->damage_count[player]=0;
        }
    }

    void Game::attack (int attacking, int attacked){
        if(this->state != Attack){
            std::cout << "It is not the attack phase ! \n";
        }
        int value = this->playerListe[attacking]->get_attack();
        this->damage_count[attacked] += value;
    }

    void Game::activate_card_effect(int target) {
        this->actualCard->activate_effect(target, this);
        this->actualCard = nullptr;
    }

    int Game::get_active_player() const {
        return this->playing;
    }

    int Game::get_number_player() const {
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

    std::vector<int> Game::get_neighbours(int playerNum) {
        return this->board->get_neighbours(playerNum);
    }

    void Game::next_state() {
        switch(this->state){
            case(Starting) :
                this->state = Playing;
                this->new_turn();
                break;
            case(Playing) :
                this->state = Move;
                break;
            case(Move) :
                this->state = Location_effect;
                break;
            case(Location_effect) :
                this->state = Card_effect;
                this->active_board_effect(this->playing);
            case(Card_effect) :
                this->state = Attack;
                break;
            case(Attack) :
                this->new_turn();
                break;
            case(Finished) :
                std::cerr << "Error : the game is already finished";
                break;
        }
        this->notifyObserver(this->state, this->playing);
    }

    void Game::did_someone_died() {
        for(Player* player : playerListe){
            if(player->is_alive()){
                if(damage_count[player->get_number()] >= player->get_hp()){

                }
            }
        }
    }
}