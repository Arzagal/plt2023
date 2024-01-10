#include <render/Const.h>
#include <sstream>
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>

namespace render{

    Const::Const() {
        std::ifstream file("./ShadowHunter_Card/Consts");
        std::string line;
        int groupNum = 1;
        int playerNum = 1;
        int groupNum1 = 1;
        int playerNum1 = 1;

        this->cardWidth=200;
        this->cardHeight=300;

        while (getline(file, line)) {
            if (line == "Cartes") {
                while (getline(file, line) && !line.empty()) {
                    std::istringstream iss(line);
                    float pixelX, pixelY, angle;
                    iss >> pixelX >> pixelY >> angle;

                    cardsOnBoard.emplace_back(pixelX, pixelY, angle);
                }
            } else if (line == "Blessures") {

                std::vector<PlayerPosition> positions;
                while (getline(file, line) && !line.empty()) {
                    std::istringstream iss(line);
                    float pixelX, pixelY;
                    iss >> pixelX >> pixelY;
                    positions.emplace_back(pixelX, pixelY, playerNum);

                    if (playerNum == 4) {
                        woundLocations[groupNum] = positions;
                        positions.clear();
                        groupNum++;
                        playerNum = 0;
                    }
                    playerNum++;
                }
            } else if (line == "Joueurs") {

                std::vector<PlayerPosition> positions;
                groupNum = 1;
                playerNum = 1;
                while (getline(file, line) && !line.empty()) {
                    std::istringstream iss(line);
                    float pixelX, pixelY;
                    iss >> pixelX >> pixelY;
                    positions.emplace_back(pixelX, pixelY, playerNum);

                    if (playerNum == 4) {
                        playerOnBoard[groupNum] = positions;
                        positions.clear();
                        groupNum++;
                        playerNum = 0;
                    }
                    playerNum++;
                }
            }
            else if (line == "Personnages") {

                while (getline(file, line) && !line.empty()) {

                    std::istringstream iss(line);
                    float pixelX, pixelY, angle;
                    iss >> pixelX >> pixelY >> angle;

                    characterCards.emplace_back(pixelX, pixelY, angle);
                }
            }
            else if (line == "Equipements") {
                std::vector<CardPosition> positions;
                while (getline(file, line) && !line.empty()) {
                    std::istringstream iss(line);
                    float pixelX, pixelY,angle;
                    iss >> pixelX >> pixelY >> angle;
                    positions.emplace_back(pixelX, pixelY, angle);

                    if (playerNum1 == 4) {
                        equipmentCards[groupNum1] = positions;
                        positions.clear();
                        groupNum1++;
                        playerNum1 = 0;
                    }
                    playerNum1++;
                }
            }
            else if (line=="Boutons"){
                while (getline(file, line) && !line.empty()) {
                    std::istringstream iss(line);
                    float pixelX, pixelY;
                    iss >> pixelX >> pixelY ;
                    std::cout<<pixelX<<pixelY<<std::endl;
                    buttons.emplace_back(pixelX, pixelY);
                }

                for (int i=1;i<4;i++) {
                    buttons[i-1].setButton(i);
                    buttons[i-1].setHeight(85);
                    buttons[i-1].setWidth(85);


                }
            }
        }
        file.close();
    }

    float Const::get_card_height() {
        return this->cardHeight;
    }
    float Const::get_card_width() {
        return this->cardWidth;
    }
    std::map<int, std::vector<PlayerPosition>> Const::get_woundLocations() {
        return woundLocations;
    }
    std::map<int, std::vector<PlayerPosition>> Const::get_playerOnBoard() {
        return playerOnBoard;
    }
    std::vector<CardPosition> Const::get_cardsOnBoard() {
        return cardsOnBoard;
    }
    std::vector<CardPosition> Const::get_characterCards() {
        return characterCards;
    }
    std::map<int,std::vector<CardPosition>> Const::get_equipmentCards() {
        return equipmentCards;
    }
    std::vector<ButtonPosition> Const::get_buttons() {
        return buttons;
    }
    

}