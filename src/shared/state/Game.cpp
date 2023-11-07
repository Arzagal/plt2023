//
// Created by louis on 10/24/23.
//
#include "Game.h"

namespace state{
    Game::Game (){}
    void Game::add_player (){}
    void Game::new_turn (){}
    void Game::add_dmg (int target){}
    void Game::draw (Card_type card_type){}
    State Game::get_state (){}
    void Game::start_game (){}
    void Game::move_player (Player player, int location){}
    void Game::active_board_effect (Player active_player){}
    void Game::add_wound (Player player, int value){}
    void Game::heal (Player player, int value){}
    void Game::attack (Player attacking, Player attacked){}
}