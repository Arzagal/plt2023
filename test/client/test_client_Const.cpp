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
    std::map<int, std::vector<PlayerPosition>> playerBoard = constTest->get_playerOnBoard();
    BOOST_CHECK_EQUAL(playerBoard.at(1)[0].getPixelX(), 770);
    constTest->printContents();

}