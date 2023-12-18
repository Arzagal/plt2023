#include "Darknlight.h"

namespace state {

    Darknlight::Darknlight() : card_id(0), is_equipped(false), card_type(0) {
    }

    int Darknlight::get_id() {
        return card_id;
    }

    void Darknlight::set_id(int id) {
        card_id = id;
    }

    void Darknlight::play_effect() {
    }

    int Darknlight::get_card_type() {
        return card_type;
    }

    void Darknlight::set_card_type(int type) {
        card_type = type;
    }

}
