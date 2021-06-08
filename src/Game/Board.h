#ifndef TETRIS_BOARD_H
#define TETRIS_BOARD_H

#include "Block.h"
#include "Pieces/Piece.h"

#include <array>

class Board: public sf::Drawable {
public:
    static constexpr int BOARD_HEIGHT = 20;
    static constexpr int BOARD_WIDTH = 10;
    static const BoardCoordinates STARTING_POS;
    static const sf::Vector2f BOARD_OFFSET; // texture has 4px border
    const sf::Vector2f TEXTURE_POSITION{300, 106};
private:
    std::array<std::array<std::unique_ptr<Block>, BOARD_WIDTH>, BOARD_HEIGHT> board;
    sf::Sprite sprite;
private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    static bool isRowFull(std::array<std::unique_ptr<Block>, BOARD_WIDTH>& row);
    int findAndClearFullRows();
    void moveBlocksOneDown(int emptyRow);
    static bool isBlockOutOfBounds(const Block& block) ;
public:
    explicit Board(const AssetsManager& manager): board{},
    sprite{manager.getTexture(AssetsManager::Textures::Board)} { sprite.setPosition(TEXTURE_POSITION); }

    void addBlock(const Block& block);
    void addPiece(const Piece& piece);
    int clearFullRows();
    void restart();
    bool isPieceOnValidPosition(const Piece& piece) const;
};
#endif //TETRIS_BOARD_H
