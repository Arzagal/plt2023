#include <algorithm>
#include <chrono>
#include <random>
#include <iostream>
#include "Board.h"
namespace state {
    Board::Board(int len) {
        this->player_location = std::vector<int>();
        for(int i = 0; i <len; i++){
            unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
            std::default_random_engine randomness(seed);
            std::uniform_int_distribution<int> distribution(0, 6-1);
            // Generate a random integer.
            int randomInt = distribution(randomness);
            this->player_location.push_back(randomInt);
        }
        this->random_init();
    }

    void Board::random_init() {
        for(int i =0; i<6; i++){
            unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
            srand(seed);
            std::default_random_engine randomness(seed);
            std::uniform_int_distribution<int> distribution(0, 6-1);
            // Generate a random integer.
            int randomInt = rand()%6;

            while(std::find(lineup.begin(), lineup.end(), randomInt) != lineup.end()){
                seed = std::chrono::system_clock::now().time_since_epoch().count();
                std::default_random_engine randomness2(seed);
                randomInt = rand()%6;
            }
            lineup.push_back(randomInt);
            std::cout << "Placed Card number " << randomInt << std::endl;
        }
    }

    void Board::move_player(int player, int location) {
        this->player_location[player] = location;
    }

    std::vector <int> Board::get_neighbours(int player) {
        int i = this->get_location(player);
        std::vector<int> res;
        if(i == 0 || i ==1){
            for(int j =0; j < (int)this->player_location.size(); j++){
                if(j != player && (player_location[j] == 0 || player_location[j] == 1)){
                    res.push_back(j);
                }
            }
        }
        else if(i == 2 || i ==3){
            for(int j =0; j < (int)this->player_location.size(); j++){
                if(j != player && (player_location[j] == 2 || player_location[j] == 3)){
                    res.push_back(j);
                }
            }
        }
        else if(i == 4 || i ==5){
            for(int j =0; j < (int)this->player_location.size(); j++){
                if(j != player && (player_location[j] == 4 || player_location[j] == 5)){
                    res.push_back(j);
                }
            }
        }
        return res;
    }

    void Board::get_effect(int location, Game* game) {
        int card = lineup[location];
        if(card == 0 || card==1){
            game->draw(0);
        }
        else if(card == 2 || card==3){
            game->draw(1);
        }
        else{
            game->draw(2);
        }
    }

    int Board::get_location(int player) {
        int res = this->player_location[player];
        return res;
    }

    bool Board::are_neighbours(int first_player, int second_player) {
        std::vector<int> neigh_first = this->get_neighbours(first_player);
        if(std::find(neigh_first.begin(), neigh_first.end(),second_player) != neigh_first.end()){
            return true;
        }
        return false;
    }
}
