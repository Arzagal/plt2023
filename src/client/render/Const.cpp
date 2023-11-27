//
// Created by franzozich on 13/11/23.
//
#include <render/Const.h>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iostream>
#include <map>
#include <vector>
#include <string>

namespace render{

    Const::Const() {
        std::ifstream file("../Consts");
        if (!file.is_open()) {
            std::cerr << "Error opening file: ../Consts" << std::endl;
             // or handle error appropriately
        }

        // Perform file reading operations here...

        // Check for other I/O errors
        if (file.bad()) {
            std::cerr << "I/O error while reading" << std::endl;
            // Handle error
        }
        if (file.eof()) {
            std::cerr << "End of file reached unexpectedly" << std::endl;
            // Handle error
        }
        if (file.fail()) {
            std::cerr << "Non-IO error occurred" << std::endl;
            // Handle error
        }
        std::string line;
        int groupNum = 1;
        int playerNum = 1;

        while (getline(file, line)) {
            std::cout<<line<<std::endl;
            if (line == "Cartes") {
                std::cout<<"into Cartes"<<std::endl;
                while (getline(file, line) && !line.empty()) {
                    std::cout<<"into the while"<<std::endl;
                    std::istringstream iss(line);
                    float pixelX, pixelY, angle;
                    iss >> pixelX >> pixelY >> angle;
                    std::cout<<"checking vars"<<std::endl;
                    std::cout<<pixelX<<pixelY<<angle<<std::endl;
                    std::cout<<"checking vars"<<std::endl;
                    cardsOnBoard.emplace_back(pixelX, pixelY, angle);
                }
            } else if (line == "Blessures") {
                std::cout<<"into Blessures"<<std::endl;
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
                std::cout<<"into Joueurs"<<std::endl;
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
        }
    }
    void Const::printContents() {
        std::cout << "Contents of woundLocations:\n";
        for (const auto& pair : woundLocations) {
            std::cout << "Key: " << pair.first << " - Values: ";
            for (PlayerPosition playerPos : pair.second) {
                std::cout << "Player " << playerPos.getPlayerNum() << " at ["
                          << playerPos.getPixelX() << ", " << playerPos.getPixelY() << "] ";
            }
            std::cout << "\n";
        }

        std::cout << "\nContents of playerOnBoard:\n";
        for (const auto& pair : playerOnBoard) {
            std::cout << "Key: " << pair.first << " - Values: ";
            for (PlayerPosition playerPos : pair.second) {
                std::cout << "Player " << playerPos.getPlayerNum() << " at ["
                          << playerPos.getPixelX() << ", " << playerPos.getPixelY() << "] ";
            }
            std::cout << "\n";
        }

        std::cout << "\nContents of cardsOnBoard:\n";
        for (CardPosition cardPos : cardsOnBoard) {
            std::cout << "Card at [" << cardPos.getPixelX() << ", "
                      << cardPos.getPixelY() << "] with angle " << cardPos.getAngle() << " ";
        }
        std::cout << "\n";
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


}