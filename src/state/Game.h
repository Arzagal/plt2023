// Generated by dia2code
#ifndef STATE__GAME__H
#define STATE__GAME__H


namespace state {
  class Card_type;
  class Player;
  class Board;
}

#include "Card_type.h"
#include "Player.h"
#include "Board.h"

namespace state {

  /// class Game - 
  class Game {
    // Associations
    // Attributes
  private:
    Playing playing     = 0;
    int turn;
     player_number;
     damage_count;
    // Operations
  public:
    start_game ();
    add_player ();
    new_turn ();
    change_player ();
    add_dmg (int target);
    draw (Card_type card_type);
    // Setters and Getters
  };

};

#endif
