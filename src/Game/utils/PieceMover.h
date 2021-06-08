#ifndef TETRIS_PIECEMOVER_H
#define TETRIS_PIECEMOVER_H


#include "../Board.h"

class PieceMover {
    const Board& board;
public:
    enum class Move {
        Left, Right, Down, NoMove
    };

    enum class Rotation {
        Clockwise, CounterClockwise, NoRotation
    };

    static constexpr Move MOVES[] = { Move::NoMove, Move::Left, Move::Right, Move::Down };
    static constexpr Rotation ROTATIONS[] = { Rotation::NoRotation, Rotation::Clockwise, Rotation::CounterClockwise };
private:
    bool rotateIfPossible(Piece& piece, Rotation rotation) const;
public:
    explicit PieceMover(const Board& board_): board{board_} { }

    bool canRotate(const Piece& piece, Rotation rotation) const;

    void rotate(Piece& piece, Rotation rotation) const;

    bool canRotateWithoutMoving(Piece& piece, Rotation rotation) const;

    static void rotateWithoutMoving(Piece& piece, Rotation rotation);

    bool canMove(const Piece& piece, Move move) const;

    void move(Piece& piece, Move move) const;

    static void moveWithoutChecking(Piece& piece, Move move);

    void moveToBottom(Piece& piece) const;
};

#endif //TETRIS_PIECEMOVER_H
