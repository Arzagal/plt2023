#include "Player.h"
#include <iostream>
#include <vector>

int main() {
    std::vector<state::Player> players;

    for (int i = 0; i < 4; ++i) {
        players.push_back(state::Player());
    }

    // Affichage des caractéristiques initiales des personnages
    std::cout << "Caractéristiques initiales des personnages :" << std::endl;
    for (int i = 0; i < players.size(); ++i) {
        std::cout << "Joueur " << i + 1 << " - HP: " << players[i].get_hp() << ", Number: " << players[i].get_number() << std::endl;
    }

    // Effectuer des actions avec les personnages
    for (int i = 0; i < players.size(); ++i) {
        players[i].move();
    }

    players[1].attack(players[0]);
    players[2].equipe_card(state::Darknlight(/* Passer les paramètres nécessaires ici */));
    players[3].active_character_effect();

    // Affichage des caractéristiques après les actions
    std::cout << "\nCaractéristiques après les actions :" << std::endl;
    for (int i = 0; i < players.size(); ++i) {
        std::cout << "Joueur " << i + 1 << " - HP: " << players[i].get_hp() << ", Number: " << players[i].get_number() << std::endl;
    }

    return 0;
}
