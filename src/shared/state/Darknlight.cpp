//
// Created by louis on 10/24/23.
//
#include "Darknlight.h"

namespace state{
    Darknlight::Darknlight() {
        this->card_id = 1;
    }
    int Darknlight:: get_id (){
        return this->card_id;
    };
    void Darknlight:: play_effect () {  }

    int Darknlight::get_card_type() {
        return this->card_type;
    }

    void Darknlight::set_card_type(int type) {
        this->card_type = type;
    }
}