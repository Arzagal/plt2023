#include "classe.h"

int main() {
    int canAttack;
    int target;

    std::vector<Player> players = {
        Player("John", 15, false, 10),
        Player("Edward", 15, false, 3),
        Player("Pierre", 15, false, 5),
        Player("Mike", 15, false, 2),
        Player("Dave", 15, false, 7),
    };

    while (true) {
        int alivePlayers = 0;
        int alivePlayerIndex;

        for (int i = 0; i < 5; i++) {
            if (!players[i].isDead()) {
                alivePlayers++;
                alivePlayerIndex = i;
            }
        }

        if (alivePlayers == 1) {
            std::cout << "Le joueur " << alivePlayerIndex + 1 << " a survécu. Fin du jeu." << std::endl;
            break;
        }

        for (int i = 0; i < 5; i++) {
            if (!players[i].isDead()) {

                std::cout << "C'est au tour du joueur numéro " << i + 1 << " de jouer." << std::endl;
                canAttack = 0;
                players[i].displayHealth();
                players[i].move();
                std::cout << "Voulez-vous vous relever ?" << std::endl;

                for (int j = 0; j < 5; j++) {
                    if (!players[j].isDead() && arePlayersInSameSecteur(players[i], players[j]) && i != j) {
                        std::cout << "Les joueurs " << i + 1 << " et " << j + 1 << " sont dans le même secteur." << std::endl;
                        canAttack = 1;
                    }
                }

                if (canAttack == 1) {
                    std::cout << "Choisissez une personne à attaquer parmi celles qui sont dans votre secteur : ";
                    std::cin >> target;

                    if (target >= 1 && target <= 5 && target != (i + 1) && !players[target - 1].isDead()) {
                        players[i].attackPlayer(players[target - 1]);
                    } else {
                        std::cout << "Attaque invalide ou vous avez choisi de ne pas attaquer." << std::endl;
                    }
                } else {
                    std::cout << "Il n'y a personne dans votre secteur, vous ne pouvez pas attaquer." << std::endl;
                }

                std::cout << "\n" << std::endl;
            }
        }
    }

    for (int i = 0; i < 5; i++) {
        players[i].displayInfo();
        std::cout << "\n" << std::endl;
    }

    return 0;
}
