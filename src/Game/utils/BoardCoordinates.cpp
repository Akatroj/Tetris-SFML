#include "BoardCoordinates.h"

BoardCoordinates operator+(const BoardCoordinates& lhs, const BoardCoordinates& rhs) {
    return BoardCoordinates{lhs.column + rhs.column, lhs.row + rhs.row};
}

BoardCoordinates operator-(const BoardCoordinates& lhs, const BoardCoordinates& rhs) {
    return BoardCoordinates{lhs.column - rhs.column, lhs.row - rhs.row};
}
