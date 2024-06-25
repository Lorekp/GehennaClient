#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "State.h"
#include "StateMachine.h"
#include "PauseState.h"
#include <SFML/Graphics.hpp>

class GameState : public State {
public:
    GameState(StateMachine& machine, sf::RenderWindow& window);
    int handleEvent(sf::Event& event) override;
    void update(sf::Time deltaTime) override;
    void render(sf::RenderWindow& window) override;

private:
    StateMachine& stateMachine;
    sf::RenderWindow& window;

};

#endif 
