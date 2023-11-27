//
// Created by louis on 11/12/23.
//
#include "PlayerPosition.h"

namespace render{
    PlayerPosition::PlayerPosition(float X, float Y, float num) {
        this->pixelX=X;
        this->pixelY=Y;
        this->playerNum=num;
    }

    void PlayerPosition::setPixelY(float Y) {
        this->pixelY=Y;
    }
    void PlayerPosition::setPixelX(float X) {
        this->pixelX=X;
    }
    void PlayerPosition::setPlayerNum(int num) {
        this->playerNum=num;
    }
    float PlayerPosition::getPixelX() {
        return this->pixelX;
    }
    float PlayerPosition::getPixelY() {
        return this->pixelY;
    }
    int PlayerPosition::getPlayerNum() {
        return this->playerNum;
    }
}