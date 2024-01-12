#include "Card.h"
namespace state {
    Card::Card() = default;

    int Card::getCard_type() const {
        return this->card_type;
    }

    int Card::getCard_id() const {
        return this->card_id;
    }
}