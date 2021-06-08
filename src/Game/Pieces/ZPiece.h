#ifndef TETRIS_ZPIECE_H
#define TETRIS_ZPIECE_H

#include "Piece.h"

class ZPiece: public Piece {
public:
    ZPiece(const AssetsManager& manager, const BoardCoordinates& topLeft_):
            Piece(manager.getTexture(AssetsManager::Textures::ZPiece), topLeft_,
                  {{
                           {{{0,0},{1,0},{1,1},{2,1}}},
                           {{{1,-1},{1,0},{0,0},{0,1}}},
                           {{{0,-1},{1,-1},{1,0},{2,0}}},
                           {{{1,1},{1,0},{2,0},{2,-1}}}
                   }}) {}
};


#endif //TETRIS_ZPIECE_H
