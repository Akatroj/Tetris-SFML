#ifndef TETRIS_PIECEGENERATOR_H
#define TETRIS_PIECEGENERATOR_H


#include "../Pieces/Piece.h"
#include "../Pieces/PieceTypes.h"
#include "../Pieces/FakePiece.h"

#include <vector>
#include <list>
#include <random>
#include <functional>

class PieceGenerator: public sf::Drawable {
    static constexpr unsigned int PIECES_DISPLAYED = 5;
    const sf::Vector2f offset{540, 120};
    const sf::Vector2f space{0, 20};
    std::vector<PieceType> generationPool{};
    std::list<Piece> generatedPieces{};
    std::vector<FakePiece> visualizations{};
    const AssetsManager& manager;
private:
    void refillPool();
    void generatePieces();
    void refreshVisualisations();
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    Piece makePiece(PieceType type);
public:
    PieceGenerator(const AssetsManager& manager_): manager{manager_} {
        refillPool();
        generatePieces();
    };
    Piece getNext();

};


#endif //TETRIS_PIECEGENERATOR_H
