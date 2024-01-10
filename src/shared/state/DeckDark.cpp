#include "DeckDark.h"
#include <algorithm>
#include <random>

namespace state{
    DeckDark::DeckDark() {
        this->deck_initialize();
    }
    Darknlight* DeckDark:: draw (){

        if(deck.empty()){
            this->deck_initialize();
        }

        Darknlight* res =  deck.at(deck.size()-1);
        deck.pop_back();
        return res;
    }

    void DeckDark::deck_initialize() {
        std::random_device rd;
        std::mt19937 g(rd());
        for(int i =0; i<16; i++){
            Darknlight* Card = new Darknlight(i+1, 1);
            this->deck.push_back(Card);
        }
        std::shuffle(deck.begin(), deck.end(), g);
    }
}