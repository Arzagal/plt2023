//
// Created by louis on 11/12/23.
//
#include "CardPosition.h"

namespace render{

    CardPosition::CardPosition(float X, float Y, float angle) {
        this->pixelX=X;
        this->pixelY=Y;
        this->angle=angle;
    }
    float CardPosition::getAngle() {
        return angle;
    }
    float CardPosition::getPixelX() {
        return pixelX;
    }
    float CardPosition::getPixelY() {
        return pixelY;
    }
    void CardPosition::setPixelX(float X) {
        this->pixelX=X;
    }
    void CardPosition::setPixelY(float Y) {
        this->pixelY=Y;
    }

}