#ifndef TETRIS_GAME_H
#define TETRIS_GAME_H

#include "Board.h"
#include "utils/AssetsManager.h"
#include "utils/PieceProjection.h"
#include "utils/PieceGenerator.h"
#include "utils/PieceHolder.h"
#include "utils/Score.h"

#include <SFML/Audio.hpp>
#include <random>
#include <memory>


class Game: public sf::Drawable {
public:
    static constexpr float SECONDS_BETWEEN_FALLS = 0.5f;
    static constexpr float SECONDS_BETWEEN_MOVES = 0.15f;
private:
    bool running{true};
    bool gameOver{false};
    bool canSwap{true};
    float secondsSinceLastFall{0};
    float secondsSinceLastMove{0};
    bool leftHeld{false};
    bool rightHeld{false};
    bool downHeld{false};
    std::unique_ptr<Piece> currentPiece{};
    AssetsManager manager{};
    PieceHolder holder{};
    Board board;
    PieceGenerator pieceGenerator;
    PieceProjection projection;
    PieceMover mover;
    Score score;
    sf::Music& theme;
private:
    void handleKeyPressed(const sf::Event& event);
    void handleKeyReleased(const sf::Event& event);
    void placeCurrentPiece();
    void lowerCurrentPiece();
    void swapHeldPiece();
    void calculateScore(int rowsCleared);
    void movePieces();
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
public:
    Game();

    void start();
    bool isRunning() const { return running; }
    void handleEvent(const sf::Event& event);
    void update(const sf::Time& time);
};


#endif //TETRIS_GAME_H
