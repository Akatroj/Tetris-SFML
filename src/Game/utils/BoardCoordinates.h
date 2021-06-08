#ifndef TETRIS_BOARDCOORDINATES_H
#define TETRIS_BOARDCOORDINATES_H

class BoardCoordinates {
public:
    int column;
    int row;
public:
    BoardCoordinates(int column_, int row_): column{column_}, row{row_} {}
    friend BoardCoordinates operator+(const BoardCoordinates& lhs, const BoardCoordinates& rhs);
    friend BoardCoordinates operator-(const BoardCoordinates& lhs, const BoardCoordinates& rhs);
};

#endif //TETRIS_BOARDCOORDINATES_H
