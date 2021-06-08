#include "Board.h"

const sf::Vector2f Board::BOARD_OFFSET{304, 110}; // NOLINT(cert-err58-cpp)
const BoardCoordinates Board::STARTING_POS{4, 0}; // NOLINT(cert-err58-cpp)

void Board::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(sprite, states);
    for (const auto& row : board) {
        for (const auto& blockPtr : row) {
            if (blockPtr != nullptr) target.draw(*blockPtr, states);
        }
    }
}

void Board::addBlock(const Block& block) {
    BoardCoordinates coords = block.getBoardCoordinates();
    board[coords.row][coords.column] = std::make_unique<Block>(block);
}

bool Board::isRowFull(std::array<std::unique_ptr<Block>, BOARD_WIDTH>& row) {
    return std::all_of(row.begin(), row.end(), [](auto& blockPtr){ return blockPtr != nullptr; });
}

void Board::moveBlocksOneDown(int emptyRow) {
    for (int i = emptyRow-1; i>-1; i--) {
        for(auto& blockPtr : board[i]) {
            if (blockPtr != nullptr) {
                int j = blockPtr->getBoardCoordinates().column;
                blockPtr->moveDown();
                board[i+1][j] = std::move(board[i][j]);
            }
        }
    }
}

int Board::findAndClearFullRows() {
    int counter = 0;
    for (int i = BOARD_HEIGHT - 1; i>-1; i--) {
        if(isRowFull(board[i])) {
            counter++;
            for (auto& blockPtr : board[i]) {
                blockPtr.reset();
            }
            moveBlocksOneDown(i);
        }
    }
    return counter;
}

int Board::clearFullRows() {
    int counter = 0;
    int temp = -1;
    while(temp != 0) {
        temp = findAndClearFullRows();
        counter += temp;
    }
    return counter;
}

void Board::restart() {
    for (auto& row : board) {
        for (auto& blockPtr : row) {
            blockPtr.reset(nullptr);
        }
    }
}

bool Board::isPieceOnValidPosition(const Piece& piece) const {
    const auto& blocks = piece.getBlocks();
    return std::none_of(blocks.begin(), blocks.end(),[this](const Block& block) {
        BoardCoordinates coords = block.getBoardCoordinates();
        return isBlockOutOfBounds(block) || board[coords.row][coords.column] != nullptr;
    });
}

bool Board::isBlockOutOfBounds(const Block& block) {
    BoardCoordinates coords = block.getBoardCoordinates();
    return coords.row < 0 || coords.row >= BOARD_HEIGHT || coords.column < 0 || coords.column >= BOARD_WIDTH;
}

void Board::addPiece(const Piece& piece) {
    for (const auto& block : piece.getBlocks()) {
        addBlock(block);
    }
}
