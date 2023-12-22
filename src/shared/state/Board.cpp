//
// Created by louis on 10/24/23.
//
#include <algorithm>
#include "Board.h"
namespace state {
    Board::Board(int len) {
        this->player_location = std::vector<int>();
        for(int i = 0; i <len; i++){
            this->player_location.push_back(0);
        }
    }

    void Board::random_init() {

        for(int i = 0; i< static_cast<int>(this->player_location.size()); i++){
            int loc = rand()%6;
            while(this->player_location[loc]!=0){
                loc = rand()%6;
            }
            this->player_location[loc] = i;
        }
    }

    void Board::move_player(int player, int location) {
        this->player_location[player] = location;
    }

    std::vector <int> Board::get_neighbours(int player) {
        int i = this->get_location(player);
        std::vector<int>::iterator it;
        it = std::find(this->player_location.begin(), this->player_location.end(), i);

        std::vector <int> res;
        while (it !=this->player_location.end()){
            res.push_back(it - this->player_location.begin());
            it = std::find(it+1, this->player_location.end(), i);
        }
        return res;
    }

    void Board::get_effect(int location, Game* game) {
        if(location == 0 || location==1){
            game->draw(0);
        }
        else if(location == 2 || location==3){
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
}
