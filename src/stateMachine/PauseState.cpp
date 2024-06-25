#include "PauseState.h"

PauseState::PauseState(StateMachine& machine, sf::RenderWindow& window)
    : stateMachine(machine)
    , window(window) {
    // Load font
    font = AssetManager::getInstance()->getFont(".\\resource\\fonts\\BebasNeueRegular.ttf");

    // Setup text
    resumeText.setFont(font);
    resumeText.setString("Resume Game");
    resumeText.setPosition(100.f, 100.f); // Ensure float literals

    settingsText.setFont(font);
    settingsText.setString("Settings");
    settingsText.setPosition(100.f, 200.f); // Ensure float literals

    quitText.setFont(font);
    quitText.setString("Quit to Main Menu");
    quitText.setPosition(100.f, 300.f); // Ensure float literals

    // Background setup (semi-transparent overlay)
    background.setSize(sf::Vector2f(static_cast<float>(window.getSize().x), static_cast<float>(window.getSize().y)));
    background.setFillColor(sf::Color(0, 0, 0, 150)); // Semi-transparent black
}

int PauseState::handleEvent(sf::Event& event) {
    if (event.type == sf::Event::MouseButtonPressed) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);

        if (resumeText.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
            stateMachine.popState(); // Resume the game
        }
        else if (settingsText.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
            stateMachine.pushState(new SettingsState(stateMachine, window));
        }
        else if (quitText.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
            stateMachine.returnToFirstState(); // Quit to main menu
        }
    }
    return 0;
}

void PauseState::update(sf::Time deltaTime) {
    // No update logic needed for the pause state (maybe get info from server about stuff happening in background?)
}

void PauseState::render(sf::RenderWindow& window) {
    // Render the semi-transparent overlay and text
    window.draw(background);
    window.draw(resumeText);
    window.draw(settingsText);
    window.draw(quitText);
}
