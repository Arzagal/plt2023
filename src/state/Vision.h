// Generated by dia2code
#ifndef STATE__VISION__H
#define STATE__VISION__H


namespace state {
  class Player;
  class DeckVision;
}

#include "Player.h"
#include "DeckVision.h"

namespace state {

  /// class Vision - 
  class Vision {
    // Attributes
  private:
    int card_id;
    enum effect;
    // Operations
  public:
    choose_target (Player target);
    // Setters and Getters
  };

};

#endif
