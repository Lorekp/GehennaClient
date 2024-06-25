#include "GameState.h"

GameState::GameState(StateMachine& machine, sf::RenderWindow& window)
    : stateMachine(machine), window(window)
{
    
}

int GameState::handleEvent(sf::Event& event) {
    switch (event.type)
    {
    case sf::Event::KeyPressed:
    {
        switch (event.key.code)
        {
        case sf::Keyboard::Escape:
        {
            stateMachine.pushState(new PauseState(stateMachine, window));
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
    return 0;
}

void GameState::update(sf::Time deltaTime) {
    
}

void GameState::render(sf::RenderWindow& window) {
    // draw stuff
}
