//
// Created by louis on 10/24/23.
//
#include <algorithm>
#include "Board.h"
namespace state {
    Board::Board() {
        int i =0;
    }
    void Board::random_init() {
        int i;
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

    void Board::get_effect(int location) {
        int i;
    }

    int Board::get_location(int player) {
        int res = this->player_location[player];
        return res;
    }
}
