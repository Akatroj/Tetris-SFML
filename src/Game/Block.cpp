#include "Block.h"
#include "Board.h"

Block::Block(const sf::Texture& texture, const BoardCoordinates& boardCoordinates_):
        sprite{texture}, boardCoordinates{boardCoordinates_} {
    sf::Vector2f pixelCoordinates{
            static_cast<float>(boardCoordinates.column)*BLOCK_SIZE,
            static_cast<float>(boardCoordinates.row)*BLOCK_SIZE};
    sprite.setPosition(pixelCoordinates + Board::BOARD_OFFSET);
}


void Block::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(sprite, states);
}

void Block::moveDown() {
    sf::Vector2f currentPos = sprite.getPosition();
    sprite.setPosition(currentPos.x, currentPos.y + BLOCK_SIZE);
    boardCoordinates.row++;
}

void Block::offsetCoordinates(const BoardCoordinates& offset) {
    setCoordinates(boardCoordinates + offset);
}

void Block::setCoordinates(const BoardCoordinates& newCoordinates) {
    boardCoordinates = newCoordinates;
    float newX = (float) boardCoordinates.column*BLOCK_SIZE + Board::BOARD_OFFSET.x;
    float newY = (float) boardCoordinates.row*BLOCK_SIZE + Board::BOARD_OFFSET.y;
    sprite.setPosition(newX, newY);
}
