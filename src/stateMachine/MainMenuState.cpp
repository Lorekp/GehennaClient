#include "MainMenuState.h"

MainMenuState::MainMenuState(StateMachine& machine, sf::RenderWindow& window)
    : stateMachine(machine)
    , window(window) {
    // Load font
    font = AssetManager::getFont(R"(.\resource\fonts\BebasNeueRegular.ttf)");

    // Setup text
    startText.setFont(font);
    startText.setString("Start Game");
    startText.setPosition(100, 100);

    settingsText.setFont(font);
    settingsText.setString("Settings");
    settingsText.setPosition(100, 200);

    quitText.setFont(font);
    quitText.setString("Quit Game");
    quitText.setPosition(100, 300);

    // Background setup (optional)
    background.setSize(sf::Vector2f(window.getSize()));
    background.setFillColor(sf::Color::Black);

    // Load and play video
    loadVideo("path/to/your/video.mp4");
    playVideo();
}

int MainMenuState::handleEvent(sf::Event& event) {
    switch (event.type)
    {
    case sf::Event::MouseButtonPressed:
    {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);

        if (startText.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
            stateMachine.pushState(new GameState(stateMachine, window));
        }
        else if (settingsText.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
            stateMachine.pushState(new SettingsState(stateMachine, window));
        }
        else if (quitText.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
            window.close();
            return 1;
        }
        break;
    }
    default:
        break;
    }
    return 0;
}

void MainMenuState::update(sf::Time deltaTime) {
    // Update video playback
}

void MainMenuState::render(sf::RenderWindow& window) {
    // Render video background
    window.draw(background);
    window.draw(startText);
    window.draw(settingsText);
    window.draw(quitText);
}

void MainMenuState::loadVideo(const std::string& filePath) {
    // Implement video loading logic
}

void MainMenuState::playVideo() {
    // Implement video playback logic
}
