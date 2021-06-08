#ifndef TETRIS_PIECEPROJECTION_H
#define TETRIS_PIECEPROJECTION_H


#include "../Pieces/Piece.h"
#include "PieceMover.h"
#include "../Pieces/FakePiece.h"

class PieceProjection: public sf::Drawable {
    static constexpr int alphaValue = static_cast<int>(255*0.45);
    const sf::Color colorMask{255, 255, 255, alphaValue}; // set sprite opacity to 45%
    const PieceMover& mover;
    std::unique_ptr<FakePiece> visualization{};
private:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
public:
    explicit PieceProjection(const PieceMover& mover_): mover{mover_} { }
    void reset(const Piece& piece);
};


#endif //TETRIS_PIECEPROJECTION_H
