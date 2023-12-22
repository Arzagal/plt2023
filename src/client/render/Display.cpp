//
// Created by franzozich on 13/11/23.
//
#include <render/Display.h>
#include <iostream>

namespace render {

    Display::Display(sf::RenderWindow &win,sf::Sprite bg, state::Game* game)
            : window(&win), background(bg), gameState(game){
        this->gameState=game;
        this->background=bg;
        this->refresh();
    }

    state::Game *Display::getGameState() {
        return gameState;
    }

    void Display::refresh(){
        window->clear();
        window->draw(this->background);
        if(this->gameState->get_state() != state::Starting) {
            this->draw_board();
            for (int i = 0; i < this->gameState->get_number_player(); i++) {
                this->draw_wounds(i);
                this->draw_player_character(i);
                this->draw_pawns(i);
                this->draw_equipped_card(i);
            }
        }
            window->display();
    }


    void Display::draw_wounds(int PlayerNum) {
        sf::Texture pawnTexture;
        sf::Vector2f size = sf::Vector2f(10,10);

        pawnTexture.loadFromFile("./ShadowHunter_Card/Board/Pawn_" + std::to_string(PlayerNum+1) + ".png");
        sf::Vector2f position = myLocations.get_woundLocations().at(gameState->get_wounds(PlayerNum)+1)[PlayerNum].get_position();
        this->draw(pawnTexture, size, position, 0);

    }

    void Display::draw_equipped_card(int PlayerNum) {

        sf::Texture texture;
        for(int i = 0; i< int(gameState->get_Player_liste()[PlayerNum]->get_equipped_card().size()); i++){
            int id;
            if(gameState->get_Player_liste()[PlayerNum]->get_equipped_card()[i]->get_card_type() == 0){
                id = gameState->get_Player_liste()[PlayerNum]->get_equipped_card()[i]->get_id();
                texture.loadFromFile(gameState->get_Player_liste()[PlayerNum]->get_equipped_card()[i]->get_path());
            }
            else{
                id = gameState->get_Player_liste()[PlayerNum]->get_equipped_card()[i]->get_id();
                texture.loadFromFile(gameState->get_Player_liste()[PlayerNum]->get_equipped_card()[i]->get_path());
            }
            sf::Vector2f size = sf::Vector2f(200,300);

            sf::Vector2f position = myLocations.get_equipmentCards().at(PlayerNum+1)[i].get_position();
            this->draw(texture, size, position, myLocations.get_equipmentCards().at(PlayerNum+1)[i].getAngle());

        }
    }

    void Display::draw_pawns(int PlayerNum) {
        int id  = gameState->get_player_location(PlayerNum);
        sf::Texture pawnTexture;
        sf::Vector2f size = sf::Vector2f(10,10);

        pawnTexture.loadFromFile("./ShadowHunter_Card/Board/Pawn_" + std::to_string(PlayerNum+1) + ".png");
        sf::Vector2f position;
        position = myLocations.get_playerOnBoard().at(id+1)[PlayerNum].get_position();
        this->draw(pawnTexture, size, position, 0);

    }

    void Display::draw_playing_card(int CardId, int Cardtype) {
        int id = CardId;
        if(CardId<1 || CardId  >17){
            std::cerr << "Wrong ID : this card does not exist" << std::endl;
            return;
        }
        if(Cardtype==2){
            id += 33;
        }
        else if(Cardtype==1){
            id += 17;
        }
//        sf::Texture texture = this->getCardImg(id);
//        sf::Vector2f size = sf::Vector2f(62,100);
//        sf::Vector2f position = myLocations.get_cardsOnBoard().at(id).get_position();
//        this->draw(texture, size, position, 0);

    }

    void Display::draw_board() {
        for(int i =0; i<6;i++){
            sf::Texture texture;
            texture.loadFromFile("./ShadowHunter_Card/Role_Card/Bob_1.png");
            sf::Vector2f size = sf::Vector2f(200,300);
            sf::Vector2f position = this->myLocations.get_cardsOnBoard()[i].get_position();
            float angle = this->myLocations.get_cardsOnBoard()[i].getAngle();
            this->draw(texture, size, position, angle);
        }
    }

    void Display::draw_player_character(int PlayerNum) {
        sf::Texture texture;
        if(this->gameState->get_Player_liste()[PlayerNum]->isrevealed()) {
            texture.loadFromFile(
                    "./ShadowHunter_Card/Role_Card/" + this->gameState->get_Player_liste()[PlayerNum]->getCharacter() +
                    ".png");
        }
        else{
            texture.loadFromFile("./ShadowHunter_Card/Back_Card/role_back.png");
        }
        sf::Vector2f size = sf::Vector2f(200,300);
        sf::Vector2f position;
        position = myLocations.get_characterCards()[PlayerNum].get_position();
        float angle = myLocations.get_characterCards()[PlayerNum].getAngle();
        this->draw(texture, size, position, angle);

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


    void Display::stateChanged(state::State, int playerNum){
        this->refresh();
    }
}

