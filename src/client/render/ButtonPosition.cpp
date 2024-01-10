#include "ButtonPosition.h"
namespace render{
    ButtonPosition::ButtonPosition(float x, float y) {
        this->x=x;
        this->y=y;


    }

    sf::Vector2f ButtonPosition::get_position() {
        return sf::Vector2f (this->x,this->y);

    }
    sf::Vector2f ButtonPosition::get_size() {
        return sf::Vector2f (this->width,this->height);
    }
    void ButtonPosition::setButton(int button) {
        this->buttonType=button;
    }
    float ButtonPosition::getX(){
        return this->x;
    }
    float ButtonPosition::getY() {
        return this->y;
    }
    int ButtonPosition::getType() {
        return this->buttonType;
    }
    void ButtonPosition::setHeight(float height) {
        this->height=height;
    }
    void ButtonPosition::setWidth(float width) {
        this->width=width;
    }
    float ButtonPosition::get_height() {
        return this->height;
    }
    float ButtonPosition::get_width() {
        return this->width;
    }
}