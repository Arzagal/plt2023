#include <iostream>

// Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>

// Fin test SFML

#include <state.h>
#include "render/Display.h"

using namespace std;
using namespace state;

int main(int argc,char* argv[])
{
    /*Ceci est une version de démonstration non représentative du résultat final
     * Dans la version finale , le jeu lira les positions prédéfiniesdes cartes à partir d'un .txt
     * */
    sf::RenderWindow window(sf::VideoMode(600, 450), "Jeu de societe");


    sf::Sprite bg;
    sf::Texture myTexture;
    myTexture.loadFromFile("../ShadowHunter_Card/Board/Board-1.png");
    bg.setScale(400/myTexture.getSize().x,300/myTexture.getSize().x);
    sf::FloatRect bounds = bg.getLocalBounds();
    bg.setOrigin(bounds.width / 2, bounds.height / 2);
    bg.setPosition(300, 225);
    bg.setTexture(myTexture);
    render::Display display(window,  bg);
    //render::Const constants();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear();
        display.refresh();
    }
    return 0;
}
