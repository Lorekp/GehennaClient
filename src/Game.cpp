#include "Game.h"

Game::Game()
    : window(sf::VideoMode(800, 600), "Gehenna")
    , timePerFrame(sf::seconds(1.f / 60.f))
    , isRunning(true) {
    stateMachine.pushState(new MainMenuState(stateMachine, window)); //start game with mainMenuState
    // Initialize game states and other components
    ConnectionHandler::getInstance();
}

void Game::run() {
    while (isRunning) {
        processEvents();
        update(clock.restart());
        render();
    }
}

void Game::processEvents() {
    sf::Event event{};
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            isRunning = false;
        }
        if (stateMachine.getCurrentState()->handleEvent(event) != 0) //handleEvent returns 0 when not quitting game
            isRunning = false;
        // Pass events to current game state
    }
}

void Game::update(sf::Time deltaTime) {
    stateMachine.getCurrentState()->update(deltaTime);
    // Update current game state
}

void Game::render() {
    window.clear();
    stateMachine.getCurrentState()->render(window);
    // Render current game state
    window.display();
}