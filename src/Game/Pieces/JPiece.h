#ifndef TETRIS_JPIECE_H
#define TETRIS_JPIECE_H

#include "Piece.h"

class JPiece: public Piece {
public:
    JPiece(const AssetsManager& manager, const BoardCoordinates& topLeft_):
            Piece(manager.getTexture(AssetsManager::Textures::JPiece), topLeft_,
                  {{
                           {{{1,0},{1,1},{1,2},{0,2}}},
                           {{{2,1},{1,1},{0,1},{0,0}}},
                           {{{1,2},{1,1},{1,0},{2,0}}},
                           {{{0,1},{1,1},{2,1},{2,2}}}
                   }}) {}
};


#endif //TETRIS_JPIECE_H
