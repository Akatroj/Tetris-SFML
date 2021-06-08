#include "PieceProjection.h"

void PieceProjection::reset(const Piece& piece) {
    Piece copy{piece};
    mover.moveToBottom(copy);
    visualization = std::make_unique<FakePiece>(copy);
    visualization->setColor(colorMask);
}

void PieceProjection::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    if (visualization == nullptr) return;
    target.draw(*visualization, states);
}
