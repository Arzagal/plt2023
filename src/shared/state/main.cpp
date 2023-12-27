#include "Game.h"
#include "Board.h"
#include "Player.h"
#include "Character.h"

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <vector>

int main() {
    // Initialise srand en fonction de l'horloge
    auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::srand(static_cast<unsigned int>(seed));

    state::Game game;

    game.start_game();

    // Accède à la liste des joueurs depuis l'instance de la classe Game
    std::vector<state::Player*> players = game.get_Player_liste();

    game.new_turn();

    game.add_wound(1,2);

    for(int i=0; i<game.get_active_player(); i++){
        std::cout << "\nPlayer " << players[i]->get_number() << " HP: " << players[i]->get_hp() << std::endl;
        std::cout << "Character: " << state::characterToString(players[i]->getCharacter()) << std::endl;
        std::cout << "Teams: " << state::teamsToString(players[i]->get_team()) << std::endl;
        std::cout << "Localisation : " << players[i]->get_location() << std::endl;
    }

    return 0;
}
