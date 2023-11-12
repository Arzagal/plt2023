#include <SFML/Graphics.hpp>
#include <iostream>

class Card_Area {
public:
    Card_Area(const std::string& texturePath, const sf::Vector2f& size, const sf::Vector2f& position,float rotationAngle = 0.0f) {
        if (!card_areaTexture.loadFromFile(texturePath)) {
            std::cerr << "Erreur lors du chargement de l'image de la carte lieu" << std::endl;
        }

        card_areaSprite.setTexture(card_areaTexture);
        // Redimensionnez le sprite du plateau en fonction de la taille souhaitée
        card_areaSprite.setScale(size.x / card_areaTexture.getSize().x, size.y / card_areaTexture.getSize().y);
        // Positionnez le sprite du plateau au centre de la fenêtre
        sf::FloatRect bounds = card_areaSprite.getLocalBounds();
        card_areaSprite.setOrigin(bounds.width / 2, bounds.height / 2);
        card_areaSprite.setPosition(position); // Ajustez les coordonnées en fonction de votre fenêtre
        card_areaSprite.setRotation(rotationAngle);
    }

    void draw(sf::RenderWindow& window) {
        window.draw(card_areaSprite);
    }

private:
    sf::Texture card_areaTexture;
    sf::Sprite card_areaSprite;
};

class Vision_Card {
public:
    Vision_Card(const std::string& texturePath, const sf::Vector2f& size, const sf::Vector2f& position) {
        if (!vision_cardTexture.loadFromFile(texturePath)) {
            std::cerr << "Erreur lors du chargement de l'image de la carte lieu" << std::endl;
        }

        vision_cardSprite.setTexture(vision_cardTexture);
        // Redimensionnez le sprite du plateau en fonction de la taille souhaitée
        vision_cardSprite.setScale(size.x / vision_cardTexture.getSize().x, size.y / vision_cardTexture.getSize().y);
        // Positionnez le sprite du plateau au centre de la fenêtre
        sf::FloatRect bounds = vision_cardSprite.getLocalBounds();
        vision_cardSprite.setOrigin(bounds.width / 2, bounds.height / 2);
        vision_cardSprite.setPosition(position); // Ajustez les coordonnées en fonction de votre fenêtre
    }

    void draw(sf::RenderWindow& window) {
        window.draw(vision_cardSprite);
    }

private:
    sf::Texture vision_cardTexture;
    sf::Sprite vision_cardSprite;
};

class Darkness_Card {
public:
    Darkness_Card(const std::string& texturePath, const sf::Vector2f& size, const sf::Vector2f& position) {
        if (!darkness_cardTexture.loadFromFile(texturePath)) {
            std::cerr << "Erreur lors du chargement de l'image de la carte lieu" << std::endl;
        }

        darkness_cardSprite.setTexture(darkness_cardTexture);
        // Redimensionnez le sprite du plateau en fonction de la taille souhaitée
        darkness_cardSprite.setScale(size.x / darkness_cardTexture.getSize().x, size.y / darkness_cardTexture.getSize().y);
        // Positionnez le sprite du plateau au centre de la fenêtre
        sf::FloatRect bounds = darkness_cardSprite.getLocalBounds();
        darkness_cardSprite.setOrigin(bounds.width / 2, bounds.height / 2);
        darkness_cardSprite.setPosition(position); // Ajustez les coordonnées en fonction de votre fenêtre
    }

    void draw(sf::RenderWindow& window) {
        window.draw(darkness_cardSprite);
    }

private:
    sf::Texture darkness_cardTexture;
    sf::Sprite darkness_cardSprite;
};

class Light_Card {
public:
    Light_Card(const std::string& texturePath, const sf::Vector2f& size, const sf::Vector2f& position) {
        if (!light_cardTexture.loadFromFile(texturePath)) {
            std::cerr << "Erreur lors du chargement de l'image de la carte lieu" << std::endl;
        }

        light_cardSprite.setTexture(light_cardTexture);
        // Redimensionnez le sprite du plateau en fonction de la taille souhaitée
        light_cardSprite.setScale(size.x / light_cardTexture.getSize().x, size.y / light_cardTexture.getSize().y);
        // Positionnez le sprite du plateau au centre de la fenêtre
        sf::FloatRect bounds = light_cardSprite.getLocalBounds();
        light_cardSprite.setOrigin(bounds.width / 2, bounds.height / 2);
        light_cardSprite.setPosition(position); // Ajustez les coordonnées en fonction de votre fenêtre
    }

