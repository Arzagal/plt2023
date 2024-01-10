#include "DeckLight.h"
#include <algorithm>
#include <random>

namespace state{
    DeckLight::DeckLight() {
        this->deck_initialize();
    }

    Darknlight* DeckLight:: draw (){
        if(deck.empty()){
            this->deck_initialize();
        }
        Darknlight* res =  deck.at(deck.size()-1);
        deck.pop_back();
        return res;
    }

    void DeckLight::deck_initialize() {
        std::random_device rd;
        std::mt19937 g(rd());
        for(int i =0; i<17; i++){
            Darknlight* Card = new Darknlight(i+1, 0);
            this->deck.push_back(Card);
        }
        std::shuffle(deck.begin(), deck.end(), g);
    }
}
