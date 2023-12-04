#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <random>
#include <ctime>

class CarteVision {
public:
    CarteVision(sf::RenderWindow& window);

    // Méthode pour mélanger les cartes
    void shuffle();

    // Méthode pour piocher une carte
    void draw();

    // Méthode pour afficher la carte actuelle
    void display();

private:
    std::vector<sf::Texture> cartes;
    int currentIndex;
    sf::RenderWindow& window;
};

CarteVision::CarteVision(sf::RenderWindow& window) : window(window) {
    // Chargez les textures des cartes (16 cartes différentes)
    for (int i = 1; i < 16; i++) {
        sf::Texture texture;
        if (texture.loadFromFile("Vision_Card_" + std::to_string(i) + ".png")) {
            cartes.push_back(texture);
        }
        else {
            std::cerr << "Impossible de charger l'image de la carte " << i << std::endl;
        }
    }

    currentIndex = 0;
}

void CarteVision::shuffle() {
    // Mélangez les cartes en utilisant un algorithme de mélange.
    std::shuffle(cartes.begin(), cartes.end(), std::default_random_engine(std::time(nullptr)));
    currentIndex = 0;
}

void CarteVision::draw() {
    if (currentIndex < cartes.size()) {
        // Ici, vous pouvez ajouter du code pour gérer le tirage d'une carte.
        // Par exemple, vous pouvez augmenter l'indice actuel pour passer à la carte suivante.
        currentIndex++;
    }
}

void CarteVision::display() {
    if (currentIndex < cartes.size()) {
        sf::Sprite carteSprite;
        carteSprite.setTexture(cartes[currentIndex]);
        window.clear();
        window.draw(carteSprite);
        window.display();
    }
}

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Carte Vision");
    CarteVision carteVision(window);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if (event.type == sf::Event::MouseButtonReleased) {
                // Gérer les clics de souris pour les actions de mélange et de pioche
                if (event.mouseButton.button == sf::Mouse::Left) {
                    // Mélanger les cartes lorsque le bouton gauche de la souris est cliqué
                    carteVision.shuffle();
                }
                else if (event.mouseButton.button == sf::Mouse::Right) {
                    // Piocher une carte lorsque le bouton droit de la souris est cliqué
                    carteVision.draw();
                }
            }
        }

        carteVision.display();
    }

    return 0;
}
