    //
// Created by louis on 10/24/23.
//
#include "DeckVision.h"
#include <algorithm>
#include <random>

namespace state{
    DeckVision::DeckVision() {
        for(int i =0; i<16; i++){
            Vision* Card = new Vision(i-1);
            this->deck.push_back(Card);
        }

    }
    Vision* DeckVision:: draw (){
        std::random_device rd;
        std::mt19937 g(rd());

        std::shuffle(deck.begin(), deck.end(), g);
        Vision* res =  deck.at(deck.size()-1);
        deck.pop_back();
        return res;
    }
}