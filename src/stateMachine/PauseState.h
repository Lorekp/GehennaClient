#ifndef PAUSESTATE_H
#define PAUSESTATE_H

#include "State.h"
#include "StateMachine.h"
#include "SettingsState.h"
#include "MainMenuState.h"
#include "../backend/AssetManager.h"
#include <SFML/Graphics.hpp>

class PauseState : public State {
public:
    PauseState(StateMachine& machine, sf::RenderWindow& window);
    int handleEvent(sf::Event& event) override;
    void update(sf::Time deltaTime) override;
    void render(sf::RenderWindow& window) override;

private:
    StateMachine& stateMachine;
    sf::RenderWindow& window;
    sf::Font font;
    sf::Text resumeText;
    sf::Text settingsText;
    sf::Text quitText;
    sf::RectangleShape background;
};

#endif // PAUSESTATE_H
