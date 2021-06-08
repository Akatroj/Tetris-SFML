#ifndef TETRIS_TPIECE_H
#define TETRIS_TPIECE_H

#include "Piece.h"

class TPiece: public Piece {
public:
    TPiece(const AssetsManager& manager, const BoardCoordinates& topLeft_):
            Piece(manager.getTexture(AssetsManager::Textures::TPiece), topLeft_,
                  {{
                           {{{0,0},{1,0},{2,0},{1,1}}},
                           {{{1,1},{1,0},{1,-1},{2,0}}},
                           {{{0,0},{1,0},{2,0},{1,-1}}},
                           {{{1,-1},{1,0},{1,1},{0,0}}}
                   }}) { }
};


#endif //TETRIS_TPIECE_H
