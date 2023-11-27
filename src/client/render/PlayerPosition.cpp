//
// Created by louis on 11/12/23.
//
#include "PlayerPosition.h"

namespace render{
    PlayerPosition::PlayerPosition(float X, float Y, int playerNum) {
        this->pixelX = X;
        this->pixelY = Y;
        this->playerNum = playerNum;
    }

    int PlayerPosition::getPlayerNum() {
        return this->playerNum;
    }

    float PlayerPosition::getPixelX() {
        return this->pixelX;
    }

    float PlayerPosition::getPixelY() {
        return this->pixelY;
    }

    sf::Vector2f PlayerPosition::get_position() {
        sf::Vector2f res = sf::Vector2f(this->pixelX, this->pixelY);
        return res;
    }
}