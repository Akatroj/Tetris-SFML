#ifndef TETRIS_PIECE_H
#define TETRIS_PIECE_H

#include "../Block.h"
#include "../utils/BoardCoordinates.h"
#include "../utils/AssetsManager.h"

#include <array>



class Piece: public sf::Drawable {
public:
    static constexpr int BLOCKS_AMOUNT = 4;
    static constexpr int ROTATIONS_AMOUNT = 4;
private:
    unsigned char currentRotation;
    BoardCoordinates topLeft;
    std::array<Block, BLOCKS_AMOUNT> blocks;
    std::array<std::array<BoardCoordinates, BLOCKS_AMOUNT>, ROTATIONS_AMOUNT> rotationBlockOffsets;

private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
protected:
    Piece(const sf::Texture& texture, const BoardCoordinates& topLeft_,
          const std::array<std::array<BoardCoordinates, BLOCKS_AMOUNT>, ROTATIONS_AMOUNT>& offsets);
    void offsetMyBlocks(const BoardCoordinates& offset);
    void rotationHelper(const std::array<BoardCoordinates, BLOCKS_AMOUNT>& rotationOffsets);
public:
    Piece() = delete;
    void moveDown();
    void moveLeft();
    void moveRight();
    void rotateClockwise();
    void rotateCounterClockwise();
    void resetRotation();
    void setBoardCoordinates(const BoardCoordinates& newCoordinates);
    const std::array<Block, BLOCKS_AMOUNT>& getBlocks() const;
};


#endif //TETRIS_PIECE_H
