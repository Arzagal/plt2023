#include <boost/test/unit_test.hpp>
#include "../../src/shared/state/Player.h"
#include "../../src/shared/state.h"
using namespace state;
BOOST_AUTO_TEST_CASE(firstPlayerTest){
    int num1 = 0;
    int num2 = 1;
    Player player = Player(num1);
    Player target = Player(num2);
    Character character = Allie;
    Darknlight* card = new Darknlight(1,0);
    int hp = 10;

    player.active_character_effect ();
    player.active_character_effect();
    player.reveal ();
    player.get_hp ();
    player.set_hp (hp);

    player.set_character (character);
    int get_number = player.get_number();
    BOOST_CHECK_EQUAL(get_number, num1);
    std::vector <Darknlight*> equipped;
    equipped = player.get_equipped_card ();
    BOOST_CHECK(equipped.empty());
    player.active_board_effect ();

    player.equipe_card (card);

    player.set_character(Allie);
    BOOST_CHECK_EQUAL(player.getCharacter(), "Allie");
    player.set_character(Agnes);
    BOOST_CHECK_EQUAL(player.getCharacter(), "Agnes");
    player.set_character(Bob);
    BOOST_CHECK_EQUAL(player.getCharacter(), "Bob");
    player.set_character(Bryan);
    BOOST_CHECK_EQUAL(player.getCharacter(), "Bryan");
    player.set_character(Catherine);
    BOOST_CHECK_EQUAL(player.getCharacter(), "Catherine");
    player.set_character(Charles);
    BOOST_CHECK_EQUAL(player.getCharacter(), "Charles");
    player.set_character(Daniel);
    BOOST_CHECK_EQUAL(player.getCharacter(), "Daniel");
    player.set_character(David);
    BOOST_CHECK_EQUAL(player.getCharacter(), "David");
    player.set_character(Ellen);
    BOOST_CHECK_EQUAL(player.getCharacter(), "Ellen");
    player.set_character(Emi);
    BOOST_CHECK_EQUAL(player.getCharacter(), "Emi");
    player.set_character(Franklin);
    BOOST_CHECK_EQUAL(player.getCharacter(), "Franklin");
    player.set_character(Fu_ka);
    BOOST_CHECK_EQUAL(player.getCharacter(), "Fu_ka");
    player.set_character(Georges);
    BOOST_CHECK_EQUAL(player.getCharacter(), "Georges");
    player.set_character(Gregor);
    BOOST_CHECK_EQUAL(player.getCharacter(), "Gregor");
    player.set_character(Liche);
    BOOST_CHECK_EQUAL(player.getCharacter(), "Liche");
    player.set_character(Loup_Garou);
    BOOST_CHECK_EQUAL(player.getCharacter(), "Loup_garou");
    player.set_character(Metamorphe);
    BOOST_CHECK_EQUAL(player.getCharacter(), "Metamorphe");
    player.set_character(Momie);
    BOOST_CHECK_EQUAL(player.getCharacter(), "Momie");
    player.set_character(Valkyrie);
    BOOST_CHECK_EQUAL(player.getCharacter(), "Valkyrie");
    player.set_character(Vampire);
    BOOST_CHECK_EQUAL(player.getCharacter(), "Vampire");
    BOOST_CHECK(1);
    }
