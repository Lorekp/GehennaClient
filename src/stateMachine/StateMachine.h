#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include "State.h"
#include <stack>

class StateMachine {
public:
    void pushState(State* state);
    void popState();
    void changeState(State* state);
    void returnToFirstState();
    State* getCurrentState();

private:
    std::stack<State*> states;
};

#endif // STATEMACHINE_H