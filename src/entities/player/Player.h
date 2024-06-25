#include "../Entity.h"

class Player : public Entity{
public:
    Player();

    void handleInput();
    void update(sf::Time deltaTime);
    void render(sf::RenderWindow& window);

private:
    sf::Sprite sprite;
    sf::Texture texture;
    float speed;
};