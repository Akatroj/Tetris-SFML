#ifndef TETRIS_PIECEHOLDER_H
#define TETRIS_PIECEHOLDER_H


#include "../Pieces/Piece.h"
#include "../Pieces/FakePiece.h"
#include <memory>

class PieceHolder: public sf::Drawable {
public:
    const sf::Vector2f DRAW_POS{235, 200};
private:
    std::unique_ptr<Piece> heldPiece{};
    std::unique_ptr<FakePiece> visualization{};
private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
public:
    PieceHolder() = default;
    void clear();
    bool isEmpty() { return heldPiece == nullptr; }
    std::unique_ptr<Piece> hold(std::unique_ptr<Piece>&& piece);
};


#endif //TETRIS_PIECEHOLDER_H