    void draw(sf::RenderWindow& window) {
        window.draw(light_cardSprite);
    }

private:
    sf::Texture light_cardTexture;
    sf::Sprite light_cardSprite;
};

class Player_Card {
public:
    Player_Card(const std::string& texturePath, const sf::Vector2f& size, const sf::Vector2f& position){
        if (!player_card_Texture.loadFromFile(texturePath)) {
            std::cerr << "Erreur lors du chargement de l'image du pion" << std::endl;
        }

        player_card_Sprite.setTexture(player_card_Texture);
        // Redimensionnez le sprite du plateau en fonction de la taille souhaitée
        player_card_Sprite.setScale(size.x / player_card_Texture.getSize().x, size.y / player_card_Texture.getSize().y);
        // Positionnez le sprite du plateau au centre de la fenêtre
        sf::FloatRect bounds = player_card_Sprite.getLocalBounds();
        player_card_Sprite.setOrigin(bounds.width / 2, bounds.height / 2);
        player_card_Sprite.setPosition(position); // Ajustez les coordonnées en fonction de votre fenêtre
    }

    void draw(sf::RenderWindow& window) {
        window.draw(player_card_Sprite);
    }

    private:
    sf::Texture player_card_Texture;
    sf::Sprite player_card_Sprite;
};

class Pawn {
public:
    Pawn(const std::string& texturePath, const sf::Vector2f& size, const sf::Vector2f& position){
        if (!pawnTexture.loadFromFile(texturePath)) {
            std::cerr << "Erreur lors du chargement de l'image du pion" << std::endl;
        }

        pawnSprite.setTexture(pawnTexture);
        // Redimensionnez le sprite du plateau en fonction de la taille souhaitée
        pawnSprite.setScale(size.x / pawnTexture.getSize().x, size.y / pawnTexture.getSize().y);
        // Positionnez le sprite du plateau au centre de la fenêtre
        sf::FloatRect bounds = pawnSprite.getLocalBounds();
        pawnSprite.setOrigin(bounds.width / 2, bounds.height / 2);
        pawnSprite.setPosition(position); // Ajustez les coordonnées en fonction de votre fenêtre
    }

    void draw(sf::RenderWindow& window) {
        window.draw(pawnSprite);
    }

    private:
    sf::Texture pawnTexture;
    sf::Sprite pawnSprite;
};

class Board {
public:
    Board(const std::string& texturePath, const sf::Vector2f& size) {
        if (!boardTexture.loadFromFile(texturePath)) {
            std::cerr << "Erreur lors du chargement de l'image du plateau" << std::endl;
        }

        boardSprite.setTexture(boardTexture);
        // Redimensionnez le sprite du plateau en fonction de la taille souhaitée
        boardSprite.setScale(size.x / boardTexture.getSize().x, size.y / boardTexture.getSize().y);
        // Positionnez le sprite du plateau au centre de la fenêtre
        sf::FloatRect bounds = boardSprite.getLocalBounds();
        boardSprite.setOrigin(bounds.width / 2, bounds.height / 2);
        boardSprite.setPosition(300, 225); // Ajustez les coordonnées en fonction de votre fenêtre
    }

    void draw(sf::RenderWindow& window) {
        window.draw(boardSprite);
    }

private:
    sf::Texture boardTexture;
    sf::Sprite boardSprite;
};


