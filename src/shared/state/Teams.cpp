#include "Teams.h"

namespace state {

  std::string teamsToString(Teams teams) {
    switch(teams) {
      case Shadow: return "Shadow";
      case Hunter: return "Hunter";
      case Neutral: return "Neutral";

      default: return "Unknown teams";
    }
  }
  
};