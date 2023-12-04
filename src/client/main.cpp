#include <iostream>

// Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>

// Fin test SFML

#include <state.h>
#include <render/Display.h>

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

Sprite redPawnSprite;
Sprite greenPawnSprite;
Sprite bluePawnSprite;
Sprite purplePawnSprite;

void setPawns(float x, float y, float offset){
    redPawnSprite.setPosition(x,y);
    greenPawnSprite.setPosition(x+offset,y);
    bluePawnSprite.setPosition(x+2*offset,y);
    purplePawnSprite.setPosition(x+3*offset,y);
}

void movePawns(float dx, float dy){
    redPawnSprite.move(dx, dy);
    greenPawnSprite.move(dx, dy);
    bluePawnSprite.move(dx, dy);
    purplePawnSprite.move(dx, dy);

    // Output the coordinates of each pawn
    cout << "Red Pawn: (" << redPawnSprite.getPosition().x << ", " << redPawnSprite.getPosition().y << ")\n";
    cout << "Green Pawn: (" << greenPawnSprite.getPosition().x << ", " << greenPawnSprite.getPosition().y << ")\n";
    cout << "Blue Pawn: (" << bluePawnSprite.getPosition().x << ", " << bluePawnSprite.getPosition().y << ")\n";
    cout << "Purple Pawn: (" << purplePawnSprite.getPosition().x << ", " << purplePawnSprite.getPosition().y << ")\n";
}

int main(int argc,char* argv[]){
    // ... [Unchanged code for initialization and setup] ...
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Jeu de societe",sf::Style::Fullscreen);
    sf::Sprite bg;
    sf::Texture myTexture;
    myTexture.loadFromFile("../ShadowHunter_Card/Board/Board-1.png");
    bg.setTexture(myTexture);
    sf::Vector2f myVect=sf::Vector2f (1366,768);
    bg.setScale(myVect.x/myTexture.getSize().x,myVect.y/myTexture.getSize().y);
    sf::FloatRect bounds = bg.getLocalBounds();
    bg.setOrigin(bounds.width / 2, bounds.height / 2);
    bg.setPosition(950, 500);


    render::Display display(window,  bg);
    float movementStep = 10.0f;  // Define the movement step size
    display.getGameState()->add_player();
    display.getGameState()->add_player();
    display.getGameState()->add_player();
    display.getGameState()->start_game();
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::KeyPressed) {
                switch(event.key.code) {
                    case sf::Keyboard::Space: ; break;
                    default: break;
                }
            }
            display.refresh();
        }

        // ... [Unchanged code for rendering] ...
    }
//    render::Const myConst;
//    myConst.printContents();

    return 0;
}
