//
// Created by louis on 11/12/23.
//
#include "CardPosition.h"

namespace render{
    CardPosition::CardPosition(float X, float Y, float angle) {
        this->pixelX = X;
        this->pixelY = Y;
        this->angle = angle;
    }

    float CardPosition::get_angle() {
        return this->angle;
    }

    float CardPosition::get_pixelX() {
        return this->pixelX;
    }

    float CardPosition::get_pixelY() {
        return this->pixelY;
    }

    void CardPosition::set_angle(float angle) {
        this->angle = angle;
    }

    void CardPosition::set_pixelX(float X) {
        this->pixelX = X;
    }

    void CardPosition::set_pixelY(float Y) {
        this->pixelY = Y;
    }
}