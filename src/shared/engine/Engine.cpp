//
// Created by franzozich on 18/12/23.
//
#include "Engine.h"
#include "MoveCommand.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>
#include "render/ButtonPosition.h"

namespace engine{
    Engine::Engine(render::Display *myDisplay) {
        this->myDisplay=myDisplay;
        this->buttonClicked= false;
        /*clickThread = std::thread(&Engine::awaitUsrInput, this);
        clickThread.detach();*/
    }
    bool Engine::detectArea(float x, float y, float width, float height, float pointX, float pointY) {
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
    render::Display* Engine::get_display(){
        return this->myDisplay;
    }

    void Engine::handleClick(float x,float y) {

        std::vector<render::ButtonPosition> buttons = myDisplay->get_locations().get_buttons();
        std::vector<render::CardPosition> players = myDisplay->get_locations().get_characterCards();

        if (!buttonClicked) {
            int i;
            float rectWidth, rectHeight, rectX, rectY;
            rectWidth = buttons[0].get_width();
            rectHeight = buttons[0].get_height();

            for (i = 0; i < buttons.size(); i++) {
                rectX = buttons[i].getX();
                rectY = buttons[i].getY();


                if (detectArea(rectX, rectY, rectWidth, rectHeight, x, y)) {

                    std::cout << "Clicked on Button" << i << "\n";
                    break;
                }

            }
            engine::MoveCommand move;
            switch (i) {


                case 0://ATK
                    this->buttonClicked = true;
                    std::cout << "Atk mode" << "\n";
                    break;
                case 1://MOV
                    move.execute(this);
                    break;
                case 2://NEXT
                    break;
                default:
                    break;
            }
        } else {
            std::cout<<"Selecting target"<<"\n";
            int i;
            float rectWidth, rectHeight, rectX, rectY;
            rectWidth = myDisplay->get_locations().get_card_width();
            rectHeight = myDisplay->get_locations().get_card_height();

            for (i = 0; i < buttons.size(); i++) {
                 rectX=players[i].getPixelX();
                 rectY=players[i].getPixelY();


                if (detectArea(rectX, rectY, rectWidth, rectHeight, x, y)) {

                    std::cout << "Clicked on Player" << i << "\n";
                    break;
                }

            }
            this->buttonClicked= false;
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
                    //std::cout<<"mouse X at "<<mouseX<<"| mouse Y at "<<mouseY<<std::endl;
                    this->handleClick(mouseX,mouseY);
                }
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(2));
        }

    }
}