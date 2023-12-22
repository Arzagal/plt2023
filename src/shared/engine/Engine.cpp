//
// Created by franzozich on 18/12/23.
//
#include "Engine.h"

#include <iostream>
#include <thread>
#include <chrono>
#include "../../client/render/ButtonPosition.h"

namespace engine{
    Engine::Engine(render::Display *myDisplay) {
        this->myDisplay=myDisplay;
        clickThread = std::thread(&Engine::awaitUsrInput, this);
        clickThread.detach();
    }
    void Engine::handleClick(int x,int y) {
        //std::vector<render::ButtonPosition> temp=myWindow->
    }

    void Engine::awaitUsrInput() {
        while (true){
            if (myDisplay->getWindow()->isOpen()){
                sf::Event event;
                while (myDisplay->getWindow()->pollEvent(event)){
                    if (event.type==sf::Event::MouseButtonReleased){
                        int mouseX = event.mouseButton.x;
                        int mouseY = event.mouseButton.y;
                        this->handleClick(mouseX,mouseY);
                    }
                }
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }

    }
}