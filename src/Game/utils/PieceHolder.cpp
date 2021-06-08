#include "PieceHolder.h"

void PieceHolder::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    if (visualization == nullptr) return;
    target.draw(*visualization);
}

void PieceHolder::clear() {
    visualization.reset();
    heldPiece.reset();
}

std::unique_ptr<Piece> PieceHolder::hold(std::unique_ptr<Piece>&& piece) {
    auto temp = std::move(heldPiece);
    heldPiece = std::move(piece);
    heldPiece->resetRotation();
    visualization = std::make_unique<FakePiece>(*heldPiece);
    visualization->resetRotation();
    visualization->moveCenterToPos(DRAW_POS);
    return temp;
}
