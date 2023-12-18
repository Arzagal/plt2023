#include "Game.h"
#include "Card.h"
#include "Teams.h"

namespace state {

    Game::Game() : playing(0), turn(0), player_number(0), board(nullptr), deckL(nullptr), deckD(nullptr), deckV(nullptr) {
    }

    void Game::add_player() {
        // Crée un nouveau joueur
        Player* newPlayer = new Player(playerListe.size() + 1);

        // Attribue un personnage non attribué au joueur
        Character defaultCharacter;
        do {
            defaultCharacter = static_cast<state::Character>(std::rand() % 20);
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
    }

    void Game::add_dmg(int target) {
    }

    Card* Game::draw(int card_type) {
        return nullptr;
    }

    State Game::get_state() {
        return state;
    }

    void Game::start_game() {
    }

    void Game::move_player(int player, int location) {
    }

    void Game::active_board_effect(int active_player) {
    }

    void Game::add_wound(int player, int value) {
    }

    void Game::heal(int player, int value) {
    }

    void Game::attack(int attacking, int attacked) {
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

}
