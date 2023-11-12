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

    int PlayerPosition::get_playerNum() {
        return this->playerNum;
    }

    float PlayerPosition::get_pixelX() {
        return this->pixelX;
    }

    float PlayerPosition::get_pixelY() {
        return this->pixelY;
    }

    void PlayerPosition::set_playerNum(int playerNum) {
        this->playerNum = playerNum;
    }

    void PlayerPosition::set_pixelX(float X) {
        this->pixelX = X;
    }

    void PlayerPosition::set_pixelY(float Y) {
        this->pixelY = Y;
    }
}