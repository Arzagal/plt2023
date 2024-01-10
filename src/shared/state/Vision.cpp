#include <algorithm>
#include "Vision.h"

namespace state{
    Vision::Vision(int id) : card_id(id) {}


    int Vision::get_id (){
        return this->card_id;
    }

    void Vision::activate_effect(int target, Game* game) {
        game->add_wound(target, 1);
    }
}