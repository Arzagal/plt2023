//
// Created by franzozich on 13/11/23.
//
#include <render/Display.h>

namespace render {

    Display::Display(sf::RenderWindow &win, sf::Sprite bg)
            : window(&win), background(bg) {
        this->gameState=new state::Game();
        this->background=bg;
    }

    state::Game *Display::getGameState() {
        return gameState;
    }
    /*Ceci ne correspond pas au fonctionnement fnal de la méthode refresh()
     * dans sa version finale elle sera appelée à intervalles réguliers
     *
     *
     *
     * */
    void Display::refresh(){
        //window->close();
        window->draw(background);
        window->display();
    }

}

