#ifndef TETRIS_FAKEPIECE_H
#define TETRIS_FAKEPIECE_H

#include "Piece.h"

#include <utility>

class FakePiece: public sf::Drawable {
    std::vector<sf::Sprite> pieceSprites{};
    Piece fakedPiece;
private:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    void resetSprites();

    inline float findMinX();
    inline float findMinY();
    inline float findMaxX();
    inline float findMaxY();
public:
    explicit FakePiece(Piece piece): fakedPiece{std::move(piece)} {
        resetSprites();
    }

    void moveTopLeftToPos(const sf::Vector2f& pos);
    void moveCenterToPos(const sf::Vector2f& pos);
    void setColor(sf::Color color);

    float getBottomY();

    void resetRotation();

};


#endif //TETRIS_FAKEPIECE_H
