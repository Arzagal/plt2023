//
// Created by franzozich on 18/12/23.
//
#include "Engine.h"
#include "MoveCommand.h"
#include "NextCommand.h"
#include "AttackCommand.h"
#include <iostream>
#include <thread>
#include <chrono>

namespace engine {
    Engine::Engine(render::Display *myDisplay) {

        this->myDisplay = myDisplay;
        this->buttonClicked = false;

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

    render::Display *Engine::get_display() {
        return this->myDisplay;
    }

    state::State& Engine::getState (){
        return currentState;
    }
    void Engine::handleClick(float x, float y) {

        std::vector<render::ButtonPosition> buttons = myDisplay->get_locations().get_buttons();
        std::vector<render::CardPosition> players = myDisplay->get_locations().get_characterCards();

        if (!buttonClicked) {
            int i;
            float rectWidth, rectHeight, rectX, rectY;
            rectWidth = buttons[0].get_width();
            rectHeight = buttons[0].get_height();

            for (i = 0; i < (int)buttons.size(); i++) {
                rectX = buttons[i].getX();
                rectY = buttons[i].getY();

                if (detectArea(rectX, rectY, rectWidth, rectHeight, x, y)) {

                    std::cout << "Clicked on Button" << i << "\n";
                    break;
                }
            }
            engine::MoveCommand move;
            engine::NextCommand next;

            switch (i) {

                case 0://ATK
                    this->buttonClicked = true;
                    std::cout << "Atk mode" << "\n";
                    break;
                case 1://MOV
                    move.execute(this);
                    break;
                case 2://NEXT
                    next.execute(this);
                    break;

            }
        }
        else {
            std::cout << "Selecting target" << "\n";
            int i;
            float rectWidth, rectHeight, rectX, rectY;
            rectWidth = myDisplay->get_locations().get_card_width();
            rectHeight = myDisplay->get_locations().get_card_height();

            for (i = 0; i < (int)buttons.size(); i++) {
                rectX = players[i].getPixelX();
                rectY = players[i].getPixelY();

                if (detectArea(rectX, rectY, rectWidth, rectHeight, x, y)) {

                    std::cout << "Clicked on Player" << i << "\n";
                    break;
                }
                engine::AttackCommand atk(i);
                atk.execute(this);

            }
            this->buttonClicked = false;
        }
    }


    void Engine::awaitUsrInput() {

        while (myDisplay->getWindow()->isOpen()) {
            sf::Event event;
            while (myDisplay->getWindow()->pollEvent(event)) {

                if (event.type == sf::Event::Closed) {
                    myDisplay->getWindow()->close();
                }

                if (event.type == sf::Event::MouseButtonReleased) {
                    int mouseX = event.mouseButton.x;
                    int mouseY = event.mouseButton.y;
                    std::cout<<"mouse X"<<mouseX<<" mouse Y"<<mouseY<<"\n";
                    this->handleClick((float) mouseX, (float) mouseY);
                }
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(2));
        }
    }
}