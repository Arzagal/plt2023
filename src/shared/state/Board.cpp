#include <algorithm>
#include "Board.h"
namespace state {
    Board::Board(int len) {
        this->player_location = std::vector<int>();
        for(int i = 0; i <len; i++){
            this->player_location.push_back(rand()%6);
        }
    }

    void Board::random_init() { //TODO

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
        std::vector<int> res;
        if(i == 0 || i ==1){
            for(int j =0; j < (int)this->player_location.size(); j++){
                if(j != player && (j == 0 || j == 1)){
                    res.push_back(j);
                }
            }
        }
        else if(i == 2 || i ==3){
            for(int j =0; j < (int)this->player_location.size(); j++){
                if(j != player && (j == 2 || j == 3)){
                    res.push_back(j);
                }
            }
        }
        else if(i == 4 || i ==5){
            for(int j =0; j < (int)this->player_location.size(); j++){
                if(j != player && (j == 4 || j == 5)){
                    res.push_back(j);
                }
            }
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

    bool Board::are_neighbours(int first_player, int second_player) {
        std::vector<int> neigh_first = this->get_neighbours(first_player);
        if(std::find(neigh_first.begin(), neigh_first.end(),second_player) != neigh_first.end()){
            return true;
        }
        return false;
    }
}
