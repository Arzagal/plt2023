#include <iostream>

// Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>

// Fin test SFML

#include <state.h>
#include <render/Display.h>
#include "engine/Engine.h"
#include <ai/RandomAi.h>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstring>
#include <thread>

using namespace std;
using namespace sf;

int main(int argc,char* argv[]){
    // ... [Unchanged code for initialization and setup] ...
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

    if(0 == strcmp(argv[1], "DemoRender")) {
        state::Game *game = new state::Game();
        render::Display display(window, bg, game);
        game->registerObserver(&display);
        game->add_player();
        game->add_player();
        game->add_player();
        game->start_game();
        game->get_Player_liste()[0]->set_character(state::Agnes);
        game->get_Player_liste()[1]->set_character(state::Allie);
        game->get_Player_liste()[2]->set_character(state::Emi);
        game->get_Player_liste()[3]->set_character(state::Franklin);

        state::Darknlight *equipCardL = new state::Darknlight(17, 0);

        state::Darknlight *equipCardD = new state::Darknlight(4, 1);

        game->get_Player_liste()[0]->equipe_card(equipCardL);
        game->get_Player_liste()[1]->equipe_card(equipCardL);
        game->get_Player_liste()[2]->equipe_card(equipCardL);
        game->get_Player_liste()[3]->equipe_card(equipCardL);

        game->get_Player_liste()[0]->equipe_card(equipCardD);
        game->get_Player_liste()[1]->equipe_card(equipCardD);
        game->get_Player_liste()[2]->equipe_card(equipCardD);
        game->get_Player_liste()[3]->equipe_card(equipCardD);

        engine::Engine engine(&display);
        engine.awaitUsrInput();
}
    else if(0 == strcmp(argv[1], "DemoIA")){
        state::Game *game = new state::Game();
        game->add_player();
        game->add_player();
        game->add_player();
        ai::RandomAi *ai1 = new ai::RandomAi(game, 0);
        ai::RandomAi *ai2 = new ai::RandomAi(game, 1);
        ai::RandomAi *ai3 = new ai::RandomAi(game, 2);
        ai::RandomAi *ai4 = new ai::RandomAi(game, 3);
        render::Display display(window, bg, game);
        game->registerObserver(&display);
        game->registerObserver(ai1);
        game->registerObserver(ai2);
        game->registerObserver(ai3);
        game->registerObserver(ai4);
        std::thread threadGame(&state::Game::start_game, game);
        while(window.isOpen()){
            sf::Event event;
            while (window.pollEvent(event)) {

                if (event.type == sf::Event::Closed) {
                    window.close();
                }
            }
        }
    }
    return 0;
}
