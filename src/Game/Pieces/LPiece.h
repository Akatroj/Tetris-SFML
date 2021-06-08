#ifndef TETRIS_LPIECE_H
#define TETRIS_LPIECE_H

#include "../utils/BoardCoordinates.h"
#include "Piece.h"

class LPiece: public Piece {
public:
    LPiece(const AssetsManager& manager, const BoardCoordinates& topLeft_):
            Piece(manager.getTexture(AssetsManager::Textures::LPiece), topLeft_,
                  {{
                           {{{0,0},{0,1},{0,2},{1,2}}},
                           {{{-1,1},{0,1},{1,1},{-1,2}}},
                           {{{0,0},{0,1},{0,2},{-1,0}}},
                           {{{-1,1},{0,1},{1,1},{1,0}}},
                   }}) {}

};


#endif //TETRIS_LPIECE_H
