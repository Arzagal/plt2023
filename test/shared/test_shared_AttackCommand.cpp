//
// Created by franzozich on 10/01/24.
//
#include <boost/test/unit_test.hpp>
#include "../../src/shared/engine/AttackCommand.h"

using namespace engine;
using namespace state;
using namespace render;
BOOST_AUTO_TEST_CASE(firstAttackCommandTest){
    Game myGame=Game();
    Player player = Player(1);
    myGame.add_player();
    myGame.start_game();
    myGame.new_turn ();
    sf::RenderWindow window;
    sf::Sprite mySprite=sf::Sprite();
    Display myDisplay=Display(window,mySprite,&myGame);
    Engine myEngine= Engine(&myDisplay);
    AttackCommand atk= AttackCommand(1);
    atk.execute(&myEngine);
}