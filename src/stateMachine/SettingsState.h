#ifndef SETTINGSSTATE_H
#define SETTINGSSTATE_H

#include "State.h"
#include "StateMachine.h"
#include "MainMenuState.h"
#include "../backend/AssetManager.h"
#include <SFML/Graphics.hpp>

class SettingsState : public State {
public:
    SettingsState(StateMachine& machine, sf::RenderWindow& window);
    int handleEvent(sf::Event& event) override;
    void update(sf::Time deltaTime) override;
    void render(sf::RenderWindow& window) override;

private:
    StateMachine& stateMachine;
    sf::RenderWindow& window;
    sf::Font font;
    sf::Text volumeText;
    sf::Text resolutionText;
    sf::Text backText;
    sf::RectangleShape background;
};

#endif // SETTINGSSTATE_H
