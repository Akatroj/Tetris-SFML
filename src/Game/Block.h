#ifndef TETRIS_BLOCK_H
#define TETRIS_BLOCK_H

#include "utils/BoardCoordinates.h"

#include <SFML/Graphics.hpp>

class Block: public sf::Drawable {
public:
    static constexpr float BLOCK_SIZE = 19; // texture is 20x20 px but setting size as 19 eliminates doubled border
private:
    sf::Sprite sprite;
    BoardCoordinates boardCoordinates;
private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
public:
    Block(const sf::Texture& texture, const BoardCoordinates& boardCoordinates_);

    void moveDown();
    void offsetCoordinates(const BoardCoordinates& offset);
    void setCoordinates(const BoardCoordinates& newCoordinates);
    const BoardCoordinates& getBoardCoordinates() const { return boardCoordinates; }
    const sf::Vector2f& getPixelPosition() const { return sprite.getPosition(); }
    const sf::Sprite& getSprite() const { return sprite; }
};


#endif //TETRIS_BLOCK_H
