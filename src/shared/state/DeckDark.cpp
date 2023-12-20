//
// Created by louis on 10/24/23.
//
#include "DeckDark.h"
#include <algorithm>
#include <random>

namespace state{
    DeckDark::DeckDark() {

    }
    Darknlight* DeckDark:: draw (){
        std::random_device rd;
        std::mt19937 g(rd());
        if(deck.empty()){
            this->deck_initialize();
        }
        std::shuffle(deck.begin(), deck.end(), g);
        Darknlight* res =  deck.at(deck.size()-1);
        deck.pop_back();
        return res;
    }

    void DeckDark::deck_initialize() {
        for(int i =0; i<16; i++){
            Darknlight* Card = new Darknlight(i+1, 1);
            this->deck.push_back(Card);
        }
    }
}