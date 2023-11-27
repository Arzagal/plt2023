//
// Created by louis on 11/12/23.
//
#include "CardPosition.h"

namespace render{

    sf::Vector2f CardPosition::get_position() {
        sf::Vector2f res = sf::Vector2f(this->pixelX, this->pixelY);
        return res;
    }

    float CardPosition::getAngle() {
        return this->angle;
    }

    float CardPosition::getpixelX() {
        return this->pixelX;
    }

    float CardPosition::getpixelY() {
        return this->pixelY;
    }

    CardPosition::CardPosition(float X, float Y, float angle) {
        this->pixelX = X;
        this->pixelY = Y;
        this->angle = angle;
    }
}