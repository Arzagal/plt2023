//
// Created by louis on 10/24/23.
//
#include "Darknlight.h"

namespace state{
    Darknlight::Darknlight(int id, int card_type) : card_id(id), card_type(card_type){
    }
    int Darknlight:: get_id (){
        return this->card_id;
    };
    void Darknlight:: play_effect () {

    }

    int Darknlight::get_card_type() {
        return this->card_type;
    }

    void Darknlight::set_card_type(int type) {
        this->card_type = type;
    }

    void Darknlight::set_id(int id) {
        this->card_id = id;
    }


}