//
// Created by louis on 10/24/23.
//
#include "DeckLight.h"
#include <algorithm>
#include <random>

namespace state{
    DeckLight::DeckLight() {
        for(int i =0; i<17; i++){
            Darknlight* Card = new Darknlight(i+1);
            this->deck.push_back(Card);
        }

    }
    Darknlight* DeckLight:: draw (){
        std::random_device rd;
        std::mt19937 g(rd());

        std::shuffle(deck.begin(), deck.end(), g);
        Darknlight* res =  deck.at(deck.size()-1);
        deck.pop_back();
        return res;
    }
    }
}