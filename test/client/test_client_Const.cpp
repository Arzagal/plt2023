//
// Created by louis on 11/27/23.
//
#include "/usr/include/boost/test/unit_test.hpp"
#include "../../src/client/render.h"

using namespace render;

BOOST_AUTO_TEST_CASE(DisplayTest) {
    Const *constTest = new Const();

    std::vector<CardPosition> CardPos = constTest->get_cardsOnBoard();
    BOOST_CHECK_EQUAL(CardPos[2].getAngle(), -72.5);

    std::map<int, std::vector<PlayerPosition>> woundLoc = constTest->get_woundLocations();
    BOOST_CHECK_EQUAL(woundLoc.at(1)[0].getPixelX(), 450);
    BOOST_CHECK_EQUAL(woundLoc.at(1)[0].getPixelY(), 810);

    std::map<int, std::vector<PlayerPosition>> playerBoard = constTest->get_playerOnBoard();
    BOOST_CHECK_EQUAL(playerBoard.at(1)[0].getPixelX(), 770);
    BOOST_CHECK_EQUAL(playerBoard.at(1)[0].getPixelY(), 580);

    std::map<int, std::vector<CardPosition>> equipBoard = constTest->get_equipmentCards();
    BOOST_CHECK_EQUAL(equipBoard.at(2)[3].getPixelX(), 147);
    BOOST_CHECK_EQUAL(equipBoard.at(2)[3].getPixelY(), 336);

    std::vector<CardPosition> CharaPos = constTest->get_characterCards();
    BOOST_CHECK_EQUAL(CharaPos[2].getAngle(), 90);
    constTest->printContents();

}