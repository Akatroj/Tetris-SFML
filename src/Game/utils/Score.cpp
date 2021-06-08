#include "Score.h"

Score::Score(AssetsManager &manager): currentScore{0}, highScore{0},
currentScoreText{"", manager.getFont()}, highScoreText{"", manager.getFont()} {
    highScoreText.setPosition(HISCORE_DRAW_POS);
    highScoreText.setFillColor(sf::Color{32, 178, 170});
    currentScoreText.setFillColor(sf::Color{32, 178, 170});
    currentScoreText.setPosition(SCORE_DRAW_POS);
    reset();
}


void Score::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(currentScoreText, states);
    target.draw(highScoreText, states);
}

void Score::addPoints(long points) {
    currentScore += points;
    highScore = std::max(highScore, currentScore);
    updateTexts();
}

void Score::reset() {
    currentScore = 0;
    updateTexts();
}

void Score::updateTexts() {
    currentScoreText.setString("Score " + std::to_string(currentScore));
    highScoreText.setString("HighScore " + std::to_string(highScore));
}
