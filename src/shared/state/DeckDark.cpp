//
// Created by louis on 10/24/23.
//
#include "DeckDark.h"

namespace state{
    DeckDark::DeckDark() {
        for(int i =0; i<16; i++){
            Darknlight Card = new Darknlight();
        }
    }
    void DeckDark:: remove (int card_id){}
    Darknlight* DeckDark:: draw (){}
}