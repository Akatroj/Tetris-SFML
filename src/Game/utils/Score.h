#ifndef TETRIS_SCORE_H
#define TETRIS_SCORE_H

#include <SFML/Graphics.hpp>
#include "AssetsManager.h"

class Score: public sf::Drawable {
public:
    const sf::Vector2f HISCORE_DRAW_POS{50, 20};
    const sf::Vector2f SCORE_DRAW_POS{50, 60};
private:
    long currentScore;
    long highScore;
    sf::Text currentScoreText;
    sf::Text highScoreText;
private:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    inline void updateTexts();
public:
    explicit Score(AssetsManager& manager);
    void addPoints(long points);
    void reset();
};


#endif //TETRIS_SCORE_H
