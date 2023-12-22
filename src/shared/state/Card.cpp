//
// Created by louis on 10/24/23.
//
#include "Card.h"
namespace state {
    Card::Card() {}

    std::string Card::get_path() {
        return this->path_to_texture;
    }
}