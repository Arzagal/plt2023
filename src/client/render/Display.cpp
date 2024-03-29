#include <render/Display.h>
#include <iostream>
#include <thread>
#include <string>

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
    void Display::write_state() {
        sf::Text text;
        sf::Font font;
        std::string msg;
        state::State myState=gameState->get_state();
        switch (myState) {
            case state::Playing:
                msg="Playing";
                break;
            case state::Move:
                msg="Move";
                break;
            case state::Starting:
                msg="Starting";
                break;
            case state::Location_effect:
                msg="Location_effect";
                break;
            case state::Attack:
                msg="Attack";
                break;
            case state::Finished:
                msg="Finished";
                break;
            case state::Card_effect:
                msg="Card_effect";
                break;

        }
        font.loadFromFile("./ShadowHunter_Card/arial.ttf");
        text.setFont(font);
        text.setString(msg);
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::White);
        text.setPosition(1720,1050);
        window->draw(text);
    }

    void Display::draw_player_to_pawn() {
        std::vector<CardPosition> playerCharacters=myLocations.get_characterCards();
        sf::Texture pawnTexture;
        sf::Vector2f size = sf::Vector2f(20,20);
        for (int i = 0; i < 4; ++i) {
            pawnTexture.loadFromFile("./ShadowHunter_Card/Board/Pawn_" + std::to_string(i+1) + ".png");
            sf::Vector2f position;
            position=playerCharacters[i].get_position();
            this->draw(pawnTexture, size, position, 0);
        }
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
            for (int i = 1; i < 4; i++) {
                this->draw_button(i);
            }
            this->draw_player_to_pawn();

        }

        if(this->gameState->get_state() == state::Card_effect) {
            std::vector<int> card = this->gameState->get_actual_card();
            if (!card.empty()) {
                this->draw_playing_card(card[0], card[1]);
            }
        }
        window->display();
    }

    sf::Texture Display::getCardImg(int cardId) {
        sf::Texture texture;
        if(cardId<1 or cardId >49){
            std::cerr << "Error : invalid Card ID"<< std::endl;
        }
        if(cardId<18){
            texture.loadFromFile("./ShadowHunter_Card/Light_Card/Light_Card_" + std::to_string(cardId) + ".png");
        }
        else if(cardId<34){
            texture.loadFromFile("./ShadowHunter_Card/Shadow_Card/Shadow_Card_" + std::to_string(cardId-17) + ".png");

        }
        else if(cardId<50){
            texture.loadFromFile("./ShadowHunter_Card/Vision_Card/Vision_Card_" + std::to_string(cardId-33) + ".png");

        }
        return texture;
    }

    void Display::draw_wounds(int PlayerNum) {
        sf::Texture pawnTexture;
        sf::Vector2f size = sf::Vector2f(20,20);

        pawnTexture.loadFromFile("./ShadowHunter_Card/Board/Pawn_" + std::to_string(PlayerNum+1) + ".png");
        sf::Vector2f position = myLocations.get_woundLocations().at(gameState->get_wounds(PlayerNum)+1)[PlayerNum].get_position();
        this->draw(pawnTexture, size, position, 0);

    }

    void Display::draw_equipped_card(int PlayerNum) {

        sf::Texture texture;
        for(int i = 0; i< int(gameState->get_Player_liste()[PlayerNum]->get_equipped_card().size()); i++){
            int id;
            if(gameState->get_Player_liste()[PlayerNum]->get_equipped_card()[i]->get_card_type() == 0){
                int output = 0;
                id = gameState->get_Player_liste()[PlayerNum]->get_equipped_card()[i]->get_id() + output;
            }
            else{
                int output = 17;
                id = gameState->get_Player_liste()[PlayerNum]->get_equipped_card()[i]->get_id() + output;
            }
            sf::Texture texture = this->getCardImg(id);
            sf::Vector2f size = sf::Vector2f(myLocations.get_card_width(),myLocations.get_card_height());

            sf::Vector2f position = myLocations.get_equipmentCards().at(PlayerNum+1)[i].get_position();
            this->draw(texture, size, position, 0);

        }
    }

    void Display::draw_pawns(int PlayerNum) {
        int id  = gameState->get_player_location(PlayerNum);
        sf::Texture pawnTexture;
        sf::Vector2f size = sf::Vector2f(20,20);

        pawnTexture.loadFromFile("./ShadowHunter_Card/Board/Pawn_" + std::to_string(PlayerNum+1) + ".png");
        sf::Vector2f position;
        position = myLocations.get_playerOnBoard().at(id+1)[PlayerNum].get_position();
        this->draw(pawnTexture, size, position, 0);

    }

    void Display::draw_playing_card(int CardId, int Cardtype) {
        int id = CardId+1;
        if(id<1 || id  >17){
            std::cout  << "card id : " << id << std::endl;
            std::cerr << "Wrong ID : this card does not exist" << std::endl;
            return;
        }
        if(Cardtype==2){
            id += 33;
        }
        else if(Cardtype==1){
            id += 17;
        }
        sf::Texture texture = this->getCardImg(id);
        sf::Vector2f size = sf::Vector2f(myLocations.get_card_width(),myLocations.get_card_height());
        CardPosition play= myLocations.get_playing_card();
        sf::Vector2f position=play.get_position();
        std::cout << position.x << " | " << position.y << std::endl;

        this->draw(texture, size, position, 0);

    }

    void Display::draw_board() {
        for(int i =0; i<6;i++){
            sf::Texture texture;
            int id = this->gameState->get_location_id(i);
            texture.loadFromFile("./ShadowHunter_Card/Board/Location_" + std::to_string(id) + ".png");
            sf::Vector2f size = sf::Vector2f(myLocations.get_card_width(),myLocations.get_card_height());
            sf::Vector2f position = this->myLocations.get_cardsOnBoard()[i].get_position();
            float angle = this->myLocations.get_cardsOnBoard()[i].getAngle();
            this->draw(texture, size, position, angle);
        }
    }

    void Display::draw_player_character(int PlayerNum) {
        sf::Texture texture;
        if(this->gameState->get_Player_liste()[PlayerNum]->isrevealed() || PlayerNum == this->playerNumber) {
            texture.loadFromFile(
                    "./ShadowHunter_Card/Role_Card/" + this->gameState->get_Player_liste()[PlayerNum]->getCharacter() +
                    ".png");
        }
        else{
            texture.loadFromFile("./ShadowHunter_Card/Back_Card/role_back.png");
        }
        sf::Vector2f size = sf::Vector2f(myLocations.get_card_width(),myLocations.get_card_height());
        sf::Vector2f position;
        position = myLocations.get_characterCards()[PlayerNum].get_position();
        float angle = myLocations.get_characterCards()[PlayerNum].getAngle();
        this->draw(texture, size, position, angle);

    }
    void Display::draw_button(int buttonType) {
        const std::string path="./ShadowHunter_Card/Buttons/";
        sf::Texture texture;
        switch (buttonType) {
            case 1:
                texture.loadFromFile(path+"atk.png");
                break;
            case 2:
                texture.loadFromFile(path+"move.png");
                break;
            case 3:
                texture.loadFromFile(path+"next.png");
                break;

        }
        sf::Vector2f size = sf::Vector2f(90,90);
        sf::Vector2f position=myLocations.get_buttons()[buttonType-1].get_position();
        this->draw(texture,size,position,0);

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
        this->write_state();
    }


    void Display::stateChanged(state::State, int playerNum){
        this->refresh();
//        std::thread displayThread (&Display::refresh, this);
//        displayThread.detach();
    }
    sf::RenderWindow* Display::getWindow() {
        return window;
    }
    Const Display::get_locations() {
        return myLocations;
    }
}

