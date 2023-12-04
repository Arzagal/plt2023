#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <vector>

//Classe joueur et ces fonctions associées
class Player {
public:
    Player(const std::string& playerName, int healthPoints, bool reveal, int secteur)
        : name(playerName), healthPoints(healthPoints), reveal(reveal), secteur(secteur) {}

    void move() {
        auto seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::srand(static_cast<unsigned int>(seed));

        int previousSecteur = secteur;
        int newSecteur;

        do {
            newSecteur = std::rand() % 9 + 2;

            std::cout << name << " a lancé un dé et est maintenant dans le secteur : " << newSecteur << std::endl;

        } while (newSecteur == previousSecteur);

        secteur = newSecteur;
    }

    void attackPlayer(Player& otherPlayer) {
        auto seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::srand(static_cast<unsigned int>(seed));

        int damage = std::rand() % 10;

        otherPlayer.takeDamage(damage);

        std::cout << name << " attaque " << otherPlayer.getName() << " et inflige " << damage << " points de dégâts!" << std::endl;
    }

    void takeDamage(int damage) {
        healthPoints -= damage;
        if (healthPoints < 0) {
            healthPoints = 0;
        }
        std::cout << name << " subit " << damage << " points de dégâts. Points de vie restants : " << healthPoints << std::endl;
    }

    void displayInfo() const {
        std::cout << "Nom: " << name << "\n"
                  << "Points de vie: " << healthPoints << "\n"
                  << "Reveal: " << (reveal ? "true" : "false") << "\n"
                  << "Secteur: " << secteur << std::endl;
    }

    void displayHealth() const {
        std::cout << "Points de vie restants pour " << name << ": " << healthPoints << std::endl;
    }

    const std::string& getName() const {
        return name;
    }

    int getSecteur() const {
        return secteur;
    }

    bool isDead() const {
        return healthPoints <= 0;
    }

private:
    std::string name;
    int healthPoints;
    bool reveal;
    int secteur;
};

//Fonction pour vérifier que deux joueurs sont dans le mếme secteur
bool arePlayersInSameSecteur(const Player& player1, const Player& player2) {
    return player1.getSecteur() == player2.getSecteur();
}

//Classe parent des cartes Dark et Light
class DraknLightCard {
    public:
        DraknLightCard (int card_id, bool is_equipped, bool DarkorLight)
            : card_id(card_id), is_equipped(is_equipped), DarkorLight(DarkorLight) {}
    
    void printState() const {
        std::cout << "Card " << card_id << ": " << (is_equipped ? "true " : "false ") << (DarkorLight ? "true" : "false") << std::endl;
    }

    private:
    int card_id;
    bool is_equipped;
    bool DarkorLight;

};

class Dark: public DraknLightCard {
    public:
        Dark (int card_id, bool is_equipped)
            : DraknLightCard(card_id, is_equipped, true) {}
    
    void OneMoreDamage (int card_id){
        
    }
};