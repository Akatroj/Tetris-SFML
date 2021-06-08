#include "Piece.h"

Piece::Piece(const sf::Texture &texture, const BoardCoordinates &topLeft_,
             const std::array<std::array<BoardCoordinates, BLOCKS_AMOUNT>, ROTATIONS_AMOUNT>& offsets):
        currentRotation{0}, topLeft{topLeft_}, rotationBlockOffsets{offsets},
        blocks{
                Block{texture, topLeft+offsets[0][0]},
                Block{texture, topLeft+offsets[0][1]},
                Block{texture, topLeft+offsets[0][2]},
                Block{texture, topLeft+offsets[0][3]}
        }
{}


void Piece::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    for (const Block& block : blocks) {
        target.draw(block);
    }
}

void Piece::moveDown() {
    topLeft.row++;
    for (Block& block : blocks) {
        block.moveDown();
    }
}

void Piece::offsetMyBlocks(const BoardCoordinates& offset) {
    for (Block& block : blocks) {
        block.offsetCoordinates(offset);
    }
}

void Piece::rotationHelper(const std::array<BoardCoordinates, BLOCKS_AMOUNT>& rotationOffsets) {
    for (int i = 0; i<BLOCKS_AMOUNT; i++) {
        blocks[i].setCoordinates(topLeft + rotationOffsets[i]);
    }
}

void Piece::moveLeft() {
    topLeft.column--;
    offsetMyBlocks(BoardCoordinates{-1, 0});
}

void Piece::moveRight() {
    topLeft.column++;
    offsetMyBlocks(BoardCoordinates{1, 0});
}

void Piece::rotateClockwise() {
    currentRotation++;
    currentRotation %= ROTATIONS_AMOUNT;
    rotationHelper(rotationBlockOffsets[currentRotation]);
}

void Piece::rotateCounterClockwise() {
    currentRotation--;
    currentRotation %= ROTATIONS_AMOUNT;
    rotationHelper(rotationBlockOffsets[currentRotation]);
}

void Piece::setBoardCoordinates(const BoardCoordinates& newCoordinates) {
    topLeft = newCoordinates;
    rotationHelper(rotationBlockOffsets[currentRotation]);
}

const std::array<Block, Piece::BLOCKS_AMOUNT> &Piece::getBlocks() const {
    return blocks;
}

void Piece::resetRotation() {
    currentRotation = 0;
    rotationHelper(rotationBlockOffsets[currentRotation]);
}