int main() {
    sf::RenderWindow window(sf::VideoMode(600, 450), "Jeu de société");

    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("/home/krustybe/Desktop/ShadowHunter_Card/Board/Table.jpg")) {
        std::cerr << "Erreur lors du chargement de l'image de fond" << std::endl;
        return 1;
    }

    // Créez un sprite pour afficher le fond
    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundTexture);

    // Créez une instance de la classe Board avec la taille souhaitée
    Board board("/home/krustybe/Desktop/ShadowHunter_Card/Board/Board-1.png", sf::Vector2f(400, 300));

    // Créez une instance de la classe Board avec la taille souhaitée
    Card_Area card_area_1("/home/krustybe/Desktop/ShadowHunter_Card/Vision_Card/Vision_Card_1.png", sf::Vector2f(55, 90), sf::Vector2f(317, 140));
    Card_Area card_area_2("/home/krustybe/Desktop/ShadowHunter_Card/Vision_Card/Vision_Card_2.png", sf::Vector2f(55, 90), sf::Vector2f(381, 140));

    Card_Area card_area_3("/home/krustybe/Desktop/ShadowHunter_Card/Vision_Card/Vision_Card_3.png", sf::Vector2f(55, 90), sf::Vector2f(260, 250), 250.0f);
    Card_Area card_area_4("/home/krustybe/Desktop/ShadowHunter_Card/Vision_Card/Vision_Card_4.png", sf::Vector2f(55, 90), sf::Vector2f(285, 315), 250.0f);

    Card_Area card_area_5("/home/krustybe/Desktop/ShadowHunter_Card/Vision_Card/Vision_Card_5.png", sf::Vector2f(55, 90), sf::Vector2f(440, 250), -250.0f);
    Card_Area card_area_6("/home/krustybe/Desktop/ShadowHunter_Card/Vision_Card/Vision_Card_6.png", sf::Vector2f(55, 90), sf::Vector2f(415, 315), -250.0f);

    Pawn pawn_Player_One("/home/krustybe/Desktop/ShadowHunter_Card/Board/Pawn.png", sf::Vector2f(10,10), sf::Vector2f(130,300));
    Pawn pawn_Player_Two("/home/krustybe/Desktop/ShadowHunter_Card/Board/Pawn.png", sf::Vector2f(10,10), sf::Vector2f(150,300));
    Pawn pawn_Player_Three("/home/krustybe/Desktop/ShadowHunter_Card/Board/Pawn.png", sf::Vector2f(10,10), sf::Vector2f(170,300));
    Pawn pawn_Player_Four("/home/krustybe/Desktop/ShadowHunter_Card/Board/Pawn.png", sf::Vector2f(10,10), sf::Vector2f(190,300));

    Player_Card play_card_One("/home/krustybe/Desktop/ShadowHunter_Card/Role_Card/Bob_1.png", sf::Vector2f(75, 120), sf::Vector2f(50,400));
    Player_Card play_card_Two("/home/krustybe/Desktop/ShadowHunter_Card/Back_Card/role_back.png", sf::Vector2f(75, 120), sf::Vector2f(50,50));
    Player_Card play_card_Three("/home/krustybe/Desktop/ShadowHunter_Card/Back_Card/role_back.png", sf::Vector2f(75, 120), sf::Vector2f(550,50));
    Player_Card play_card_Four("/home/krustybe/Desktop/ShadowHunter_Card/Back_Card/role_back.png", sf::Vector2f(75, 120), sf::Vector2f(550,400));

    Light_Card light_card_1("/home/krustybe/Desktop/ShadowHunter_Card/Back_Card/light_back.png", sf::Vector2f(62, 100), sf::Vector2f(530,130));
    Vision_Card vision_card_1("/home/krustybe/Desktop/ShadowHunter_Card/Back_Card/vision_back.png", sf::Vector2f(62, 100), sf::Vector2f(530,230));
    Darkness_Card darkness_card_1("/home/krustybe/Desktop/ShadowHunter_Card/Back_Card/darkness_back.png", sf::Vector2f(62, 100), sf::Vector2f(530,330));

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();
        window.draw(backgroundSprite);

        // Display Board
        board.draw(window);

        // Display Area
        card_area_1.draw(window);
        card_area_2.draw(window);
        card_area_3.draw(window);
        card_area_4.draw(window);
        card_area_5.draw(window);
        card_area_6.draw(window);

        pawn_Player_One.draw(window);
        pawn_Player_Two.draw(window);
        pawn_Player_Three.draw(window);
        pawn_Player_Four.draw(window);

        darkness_card_1.draw(window);
        vision_card_1.draw(window);
        light_card_1.draw(window);

        play_card_One.draw(window);
        play_card_Two.draw(window);
        play_card_Three.draw(window);
        play_card_Four.draw(window);

        window.display();
    }

    return 0;
}
