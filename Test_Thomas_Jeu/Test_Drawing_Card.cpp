#include "classe.h"

int main (){

    std::vector<Dark> Dark_Card_Deck;
    int change1;
    int change2;

    for (int i = 0; i < 16; i++){
        Dark_Card_Deck.emplace_back(i, false);
    }
    
    //Fonction shuffle
    for (int i = 0; i < 20; i++){
        auto seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::srand(static_cast<unsigned int>(seed));

        change1 = std::rand() % 17;
        change2 = std::rand() % 17;

        std::swap(Dark_Card_Deck[change1], Dark_Card_Deck[change2]);
    }

    for (int i = 0; i < 16; i++){
        Dark_Card_Deck[i].printState();
    }

    Player player1("John", 15, false, 10);

    return 0;
}