#include "StateMachine.h"

void StateMachine::pushState(State* state) {
    states.push(state);
}

void StateMachine::popState() {
    if (!states.empty()) {
        delete states.top();
        states.pop();
    }
}

void StateMachine::changeState(State* state) {
    popState();
    pushState(state);
}

void StateMachine::returnToFirstState()
{
    while (states.size() > 1)
    {
        popState();
    }
}

State* StateMachine::getCurrentState() {
    return states.top();
}