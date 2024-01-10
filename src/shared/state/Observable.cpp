#include "Observable.h"
#include <iostream>

namespace state{
    Observable::Observable(){}

    void Observable::registerObserver(state::Observer *observer) {
        observers.push_back(observer);
    }

    void Observable::notifyObserver(state::State state, int playerNum) {
        for(auto observer : observers){
            observer->stateChanged(state, playerNum);
        }
    }
}
