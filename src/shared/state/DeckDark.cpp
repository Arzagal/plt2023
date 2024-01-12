#include "DeckDark.h"

namespace state {

    DeckDark::DeckDark() {
        // Crée 20 cartes Dark et les ajoute au deck
        for (int i = 0; i < 12; ++i) {
            Dark* darkCard = new Dark();
            deck.push_back(*darkCard);
        }

        shuffleDeck();
    }

    void DeckDark::remove(int card_id) {
        // Implémentez la suppression d'une carte Dark du deck
    }

    Dark* DeckDark::draw() {
        // Retournez une carte du deck, ou nullptr si le deck est vide
        if (!deck.empty()) {
            Dark* drawnCard = new Dark(deck.back());
            deck.pop_back();
            return drawnCard;
        }
        return nullptr;
    }

    void DeckDark::shuffleDeck() {
        // Utilisez std::shuffle pour mélanger le deck
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(deck.begin(), deck.end(), g);
    }

}
