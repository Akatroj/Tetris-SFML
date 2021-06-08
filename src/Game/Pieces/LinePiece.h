#ifndef TETRIS_LINEPIECE_H
#define TETRIS_LINEPIECE_H

#include "Piece.h"

class LinePiece: public Piece {
public:
    LinePiece(const AssetsManager& manager, const BoardCoordinates& topLeft_):
                   Piece(manager.getTexture(AssetsManager::Textures::LinePiece), topLeft_,
                         {{
                                  {{{0,0},{0,1},{0,2},{0,3}}},
                                  {{{1,1},{0,1},{-1,1},{-2,1}}},
                                  {{{0,2},{0,1},{0,0},{0,-1}}},
                                  {{{-1,1},{0,1},{1,1},{2,1}}},
                          }}) {}
};


#endif //TETRIS_LINEPIECE_H
