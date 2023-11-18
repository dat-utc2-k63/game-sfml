
#include "Menu.h"

Menu::Menu(sf::RenderWindow& window) {
    if (!font.loadFromFile("../gameCplus/ttf/Roboto-Regular.ttf")) {
        // Handle font loading error
    }

    // Load the background texture and create a sprite
    if (!backgroundTexture.loadFromFile("../gameCplus/image/treeapple.jpeg")) {
        // Handle background texture loading error
    }
    background.setTexture(backgroundTexture);

    title.setFont(font);
    title.setCharacterSize(48);
    title.setFillColor(sf::Color::White);
    title.setString("Game Menu");
    title.setPosition(300, 100);

    playButton.setFont(font);
    playButton.setCharacterSize(36);
    playButton.setFillColor(sf::Color::White);
    playButton.setString("Play");
    playButton.setPosition(300, 250);

    highscoreButton.setFont(font);
    highscoreButton.setCharacterSize(36);
    highscoreButton.setFillColor(sf::Color::White);
    highscoreButton.setString("Highscore");
    highscoreButton.setPosition(300, 350);
}

void Menu::draw(sf::RenderWindow& window) {
    // Draw the background first
    window.draw(background);

    window.draw(title);
    window.draw(playButton);
    window.draw(highscoreButton);
}

bool Menu::isMouseOverPlayText(const sf::RenderWindow& window) {
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    return playButton.getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));
}
bool Menu::isMouseOverHighScoreText(const sf::RenderWindow& window) {
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    return highscoreButton.getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));
}

