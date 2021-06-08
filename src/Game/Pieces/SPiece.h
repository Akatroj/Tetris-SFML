#ifndef TETRIS_SPIECE_H
#define TETRIS_SPIECE_H

#include "Piece.h"

class SPiece: public Piece {
public:
    SPiece(const AssetsManager& manager, const BoardCoordinates& topLeft_):
            Piece(manager.getTexture(AssetsManager::Textures::SPiece), topLeft_,
                  {{
                           {{{2,0},{1,0},{1,1},{0,1}}},
                           {{{1,1},{1,0},{0,0},{0,-1}}},
                           {{{2,-1},{1,-1},{1,0},{0,0}}},
                           {{{2,1},{2,0},{1,0},{1,-1}}}
                   }}) {}
};


#endif //TETRIS_SPIECE_H
