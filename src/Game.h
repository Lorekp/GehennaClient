#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "stateMachine/StateMachine.h"
#include "stateMachine/MainMenuState.h"
#include "backend/ConnectionHandler.h"

class Game {
public:
    Game();
    void run();

private:
    void processEvents();
    void update(sf::Time deltaTime);
    void render();

    sf::RenderWindow window;
    StateMachine stateMachine;
    AssetManager assetManager;
    sf::Clock clock;
    sf::Time timePerFrame;
    bool isRunning;
};

#endif