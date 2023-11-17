//
// Created by franzozich on 13/11/23.
//
#include <render/Display.h>

namespace render {

    Display::Display(sf::RenderWindow &win, sf::Sprite bg)
            : window(&win), background(bg) {
        this->gameState=new state::Game();
        this->background=bg;
    }

    state::Game *Display::getGameState() {
        return gameState;
    }
    /*Ceci ne correspond pas au fonctionnement fnal de la méthode refresh()
     * dans sa version finale elle sera appelée à intervalles réguliers
     *
     *
     *
     * */
    void Display::refresh(){
        window->clear();
        window->draw(background);
        window->display();
    }

    sf::Texture Display::getCardImg(int cardId) {

    }

    void Display::draw_wounds(int PlayerNum) {
        sf::Texture pawnTexture;
        sf::Sprite pawnSprite;
        sf::Vector2f size = sf::Vector2f(10,10);

        pawnTexture.loadFromFile("../ShadowHunter_Card/Board/Pawn" + std::to_string(PlayerNum) + ".png");
        pawnSprite.setTexture(pawnTexture);
        sf::Vector2f position = myLocations.get_woundLocations().at(gameState->get_wounds(PlayerNum))[PlayerNum].get_position();
        // Redimensionnez le sprite du plateau en fonction de la taille souhaitée
        pawnSprite.setScale(size.x / pawnTexture.getSize().x, size.y / pawnTexture.getSize().y);
        // Positionnez le sprite du plateau au centre de la fenêtre
        sf::FloatRect bounds = pawnSprite.getLocalBounds();
        pawnSprite.setOrigin(bounds.width / 2, bounds.height / 2);
        pawnSprite.setPosition(position);
        window->draw(pawnSprite);
    }

    void Display::draw_equipped_card(int PlayerNum) {
        for(int i = 0; i< gameState->get_Player_liste()[PlayerNum].get_equipped_card().size(); i++){
            int id;
            if(gameState->get_Player_liste()[PlayerNum].get_equipped_card()[i].get_card_type() == 0){
                int output = 1;
                id = gameState->get_Player_liste()[PlayerNum].get_equipped_card()[i].get_id() + output;
            }
            else{
                int output = 2;
                id = gameState->get_Player_liste()[PlayerNum].get_equipped_card()[i].get_id() + output;
            }
            sf::Texture texture = this->getCardImg(id);
            sf::Sprite sprite;
            sf::Vector2f size = sf::Vector2f(62,100);
            sprite.setTexture(texture);
            sf::Vector2f position = myLocations.get_cardsOnBoard().at(id).get_position();

            sprite.setScale(size.x / texture.getSize().x, size.y/ texture.getSize().y);
            sf::FloatRect bounds = sprite.getLocalBounds();
            sprite.setOrigin(bounds.width / 2, bounds.height / 2);
            sprite.setPosition(position);
            window->draw(sprite);
        }
    }

    void Display::draw_player_character(int PlayerNum){
        int id  = gameState->get_player_location(PlayerNum);
        sf::Texture pawnTexture;
        sf::Sprite pawnSprite;
        sf::Vector2f size = sf::Vector2f(10,10);

        pawnTexture.loadFromFile("../ShadowHunter_Card/Board/Pawn" + std::to_string(PlayerNum) + ".png");
        pawnSprite.setTexture(pawnTexture);
        sf::Vector2f position;
        position = myLocations.get_playerOnBoard().at(id)[PlayerNum].get_position();
        // Redimensionnez le sprite du plateau en fonction de la taille souhaitée
        pawnSprite.setScale(size.x / pawnTexture.getSize().x, size.y / pawnTexture.getSize().y);
        // Positionnez le sprite du plateau au centre de la fenêtre
        sf::FloatRect bounds = pawnSprite.getLocalBounds();
        pawnSprite.setOrigin(bounds.width / 2, bounds.height / 2);
        pawnSprite.setPosition(position);
        window->draw(pawnSprite);
    }

    void Display::draw_playing_card(int CardId, int Cardtype) {

    }
}

