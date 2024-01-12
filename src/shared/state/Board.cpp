#include "Board.h"

namespace state {

    Board::Board(int len) {
    }

    void Board::random_init() {
    }

    void Board::move_player(int player, int location) {
    }

    std::vector<int> Board::get_neighbours(int player) {
        return std::vector<int>();
    }

    void Board::get_effect(int location) {
    }

    int Board::get_location(int player) {
        return 0;
    }

    void Board::active_board_effect(int active_player, DeckVision* deckV, DeckDark* deckD, std::vector<Player*>& playerListe, int location) {
        // Piocher une carte du deck
        Vision* drawnCard = nullptr;
        Dark* drawnCardDark = nullptr;
        switch(location) {
            case 2:
            case 3: 
                drawnCard = deckV->draw();
                if (drawnCard != nullptr) {
                    std::cout << "ID de la carte est : " << drawnCard->get_id() << std::endl;
                    drawnCard->choose_target(playerListe);
                    drawnCard->activate_effect();
                    delete drawnCard; // Assurez-vous de libérer la mémoire
                }
                break;
            case 4:
            case 5: 
                int i;
                std::cout << "Vous pouvez piocher le type de carte que vous voulez (Vision : 1, Dark : 2, Light : 3).\nEntrer le type de carte que vous voulez : ";
                std::cin >> i;
                std::cin.ignore();
                if (i == 1){
                    drawnCard = deckV->draw();
                    if (drawnCard != nullptr) {
                        std::cout << "ID de la carte est : " << drawnCard->get_id() << std::endl;
                        drawnCard->choose_target(playerListe);
                        drawnCard->activate_effect();
                        delete drawnCard; // Assurez-vous de libérer la mémoire
                    }
                }else if (i == 2){
                    drawnCardDark = deckD->draw();
                    if (drawnCardDark != nullptr) {
                        std::cout << "ID de la carte est : " << drawnCardDark->get_id() << std::endl;
                        drawnCardDark->activate_effect(playerListe, active_player);
                        delete drawnCardDark; // Assurez-vous de libérer la mémoire
                    }
                }else {
                    //Effect LightCard
                }
                break;
            case 6: 
                break;
            case 8: 
                drawnCardDark = deckD->draw();
                if (drawnCardDark != nullptr) {
                    std::cout << "ID de la carte est : " << drawnCardDark->get_id() << std::endl;
                    drawnCardDark->activate_effect(playerListe, active_player);
                    delete drawnCardDark; // Assurez-vous de libérer la mémoire
                }
                break;
            case 9: 
                int choice;
                int target;
                std::cout << "Vous pouvez infliger 2 blessures (taper 1) ou soigner 1 blessure (taper 2) à un joueur : ";
                std::cin >> choice;
                std::cout << "Rentrer le joueur visé : ";
                std::cin >> target;
                std::cin.ignore();
                if (choice == 1){
                    for (auto& player : playerListe) {
                        if (player->get_number() == target) {
                            player->set_hp(player->get_hp() - 2);
                            std::cout << "Vous avez infligé 2 blessures au joueur " << target << "." << std::endl;
                            break;
                        }
                    }
                }else {
                    for (auto& player : playerListe) {
                        if (player->get_number() == target) {
                            player->set_hp(player->get_hp() + 1);
                            std::cout << "Vous avez soigné 1 blessure   au joueur " << target << "." << std::endl;
                            break;
                        }
                    }
                }
                break;
            case 10: 
                break;

            default: break;
        }
    }

}
