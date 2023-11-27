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
    /*// ... [Unchanged code for initialization and setup] ...
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Jeu de societe",sf::Style::Fullscreen);
    sf::Texture cardText;
    sf::Sprite cardSprite;

    sf::Texture redPawnText;
    sf::Texture greenPawnText;
    sf::Texture bluePawnText;
    sf::Texture purplePawnText;



    redPawnText.loadFromFile("../ShadowHunter_Card/Board/Pawn_red.png");
    greenPawnText.loadFromFile("../ShadowHunter_Card/Board/Pawn_green.png");
    bluePawnText.loadFromFile("../ShadowHunter_Card/Board/Pawn_blue.png");
    purplePawnText.loadFromFile("../ShadowHunter_Card/Board/Pawn_purple.png");

    redPawnSprite.setTexture(redPawnText);
    greenPawnSprite.setTexture(greenPawnText);
    bluePawnSprite.setTexture(bluePawnText);
    purplePawnSprite.setTexture(purplePawnText);

    cardText.loadFromFile("../ShadowHunter_Card/Light_Card/Light_Card_1.png");

    sf::Sprite bg;
    sf::Texture myTexture;
    myTexture.loadFromFile("../ShadowHunter_Card/Board/Board-1.png");
    cardSprite.setTexture(cardText);
    bg.setTexture(myTexture);
    sf::Vector2f cardVect=sf::Vector2f (200,230);
    sf::Vector2f pawnVect=sf::Vector2f (40,40);

    cardSprite.setScale(cardVect.x/cardText.getSize().x,cardVect.y/cardText.getSize().y);
    redPawnSprite.setScale(pawnVect.x/redPawnText.getSize().x,pawnVect.y/redPawnText.getSize().y);
    greenPawnSprite.setScale(pawnVect.x/redPawnText.getSize().x,pawnVect.y/redPawnText.getSize().y);
    bluePawnSprite.setScale(pawnVect.x/redPawnText.getSize().x,pawnVect.y/redPawnText.getSize().y);
    purplePawnSprite.setScale(pawnVect.x/redPawnText.getSize().x,pawnVect.y/redPawnText.getSize().y);

    sf::Vector2f myVect=sf::Vector2f (1366,768);
    bg.setScale(myVect.x/myTexture.getSize().x,myVect.y/myTexture.getSize().y);
    sf::FloatRect bounds = bg.getLocalBounds();
    cardSprite.setOrigin(bounds.width / 2, bounds.height / 2);
    bg.setOrigin(bounds.width / 2, bounds.height / 2);
    bg.setPosition(950, 500);

    sf::FloatRect cardBounds = cardSprite.getLocalBounds();
    cardSprite.setOrigin(cardBounds.width / 2, cardBounds.height / 2);


    cardSprite.setPosition(1230,280);
    sf::FloatRect redBounds =redPawnSprite.getLocalBounds();
    redPawnSprite.setOrigin(redBounds.width/2, redBounds.height/2);
    sf::FloatRect greenBounds =greenPawnSprite.getLocalBounds();
    greenPawnSprite.setOrigin(greenBounds.width/2, greenBounds.height/2);
    sf::FloatRect blueBounds =bluePawnSprite.getLocalBounds();
    bluePawnSprite.setOrigin(blueBounds.width/2, blueBounds.height/2);
    sf::FloatRect purpleBounds =purplePawnSprite.getLocalBounds();
    purplePawnSprite.setOrigin(purpleBounds.width/2, purpleBounds.height/2);

    setPawns(300,300,30);

    render::Display display(window,  bg);
    float movementStep = 10.0f;  // Define the movement step size

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::KeyPressed) {
                switch(event.key.code) {
                    case sf::Keyboard::Z: movePawns(0, -movementStep); break;
                    case sf::Keyboard::Q: movePawns(-movementStep, 0); break;
                    case sf::Keyboard::S: movePawns(0, movementStep); break;
                    case sf::Keyboard::D: movePawns(movementStep, 0); break;
                    default: break;
                }
            }
            display.refresh();
            window.draw(cardSprite);
            window.draw(redPawnSprite);
            window.draw(bluePawnSprite);
            window.draw(greenPawnSprite);
            window.draw(purplePawnSprite);
            //window.display();
            window.display();
        }

        // ... [Unchanged code for rendering] ...
    }*/
    render::Const myConst;
    myConst.printContents();
    while (1){

    }
    return 0;
}
