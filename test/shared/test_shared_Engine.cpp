//
// Created by franzozich on 10/01/24.
//
#include <boost/test/unit_test.hpp>
#include "../../src/shared/engine/Engine.h"

using namespace engine;
using namespace render;
using namespace state;
BOOST_AUTO_TEST_CASE(firstEngineTest){
    Game myGame=Game();
    sf::RenderWindow window;
    sf::Sprite mySprite=sf::Sprite();
    Display myDisplay=Display(window,mySprite,&myGame);
    Engine myEngine= Engine(&myDisplay);
    myEngine.get_display();
    myEngine.getState();
    myEngine.detectArea(5,5,10,10,7,3);
    myEngine.handleClick(100,100);
    myEngine.awaitUsrInput();
}