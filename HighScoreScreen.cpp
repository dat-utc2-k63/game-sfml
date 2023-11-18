
#include "HighScoreScreen.h"

HighScoreScreen::HighScoreScreen(sf::RenderWindow& window) {
    if (!font.loadFromFile("../gameCplus/ttf/Roboto-Regular.ttf")) {
        // Handle font loading error
    }

    if (!backgroundTexture.loadFromFile("../gameCplus/image/treeapple.jpeg")) {
        // Handle background texture loading error
    }
    background.setTexture(backgroundTexture);

    highscoreTitle.setFont(font);
    highscoreTitle.setCharacterSize(48);
    highscoreTitle.setFillColor(sf::Color::Red);
    highscoreTitle.setString("High Scores");
    highscoreTitle.setPosition(600, 50);

    highscoreList.setFont(font);
    highscoreList.setCharacterSize(36);
    highscoreList.setFillColor(sf::Color::White);
    highscoreList.setPosition(600, 150);

    readHighScoresFromFile();
    returnButton.setFont(font);
    returnButton.setCharacterSize(48);
    returnButton.setFillColor(sf::Color::White);
    returnButton.setString("Return");
    returnButton.setPosition(600, 650);
}

void HighScoreScreen::draw(sf::RenderWindow& window, const std::vector<HighScoreEntry>& highScores) {
    window.draw(background);
    window.draw(highscoreTitle);

    std::string highscoreText;
    for (const auto& entry : highScores) {
        highscoreText += entry.playerName + ": " + std::to_string(entry.score) + "\n";
    }
    highscoreList.setString(highscoreText);
    window.draw(highscoreList);
    window.draw(returnButton);
}

std::vector<HighScoreEntry> HighScoreScreen::readHighScoresFromFile() {
    std::ifstream file("highscores.txt");
    std::vector<HighScoreEntry> highScores;  // Th�m d�ng n�y
    if (file.is_open()) {
        highScores.clear();

        std::string playerName;
        int score;

        while (file >> playerName >> score) {
            HighScoreEntry entry = {playerName, score};
            highScores.push_back(entry);
        }

        file.close();
    }
    return highScores;  // Th�m d�ng n�y
}

void HighScoreScreen::writeHighScoresToFile(const std::vector<HighScoreEntry>& highScores) {
    std::ofstream file("highscores.txt");
    if (file.is_open()) {
        for (const auto& entry : highScores) {
            file << entry.playerName << " " << entry.score << "\n";
        }

        file.close();
    }
}
bool HighScoreScreen::isMouseOverReturn(const sf::RenderWindow& window) {
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    return returnButton.getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));
}
