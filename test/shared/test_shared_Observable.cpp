//
// Created by louis on 12/18/23.
//
#include <boost/test/unit_test.hpp>
#include "../../src/shared/state/Observable.h"

using namespace state;
BOOST_AUTO_TEST_CASE(firstObservableTest) {
    Observable *obs = new Observable();
    Observer *observer = new Observer();
    obs->registerObserver(observer);
    State test = State::Playing;
    obs->notifyObserver(test, 0);
}