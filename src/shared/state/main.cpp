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
    auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::srand(static_cast<unsigned int>(seed));

    state::Game game;

    game.start_game();

    // Accès à la liste des joueurs depuis l'instance de la classe Game
    std::vector<state::Player*> players = game.get_Player_liste();

    // Continuez le jeu jusqu'à ce que tous les chasseurs ou toutes les ombres soient morts
    while (!game.areAllHuntersDead() && !game.areAllShadowsDead()) {
        game.new_turn();

        for(int i=0; i<game.get_active_player(); i++){
            std::cout << "\nPlayer " << players[i]->get_number() << " HP: " << players[i]->get_hp() << std::endl;
            std::cout << "Character: " << state::characterToString(players[i]->getCharacter()) << std::endl;
            std::cout << "Teams: " << state::teamsToString(players[i]->get_team()) << std::endl;
            std::cout << "Localisation : " << players[i]->get_location() << std::endl;
        }

        std::cout << "Appuyer sur Entrer pour passer au joueur suivant :";
        std::cin.ignore();
        std::cout << "\033[2J\033[H";

        // Ajoutez toute autre logique ou sortie que vous souhaitez entre les tours

        // Vérifiez l'état des chasseurs et des ombres après chaque tour
        if (game.areAllHuntersDead()) {
            std::cout << "Tous les chasseurs sont morts. Les ombres gagnent !" << std::endl;
            break;
        } else if (game.areAllShadowsDead()) {
            std::cout << "Toutes les ombres sont mortes. Les chasseurs gagnent !" << std::endl;
            break;
        }
    }

    for(int i=0; i<game.get_active_player(); i++){
        std::cout << "\nPlayer " << players[i]->get_number() << " HP: " << players[i]->get_hp() << std::endl;
        std::cout << "Character: " << state::characterToString(players[i]->getCharacter()) << std::endl;
        std::cout << "Teams: " << state::teamsToString(players[i]->get_team()) << std::endl;
        std::cout << "Localisation : " << players[i]->get_location() << std::endl;
    }

    return 0;
}
