#include "Game.h"
#include "Player.h"
#include "Character.h"

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <vector>

#define PLAYER_NUMBER 20

int main() {
    // Initialise srand en fonction de l'horloge
    auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::srand(static_cast<unsigned int>(seed));

    state::Game game;

    // Ajoute joueur
    for (int i = 0; i < PLAYER_NUMBER; ++i) {
        game.add_player();
    }

    // Accède à la liste des joueurs depuis l'instance de la classe Game
    std::vector<state::Player*> players = game.get_Player_liste();

    // Affiche les informations sur les joueurs
    for (int i = 0; i < PLAYER_NUMBER; ++i) {
        std::cout << "Player " << players[i]->get_number() << " HP: " << players[i]->get_hp() << std::endl;
        std::cout << "Character: " << state::characterToString(players[i]->getCharacter()) << std::endl;
        std::cout << "Teams: " << state::teamsToString(players[i]->get_team()) << std::endl;
    }

    return 0;
}
