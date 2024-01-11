#include <boost/test/unit_test.hpp>
#include "../../src/shared/engine/Engine.h"

using namespace engine;
using namespace render;
using namespace state;
BOOST_AUTO_TEST_CASE(firstEngineTest){
    Game myGame=Game();
    sf::RenderWindow window;

    sf::Sprite mySprite=sf::Sprite();
    myGame.start_game();
    Display myDisplay=Display(window,mySprite,&myGame);
    Engine myEngine= Engine(&myDisplay,&myGame,0);
    myEngine.get_display();
    myEngine.getState();
    myEngine.awaitUsrInput();

    myEngine.detectArea(660,960,200,300,660,960);
    //myEngine.handleClick(996,494);
    myEngine.handleClick(1094,591);
    myEngine.handleClick(1197,496);
    myEngine.handleClick(1448,104);



}