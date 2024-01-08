#include <iostream>

// Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>

// Fin test SFML

#include <state.h>
#include "engine/Engine.h"
#include <render/Display.h>

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

int main(int argc,char* argv[]){
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
    engine::Engine myEngine(&display);
    while (true){
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    return 0;
}
