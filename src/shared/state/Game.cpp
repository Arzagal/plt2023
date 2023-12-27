#include "Game.h"
#include "Board.h"
#include "Card.h"
#include "Teams.h"

#include <algorithm>
#include <random>

namespace state {

    Game::Game() : playing(0), turn(0), player_number(0), board(nullptr), deckL(nullptr), deckD(nullptr), deckV(nullptr) {
    }

    void Game::add_player(int team_min, int team_max) {
        // Crée un nouveau joueur
        Player* newPlayer = new Player(playerListe.size() + 1);

        // Attribue un personnage non attribué au joueur
        Character defaultCharacter;
        do {
            defaultCharacter = static_cast<state::Character>(std::rand() % team_max + team_min);
        } while (isCharacterAlreadyAssigned(defaultCharacter));

        newPlayer->set_character(defaultCharacter);

        // Vérifie le personnage attribué et détermine la team en conséquence
        if (defaultCharacter == Liche || defaultCharacter == Loup_Garou || defaultCharacter == Metamorphe || defaultCharacter == Momie || defaultCharacter == Valkyrie || defaultCharacter == Vampire) {
            newPlayer->set_team(Shadow);
        } 
        else if (defaultCharacter == Ellen || defaultCharacter == Emi || defaultCharacter == Franklin || defaultCharacter == Fu_ka || defaultCharacter == Georges || defaultCharacter == Gregor)  {
            newPlayer->set_team(Hunter);
        }else {
            newPlayer->set_team(Neutral);
        }

        // Vérifie le personnage attribué et lui attribu ses points de vie initiaux
        if (defaultCharacter == Georges || defaultCharacter == Gregor || defaultCharacter == Liche || defaultCharacter == Loup_Garou) {
            newPlayer->set_hp(14);
        } 
        else if (defaultCharacter == Daniel || defaultCharacter == David || defaultCharacter == Valkyrie || defaultCharacter == Vampire)  {
            newPlayer->set_hp(13);
        }else if (defaultCharacter == Franklin || defaultCharacter == Fu_ka)  {
            newPlayer->set_hp(12);
        } else if (defaultCharacter == Catherine || defaultCharacter == Charles || defaultCharacter == Metamorphe || defaultCharacter == Momie)  {
            newPlayer->set_hp(11);
        } else if (defaultCharacter == Ellen || defaultCharacter == Emi || defaultCharacter == Bob || defaultCharacter == Bryan)  {
            newPlayer->set_hp(10);
        } else {
            newPlayer->set_hp(8);
        }

        // Ajoute le joueur à la liste
        playerListe.push_back(newPlayer);
    }
    void Game::new_turn() {
        for (auto& player : playerListe) {
            bool sameArea = false;
            int target = 0;
            int choice;
            std::cout << "C'est au joueur " << player->get_number() << " de joueur." << std::endl;
            std::cout << "Vous avez appuyé sur la touche entrer pour lancer les dés et vous déplacer :";
            std::cin.ignore();
            move_player(player->get_number(), player->get_location());
            std::cout << "Pour activer l'effet de votre localisation taper 1 : ";
            std::cin >> choice;
            std::cin.ignore();
            if (choice == 1){
                player->active_board_effect(playerListe);
            }

            for (auto& Neighborplayer : playerListe) {
                if (Neighborplayer != player){
                    if (arePlayersAtSameLocation(player->get_location(), Neighborplayer->get_location())){
                        std::cout << "Le joueur " << Neighborplayer->get_number() << " est dans le même secteur que vous." << std::endl;
                        sameArea = true;
                    }
                }
            }
            if (sameArea){
                std::cout << "Des joueurs se trouvent dans votre zone qui voulez-vous attaquer ?\nEntrer le numéro du joueur que vous voulez attaquer : ";
                std::cin >> target;
                std::cin.ignore();
                if (target == 0){
                    std::cout << "Vous avez choisi de ne pas attaquer." << std::endl;
                }else{
                    attack(player->get_number(), target);
                }
            }
            

            std::cout << std::endl;
        }
    }

    void Game::add_dmg(int target) {
        int dmg = static_cast<state::Character>(std::rand() % 6);
        for (auto& player : playerListe) {
            if (player->get_number() == target) {
                player->set_hp(player->get_hp() - dmg);
                std::cout << dmg << " blessure(s) ont été infligé." << std::endl;
                break;
            }
        }
    }

    Card* Game::draw(int card_type) {
        return nullptr;
    }

    State Game::get_state() {
        return state;
    }

