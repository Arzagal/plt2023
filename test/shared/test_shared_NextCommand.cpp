#include <boost/test/unit_test.hpp>
#include "../../src/shared/engine/NextCommand.h"

using namespace engine;
using namespace state;
using namespace render;
BOOST_AUTO_TEST_CASE(firstNextCommandTest){
    Game myGame=Game();
    sf::RenderWindow window;
    sf::Sprite mySprite=sf::Sprite();
    myGame.start_game();
    Display myDisplay=Display(window,mySprite,&myGame);
    Engine myEngine= Engine(&myDisplay);
    NextCommand next=NextCommand();
    next.execute(&myEngine);
}