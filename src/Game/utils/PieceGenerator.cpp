#include "PieceGenerator.h"
#include "../Pieces/LinePiece.h"
#include "../Pieces/TPiece.h"
#include "../Pieces/OPiece.h"
#include "../Pieces/LPiece.h"
#include "../Pieces/JPiece.h"
#include "../Pieces/SPiece.h"
#include "../Pieces/ZPiece.h"
#include "../Board.h"

#include <random>


Piece PieceGenerator::getNext() {
    Piece piece = generatedPieces.back();
    generatedPieces.pop_back();
    visualizations.pop_back();
    generatePieces();
    return piece;
}

void PieceGenerator::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    for (const auto& visualization : visualizations) {
        target.draw(visualization);
    }
}

void PieceGenerator::refreshVisualisations() {
    visualizations.clear();
    sf::Vector2f curr{offset};
    for (auto it = generatedPieces.rbegin(); it != generatedPieces.rend(); it++) {
        visualizations.emplace_back(*it);
        visualizations.back().moveTopLeftToPos(curr);
        curr.y = visualizations.back().getBottomY() + 20;
    }
    std::reverse(visualizations.begin(), visualizations.end());
}

void PieceGenerator::refillPool() {
    generationPool.clear();
    std::for_each(std::begin(PIECE_TYPES), std::end(PIECE_TYPES),[this](auto type) {
        generationPool.push_back(type);
        generationPool.push_back(type);
    });

    std::shuffle(generationPool.begin(), generationPool.end(),
                 std::mt19937(std::random_device{}()));
}

void PieceGenerator::generatePieces() {
    unsigned int piecesToGen = PIECES_DISPLAYED - generatedPieces.size();
    for (int i = 0; i<piecesToGen; i++) {
        PieceType type = generationPool.back();
        generationPool.pop_back();
        generatedPieces.push_front(makePiece(type));
        refreshVisualisations();
        if (generationPool.empty()) refillPool();
    }
}

Piece PieceGenerator::makePiece(PieceType type) {
    switch (type) {
        case PieceType::LinePiece:
            return LinePiece(manager, Board::STARTING_POS);
        case PieceType::TPiece:
            return TPiece(manager, Board::STARTING_POS);
        case PieceType::OPiece:
            return OPiece(manager, Board::STARTING_POS);
        case PieceType::LPiece:
            return LPiece(manager, Board::STARTING_POS);
        case PieceType::JPiece:
            return JPiece(manager, Board::STARTING_POS);
        case PieceType::SPiece:
            return SPiece(manager, Board::STARTING_POS);
        case PieceType::ZPiece:
            return ZPiece(manager, Board::STARTING_POS);
        default:
            return LinePiece(manager, Board::STARTING_POS);
    }
}