    void Game::start_game() {
        std::cout << "Bienvenue dans Shadow Hunter.\nLe jeu Shadow Hunter est un jeu à rôle caché qui se joue de 4 à 8 joueur.\nCombien de joueur vont jouer la partie ? ";
        //std::cin >> playing;
        //std::cin.ignore();
        std::cout << std::endl;
        playing = 4;

        if (playing == 4){
            for (int i=0; i<2; i++){
                add_player(8,6);
                add_player(14,6);
            }
        } else if (playing == 5){
            for (int i=0; i<2; i++){
                add_player(8,6);
                add_player(14,6);
            }
            add_player(0,8);
        }else if (playing == 6){
            for (int i=0; i<2; i++){
                add_player(8,6);
                add_player(14,6);
                add_player(0,8);
            }
        }else if (playing == 7){
            for (int i=0; i<3; i++){
                add_player(0,8);
            }
            for (int i=0; i<2; i++){
                add_player(8,6);
                add_player(14,6);
            }
        }else {
            for (int i=0; i<3; i++){
                add_player(8,6);
                add_player(14,6);
                add_player(0,8);
            }
        }

        for (auto& player : playerListe) {
            std::cout << "C'est au joueur numéro " << player->get_number() << " de découvrir son personnage.\nAppuyer sur Entrer pour voir votre personnage :";
            std::cin.ignore();
            std::cout << "\nPlayer " << player->get_number() << " HP: " << player->get_hp() << std::endl;
            std::cout << "Character: " << state::characterToString(player->getCharacter()) << std::endl;
            std::cout << "Teams: " << state::teamsToString(player->get_team()) << std::endl;
            std::cout << "Localisation : " << player->get_location() << std::endl;
            std::cout << "Appuyer sur Entrer pour passer au joueur suivant :";
            std::cin.ignore();
            std::cout << "\033[2J\033[H";
        }
        
    }

    void Game::move_player(int player_number, int location) {
        // Recherche du joueur dans la liste
        for (auto& player : playerListe) {
            if (player->get_number() == player_number) {
                // Définir la nouvelle localisation pour le joueur
                int new_location = static_cast<state::Character>(std::rand() % 9 + 2);
                while (new_location == location)
                {
                    new_location = static_cast<state::Character>(std::rand() % 9 + 2);
                }
                if (new_location == 7){
                    std::cout << "Vous avez fait 7 vous pouvez choisir n'importe quelle localisation : ";
                    std::cin >> new_location;
                    std::cin.ignore();
                }
                player->set_location(new_location);
                std::cout << "Vous êtes désormais à la localisation " << new_location << std::endl;        
                break;
            }
        }
    }

    void Game::active_board_effect(int active_player) {
    }

    void Game::add_wound(int player_number, int value) {
        for (auto& player : playerListe) {
            if (player->get_number() == player_number) {
                player->set_hp(player->get_hp() - value);
            }
            break;
        }
    }

    void Game::heal(int player, int value) {
        for (auto& player : playerListe) {
            if (player->get_number() == player_number) {
                player->set_hp(player->get_hp() + value);
            }
            break;
        }
    }

    void Game::attack(int attacking, int attacked) {
        auto attackerIt = std::find_if(playerListe.begin(), playerListe.end(),
            [attacking](const auto& player) {
                return player->get_number() == attacking;
            });

        auto attackedIt = std::find_if(playerListe.begin(), playerListe.end(),
            [attacked](const auto& player) {
                return player->get_number() == attacked;
            });

        if (attackerIt != playerListe.end() && attackedIt != playerListe.end()) {
            if (arePlayersAtSameLocation((*attackerIt)->get_location(), (*attackedIt)->get_location())) {
                add_dmg(attacked);
            } else {
                std::cout << "\nLes joueurs ne sont pas à la même localisation." << std::endl;
            }
        }

    }

    int Game::get_active_player() {
        return playing;
    }

    int Game::get_number_player() {
        return player_number;
    }

    int Game::get_wounds(int PlayerNum) {
        return 0;
    }

    std::vector<Player*> Game::get_Player_liste() {
        return playerListe;
    }

    int Game::get_player_location(int PlayerNum) {
        return 0;
    }

    bool Game::isCharacterAlreadyAssigned(Character character) const {
        for (const auto& player : playerListe) {
            if (player->getCharacter() == character) {
                return true; // Le personnage est déjà attribué à un joueur
            }
        }
        return false; // Le personnage n'est pas encore attribué
    }

    bool Game::arePlayersAtSameLocation(int location1, int location2) {

        if (location1 != -1 && location2 != -1) {
            if ((location1 == 2 || location1 == 3 || location1 == 6) && (location2 == 2 || location2 == 3 || location2 == 6)) {
                return true;
            } else if ((location1 == 4 || location1 == 5 || location1 == 10) && (location2 == 4 || location2 == 5 || location2 == 10)) {
                return true;
            } else if ((location1 == 8 || location1 == 9) && (location2 == 8 || location2 == 9)) {
                return true;
            }
        }

        return false;
    }

}
