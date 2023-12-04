//
// Created by franzozich on 13/11/23.
//
#include <render/Display.h>
#include <iostream>

namespace render {

    Display::Display(sf::RenderWindow &win, sf::Sprite bg)
            : window(&win), background(bg) {
        this->gameState=new state::Game();
        this->background=bg;
    }

    state::Game *Display::getGameState() {
        return gameState;
    }

    void Display::refresh(){
        window->clear();
        window->draw(background);
        this->myLocations.printContents();
        this->draw_board();
        for(int i = 0; i< this->gameState->get_number_player(); i++){
            this->draw_wounds(i);
            this->draw_player_character(i);
            this->draw_equipped_card(i);
        }
        window->display();
    }

    sf::Texture Display::getCardImg(int cardId) {
        sf::Texture texture;
        if(cardId<18){
            texture.loadFromFile("../ShadowHunter_Card/Light_Card_" + std::to_string(cardId) + ".png");
        }
        else if(cardId<34){
            texture.loadFromFile("../ShadowHunter_Card/Shadow_Card_" + std::to_string(cardId-17) + ".png");

        }
        else if(cardId<50){
            texture.loadFromFile("../ShadowHunter_Card/Vision_Card" + std::to_string(cardId-33) + ".png");

        }
        return texture;
    }

    void Display::draw_wounds(int PlayerNum) {
        sf::Texture pawnTexture;
        sf::Vector2f size = sf::Vector2f(10,10);

        pawnTexture.loadFromFile("../ShadowHunter_Card/Board/Pawn_" + std::to_string(PlayerNum+1) + ".png");
        sf::Vector2f position = myLocations.get_woundLocations().at(gameState->get_wounds(PlayerNum)+1)[PlayerNum].get_position();
        this->draw(pawnTexture, size, position, 0);

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
            sf::Vector2f size = sf::Vector2f(62,100);
            sf::Vector2f position = myLocations.get_cardsOnBoard().at(id).get_position();

            this->draw(texture, size, position, 0);

        }
    }

    void Display::draw_player_character(int PlayerNum){
        int id  = gameState->get_player_location(PlayerNum);
        sf::Texture pawnTexture;
        sf::Vector2f size = sf::Vector2f(10,10);

        pawnTexture.loadFromFile("../ShadowHunter_Card/Board/Pawn_" + std::to_string(PlayerNum+1) + ".png");
        sf::Vector2f position;
        position = myLocations.get_playerOnBoard().at(id+1)[PlayerNum].get_position();
        this->draw(pawnTexture, size, position, 0);

    }

    void Display::draw_playing_card(int CardId, int Cardtype) {
        int id = CardId;
        if(0==Cardtype){
            id += 0;
        }
        else{
            id += 1;
        }
        sf::Texture texture = this->getCardImg(id);
        sf::Vector2f size = sf::Vector2f(62,100);
        sf::Vector2f position = myLocations.get_cardsOnBoard().at(id).get_position();
        this->draw(texture, size, position, 0);

    }

    void Display::draw_board() {
        for(int i =0; i<6;i++){
            sf::Texture texture;
            texture.loadFromFile("../ShadowHunter_Card/Role_Card/Bob_1.png");
            sf::Vector2f size = sf::Vector2f(200,300);
            sf::Vector2f position = this->myLocations.get_cardsOnBoard()[i].get_position();
            float angle = this->myLocations.get_cardsOnBoard()[i].getAngle();
            this->draw(texture, size, position, angle);
        }
    }
    void Display::draw(sf::Texture texture, sf::Vector2f size, sf::Vector2f position, float angle) { //Function to draw the given image on a certain position
        sf::Sprite sprite;
        sprite.setTexture(texture);
        sprite.setScale(size.x / texture.getSize().x, size.y/ texture.getSize().y);
        sprite.setRotation(angle);
        sf::FloatRect bounds = sprite.getLocalBounds();
        sprite.setOrigin(bounds.width / 2, bounds.height / 2);
        sprite.setPosition(position);
        window->draw(sprite);
    }
}

