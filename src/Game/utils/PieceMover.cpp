#include "PieceMover.h"

bool PieceMover::rotateIfPossible(Piece& piece, Rotation rotation) const {
    for(Move m : MOVES) {
        Piece copy{piece};
        move(copy, m);
        if(canRotateWithoutMoving(copy, rotation)) {
            move(piece, m);
            rotateWithoutMoving(piece, rotation);
            return true;
        }
    }
    return false;
}

bool PieceMover::canRotate(const Piece& piece, Rotation rotation) const {
    Piece copy{piece};
    return rotateIfPossible(copy, rotation);
}

void PieceMover::rotate(Piece& piece, Rotation rotation) const {
    rotateIfPossible(piece, rotation);
}

bool PieceMover::canRotateWithoutMoving(Piece& piece, Rotation rotation) const {
    Piece copy{piece};
    switch(rotation) {
        case Rotation::Clockwise:
            copy.rotateClockwise();
            break;
        case Rotation::CounterClockwise:
            copy.rotateCounterClockwise();
            break;
        case Rotation::NoRotation:
            break;
    }
    return board.isPieceOnValidPosition(copy);
}

void PieceMover::rotateWithoutMoving(Piece& piece, Rotation rotation) {
    switch(rotation) {
        case Rotation::Clockwise:
            piece.rotateClockwise();
            break;
        case Rotation::CounterClockwise:
            piece.rotateCounterClockwise();
            break;
        case Rotation::NoRotation:
            break;
    }
}

bool PieceMover::canMove(const Piece& piece, Move move) const {
    Piece copy{piece};
    switch(move) {
        case Move::Left:
            copy.moveLeft();
            break;
        case Move::Right:
            copy.moveRight();
            break;
        case Move::Down:
            copy.moveDown();
            break;
        case Move::NoMove:
            break;
    }
    return board.isPieceOnValidPosition(copy);
}

void PieceMover::moveWithoutChecking(Piece &piece, PieceMover::Move move) {
    switch (move) {
        case Move::Left:
            piece.moveLeft();
            break;
        case Move::Right:
            piece.moveRight();
            break;
        case Move::Down:
            piece.moveDown();
            break;
        case Move::NoMove:
            break;
    }
}

void PieceMover::move(Piece& piece, Move move) const {
    if (canMove(piece, move)) moveWithoutChecking(piece, move);
}

void PieceMover::moveToBottom(Piece& piece) const {
    while (canMove(piece, Move::Down)) piece.moveDown();
}
