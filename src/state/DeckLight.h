// Generated by dia2code
#ifndef STATE__DECKLIGHT__H
#define STATE__DECKLIGHT__H


namespace state {
  class Darknlight;
  class Game;
}

#include "Darknlight.h"
#include "Game.h"

namespace state {

  /// class DeckLight - 
  class DeckLight {
    // Attributes
  private:
    vector<Darknlight> deck;
    // Operations
  public:
    remove (int card_id);
    // Setters and Getters
  };

};

#endif
