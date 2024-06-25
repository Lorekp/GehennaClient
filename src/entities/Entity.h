#include <SFML/Graphics.hpp>

class Entity {
public:
    virtual void update(sf::Time deltaTime) = 0;
    virtual void render(sf::RenderWindow& window) = 0;

protected:
    sf::Sprite sprite;
    sf::Texture texture;
};