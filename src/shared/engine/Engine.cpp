//
// Created by franzozich on 18/12/23.
//
#include "Engine.h"
#include "../../client/render/Display.h"

namespace engine{
    Engine::Engine(sf::RenderWindow *myWindow) {
        this->myWindow=myWindow;
    }

    void Engine::awaitUsrInput() {
        sf::RenderWindow window(sf::VideoMode(1920, 1080), "Jeu de societe",sf::Style::Fullscreen);
        sf::Sprite bg;
        sf::Texture myTexture;
        myTexture.loadFromFile("./ShadowHunter_Card/Board/Board-1.png");
        bg.setTexture(myTexture);
        sf::Vector2f myVect=sf::Vector2f (1366,768);
        bg.setScale(myVect.x/myTexture.getSize().x,myVect.y/myTexture.getSize().y);
        sf::FloatRect bounds = bg.getLocalBounds();
        bg.setOrigin(bounds.width / 2, bounds.height / 2);
        bg.setPosition(950, 500);

        state::Game *game = new state::Game();
        render::Display display(window,  bg, game);
        float movementStep = 10.0f;  // Define the movement step size
        display.getGameState()->add_player();
        display.getGameState()->add_player();
        display.getGameState()->add_player();
        display.getGameState()->start_game();
        display.getGameState()->get_Player_liste()[0]->set_character(state::Agnes);
        display.getGameState()->get_Player_liste()[1]->set_character(state::Allie);
        display.getGameState()->get_Player_liste()[2]->set_character(state::Emi);
        display.getGameState()->get_Player_liste()[3]->set_character(state::Franklin);

        state::Darknlight * equipCardL = new state::Darknlight;
        equipCardL->set_card_type(0);
        equipCardL->set_id(17);

        state::Darknlight * equipCardD = new state::Darknlight;
        equipCardD->set_card_type(1);
        equipCardD->set_id(4);

        display.getGameState()->get_Player_liste()[0]->equipe_card(equipCardL);
        display.getGameState()->get_Player_liste()[1]->equipe_card(equipCardL);
        display.getGameState()->get_Player_liste()[2]->equipe_card(equipCardL);
        display.getGameState()->get_Player_liste()[3]->equipe_card(equipCardL);

        display.getGameState()->get_Player_liste()[0]->equipe_card(equipCardD);
        display.getGameState()->get_Player_liste()[1]->equipe_card(equipCardD);
        display.getGameState()->get_Player_liste()[2]->equipe_card(equipCardD);
        display.getGameState()->get_Player_liste()[3]->equipe_card(equipCardD);
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }


                if (event.type == sf::Event::KeyPressed) {
                    switch (event.key.code) {
                        case sf::Keyboard::Space:
                            display.getGameState()->add_wound(0, rand() % 3);
                            display.getGameState()->move_player(0, rand() % 6);
                            display.getGameState()->add_wound(1, rand() % 3);
                            display.getGameState()->move_player(1, rand() % 6);
                            display.getGameState()->add_wound(2, rand() % 3);
                            display.getGameState()->move_player(2, rand() % 6);
                            display.getGameState()->add_wound(3, rand() % 3);
                            display.getGameState()->move_player(3, rand() % 6);
                            if(rand()%6 == 5 ){display.getGameState()->get_Player_liste()[0]->reveal();}
                            if(rand()%6 == 5 ){display.getGameState()->get_Player_liste()[1]->reveal();}
                            if(rand()%6 == 5 ){display.getGameState()->get_Player_liste()[2]->reveal();}
                            if(rand()%6 == 5 ){display.getGameState()->get_Player_liste()[3]->reveal();}
                            break;
                        default:
                            break;
                    }
                }
                display.refresh();
            }
        }
    }
}