//
// Created by franzozich on 18/12/23.
//
#include "Engine.h"

#include <iostream>
#include <thread>
#include <chrono>
#include "render/ButtonPosition.h"

namespace engine{
    Engine::Engine(render::Display *myDisplay) {
        this->myDisplay=myDisplay;
        /*clickThread = std::thread(&Engine::awaitUsrInput, this);
        clickThread.detach();*/
    }
    bool Engine::thisButton(float x, float y, float width, float height, float pointX, float pointY) {
        float halfWidth = width / 2.0f;
        float halfHeight = height / 2.0f;

        // Calculate the left, right, top, and bottom edges of the rectangle
        float left = x - halfWidth;
        float right = x + halfWidth;
        float top = y - halfHeight;
        float bottom = y + halfHeight;

        // Check if the point is within the bounds of the rectangle
        if (pointX >= left && pointX <= right && pointY >= top && pointY <= bottom) {
            return true; // The point is inside the rectangle
        }

        return false;
    }

    void Engine::handleClick(int x,int y) {
        std::vector<render::ButtonPosition> temp=myDisplay->get_locations().get_buttons();
        int i;
        float rectWidth,rectHeight,rectX,rectY;
        rectWidth=temp[0].get_width();
        rectHeight=temp[0].get_height();

        for (i= 0; i < temp.size(); i++) {
            rectX=temp[i].getX();
            rectY=temp[i].getY();
            if (thisButton(rectX,rectY,rectWidth,rectHeight,x,y)){
                break;
            }
        }
    }


    void Engine::awaitUsrInput() {

        while (myDisplay->getWindow()->isOpen()) {
            sf::Event event;
            while (myDisplay->getWindow()->pollEvent(event)) {

                if (event.type == sf::Event::Closed) {
                    myDisplay->getWindow()->close();
                }
                if (event.type == sf::Event::KeyPressed) {
                    switch (event.key.code) {

                        case sf::Keyboard::Space:

                            myDisplay->getGameState()->add_wound(0, rand() % 3);
                            myDisplay->getGameState()->move_player(0, rand() % 9 +2);
                            myDisplay->getGameState()->add_wound(1, rand() % 3);
                            myDisplay->getGameState()->move_player(1, rand() % 9 +2);
                            myDisplay->getGameState()->add_wound(2, rand() % 3);
                            myDisplay->getGameState()->move_player(2, rand() % 9 +2);
                            myDisplay->getGameState()->add_wound(3, rand() % 3);
                            myDisplay->getGameState()->move_player(3, rand() % 9 +2);
                            if(rand()%6 == 5 ){myDisplay->getGameState()->get_Player_liste()[0]->reveal();}
                            if(rand()%6 == 5 ){myDisplay->getGameState()->get_Player_liste()[1]->reveal();}
                            if(rand()%6 == 5 ){myDisplay->getGameState()->get_Player_liste()[2]->reveal();}
                            if(rand()%6 == 5 ){myDisplay->getGameState()->get_Player_liste()[3]->reveal();}


                            break;
                        default:
                            break;
                    }
                    myDisplay->getGameState()->notifyObserver(myDisplay->getGameState()->get_state(), myDisplay->getGameState()->get_active_player());
                }
                if (event.type==sf::Event::MouseButtonReleased){
                    int mouseX = event.mouseButton.x;
                    int mouseY = event.mouseButton.y;
                    std::cout<<"mouse X at "<<mouseX<<"| mouse Y at "<<mouseY<<std::endl;
                    this->handleClick(mouseX,mouseY);
                }
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(2));
        }

    }
}