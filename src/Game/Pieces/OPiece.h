#ifndef TETRIS_OPIECE_H
#define TETRIS_OPIECE_H

#include "Piece.h"

class OPiece: public Piece {
public:
    OPiece(const AssetsManager& manager, const BoardCoordinates& topLeft_):
            Piece(manager.getTexture(AssetsManager::Textures::OPiece), topLeft_,
                  {{
                           {{{0,0},{1,0},{0,1},{1,1}}},
                           {{{0,0},{1,0},{0,1},{1,1}}},
                           {{{0,0},{1,0},{0,1},{1,1}}},
                           {{{0,0},{1,0},{0,1},{1,1}}},
                   }}) {}
};


#endif //TETRIS_OPIECE_H
