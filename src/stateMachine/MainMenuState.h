#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H

#include "../backend/AssetManager.h"
#include "State.h"
#include "StateMachine.h"
#include "SettingsState.h"
#include "GameState.h"
#include <SFML/Graphics.hpp>

class MainMenuState : public State {
public:
    MainMenuState(StateMachine& machine, sf::RenderWindow& window);
    int handleEvent(sf::Event& event) override;
    void update(sf::Time deltaTime) override;
    void render(sf::RenderWindow& window) override;

private:
    StateMachine& stateMachine;
    sf::RenderWindow& window;
    sf::Font font;
    sf::Text startText;
    sf::Text settingsText;
    sf::Text quitText;
    sf::RectangleShape background;

    void loadVideo(const std::string& filePath);
    void playVideo();
};

#endif // MAINMENUSTATE_H
