#ifndef TETRIS_PIECETYPES_H
#define TETRIS_PIECETYPES_H

enum class PieceType {
    LinePiece,
    TPiece,
    OPiece,
    LPiece,
    JPiece,
    SPiece,
    ZPiece
};

static constexpr PieceType PIECE_TYPES[] = {
        PieceType::LinePiece,
        PieceType::TPiece,
        PieceType::OPiece,
        PieceType::LPiece,
        PieceType::JPiece,
        PieceType::SPiece,
        PieceType::ZPiece
};

#endif //TETRIS_PIECETYPES_H
