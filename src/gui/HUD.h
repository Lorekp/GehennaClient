class HUD {
public:
    HUD();

    void update(int score, int health);
    void render(sf::RenderWindow& window);

private:
    sf::Text scoreText;
    sf::Text healthText;
    sf::Font font;
};