#include "Character.h"

namespace state {

  std::string characterToString(Character character) {
    switch(character) {
      case Agnes: return "Agnes";
      case Allie: return "Allie";
      case Bob: return "Bob";
      case Bryan: return "Bryan";
      case Catherine: return "Catherine";
      case Charles: return "Charles";
      case Daniel: return "Daniel";
      case David: return "David";
      case Ellen: return "Ellen";
      case Emi: return "Emi";
      case Franklin: return "Franklin";
      case Fu_ka: return "Fu_ka";
      case Georges: return "Georges";
      case Gregor: return "Gregor";
      case Liche: return "Liche";
      case Loup_Garou: return "Loup_Garou";
      case Metamorphe: return "Methamorph";
      case Momie: return "Momie";
      case Valkyrie: return "Valkyrie";
      case Vampire: return "Vampire";

      default: return "Unknown Character";
    }
  }
  
};