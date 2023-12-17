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

    void CardPosition::setAngle(float angle) {
        this->angle = angle;
    }

    sf::Vector2f CardPosition::get_position() {
        sf::Vector2f res = sf::Vector2f(this->pixelX, this->pixelY);
        return res;
    }

}