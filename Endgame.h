#pragma once
#include <SFML/Graphics.hpp>

class Endgame {
public:
    Endgame(sf::RenderWindow& window, int score);
    void handleInput(sf::RenderWindow& window);
    void draw(sf::RenderWindow& window);
	void updateFinalScore(int score);
	bool isMouseOverPlayAgain(const sf::RenderWindow& window) const;
	int getScore() const;
	int getLives() const;

private:
    sf::Font font;
    sf::Text endgameTitle;
    sf::Text finalScoreText;
    sf::Text Playagain;
    sf::Sprite background;  // Background sprite
    sf::Texture backgroundTexture;  // Background texture
    int finalScore;
};

