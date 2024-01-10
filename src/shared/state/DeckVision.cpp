#include "DeckVision.h"
#include <algorithm>
#include <random>

namespace state{
    DeckVision::DeckVision() {
        this->deck_initialize();
    }
    Vision* DeckVision:: draw (){
        if(deck.empty()){
            this->deck_initialize();
        }
        Vision* res =  deck.at(deck.size()-1);
        deck.pop_back();
        return res;
    }

    void DeckVision::deck_initialize() {
        std::random_device rd;
        std::mt19937 g(rd());
        for(int i =0; i<16; i++){
            Vision* Card = new Vision(i-1);
            this->deck.push_back(Card);
        }
        std::shuffle(deck.begin(), deck.end(), g);

    }
}