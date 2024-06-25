#include "SettingsState.h"

SettingsState::SettingsState(StateMachine& machine, sf::RenderWindow& window)
    : stateMachine(machine)
    , window(window) {
    // Load font
    font = AssetManager::getInstance()->getFont(".\\resource\\fonts\\BebasNeueRegular.ttf");

    // Setup text
    volumeText.setFont(font);
    volumeText.setString("Volume");
    volumeText.setPosition(100, 100);

    resolutionText.setFont(font);
    resolutionText.setString("Resolution");
    resolutionText.setPosition(100, 200);

    backText.setFont(font);
    backText.setString("Back");
    backText.setPosition(100, 300);

    // Background setup (optional)
    background.setSize(sf::Vector2f(window.getSize()));
    background.setFillColor(sf::Color(0, 0, 0, 150)); // Semi-transparent black
}

int SettingsState::handleEvent(sf::Event& event) {
    switch (event.type)
    {
    case sf::Event::MouseButtonPressed:
    {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);

        if (backText.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
            stateMachine.popState();
        }
        break;
    }
    default:
        break;
    }
    // Add more event handling for volume and resolution changes here
    return 0;
}

void SettingsState::update(sf::Time deltaTime) {
    // Update logic for settings (e.g., sliders for volume)
}

void SettingsState::render(sf::RenderWindow& window) {
    window.draw(background);
    window.draw(volumeText);
    window.draw(resolutionText);
    window.draw(backText);
}
