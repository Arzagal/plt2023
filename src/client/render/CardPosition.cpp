//
// Created by louis on 11/12/23.
//
#include "CardPosition.h"

namespace render{

    float CardPosition::getAngle() {
        return angle;
    }
    float CardPosition::getPixelX() {
        return pixelX;
    }
    float CardPosition::getpixelY() {
        return pixelY;
    }
    void CardPosition::setPixelX(float X) {
        this->pixelX=X;
    }
    void CardPosition::setPixelY(float Y) {
        this->pixelY=Y;
    }

}