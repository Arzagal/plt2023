#include "DeckVision.h"

namespace state {

    DeckVision::DeckVision() {
        // Crée 20 cartes Vision et les ajoute au deck
        for (int i = 0; i < 12; ++i) {
            Vision* visionCard = new Vision();
            deck.push_back(*visionCard);
        }

        shuffleDeck();
    }

    void DeckVision::remove(int card_id) {
    }

    Vision* DeckVision::draw() {
        // Retournez une carte du deck, ou nullptr si le deck est vide
        if (!deck.empty()) {
            Vision* drawnCard = new Vision(deck.back());
            deck.pop_back();
            return drawnCard;
        }
        return nullptr;
    }

    void DeckVision::shuffleDeck() {
        // Utilisez std::shuffle pour mélanger le deck
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(deck.begin(), deck.end(), g);
    }

}