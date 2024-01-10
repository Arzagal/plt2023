#include "Darknlight.h"

namespace state{
    Darknlight::Darknlight(int id, int card_type) : card_id(id), card_type(card_type){
    }

    int Darknlight:: get_id (){
        return this->card_id;
    }

    void Darknlight:: activate_effect (int target, Game* game) {
        if(this->card_type == 1) {
            game->add_wound(target, 1);
        }
        else if(this->card_type == 0){
            game->heal(target, 1);
        }
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

    bool Darknlight::is_equipment() {
        return this->is_equipped;
    }


}