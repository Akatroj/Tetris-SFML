#include "Game.h"

Game::Game(): board{manager}, pieceGenerator{manager}, mover{board}, projection{mover},
theme{manager.getTheme()}, score{manager} {}


void Game::start() {
    board.restart();
    gameOver = false;
    score.reset();
    holder.clear();
    currentPiece = std::make_unique<Piece>(pieceGenerator.getNext());
    projection.reset(*currentPiece);
    theme.setLoop(true);
    theme.play();
}

void Game::handleEvent(const sf::Event& event) {
    switch(event.type) {
        case sf::Event::Closed:
            running = false;
            break;
        case sf::Event::KeyPressed:
            handleKeyPressed(event);
            break;
        case sf::Event::KeyReleased:
            handleKeyReleased(event);
            break;
        default:
            return;
    }
}

void Game::handleKeyPressed(const sf::Event& event) {
    if(gameOver) return;
    switch(event.key.code) {
        case sf::Keyboard::Left:
            leftHeld = true;
            movePieces();
            break;
        case sf::Keyboard::Right:
            rightHeld = true;
            movePieces();
            break;
        case sf::Keyboard::Down:
            downHeld = true;
            movePieces();
            break;
        default:
            return;
    }
}


void Game::handleKeyReleased(const sf::Event& event) {
    if(gameOver) {
        if (event.key.code == sf::Keyboard::Enter) start();
        return;
    }

    switch(event.key.code) {
        case sf::Keyboard::Left:
            leftHeld = false;
            break;
        case sf::Keyboard::Right:
            rightHeld = false;
            break;
        case sf::Keyboard::Down:
            downHeld = false;
            break;
        case sf::Keyboard::Z:
            mover.rotate(*currentPiece, PieceMover::Rotation::CounterClockwise);
            projection.reset(*currentPiece);
            break;
        case sf::Keyboard::X:
            mover.rotate(*currentPiece, PieceMover::Rotation::Clockwise);
            projection.reset(*currentPiece);
            break;
        case sf::Keyboard::C:
            swapHeldPiece();
            break;
        case sf::Keyboard::Space:
            mover.moveToBottom(*currentPiece);
            placeCurrentPiece();
            break;
        default:
            return;
    }
}

void Game::update(const sf::Time& time) {
    if (!gameOver) {
        secondsSinceLastFall += time.asSeconds();
        secondsSinceLastMove += time.asSeconds();
        if (secondsSinceLastMove > SECONDS_BETWEEN_MOVES) {
            movePieces();
        }
        if (secondsSinceLastFall > SECONDS_BETWEEN_FALLS) {
            lowerCurrentPiece();
        }

    }
}

void Game::placeCurrentPiece() {
    board.addPiece(*currentPiece);
    int rowsCleared = board.clearFullRows();
    calculateScore(rowsCleared);

    currentPiece = std::make_unique<Piece>(pieceGenerator.getNext());
    if (!board.isPieceOnValidPosition(*currentPiece)) {
        gameOver = true;
        theme.stop();
    }
    projection.reset(*currentPiece);
    canSwap = true;
}

void Game::lowerCurrentPiece() {
     {
        if (mover.canMove(*currentPiece, PieceMover::Move::Down))
            PieceMover::moveWithoutChecking(*currentPiece, PieceMover::Move::Down);
        else {
            placeCurrentPiece();
        }
         secondsSinceLastFall = 0;
    }
}

void Game::swapHeldPiece() {
    if (!canSwap) return;
    currentPiece = std::move(holder.hold(std::move(currentPiece)));
    if (currentPiece == nullptr) currentPiece = std::make_unique<Piece>(pieceGenerator.getNext());
    currentPiece->setBoardCoordinates(Board::STARTING_POS);
    canSwap = false;
    projection.reset(*currentPiece);
}

void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.clear(sf::Color(255, 245, 238));
    target.draw(board, states);
    target.draw(score, states);
    if (!gameOver) {
        target.draw(*currentPiece, states);
        target.draw(projection, states);
        target.draw(pieceGenerator, states);
        target.draw(holder, states);
    }
}

void Game::calculateScore(int rowsCleared) {
    long scoreGained;
    switch(rowsCleared) {
        case 0:
            return;
        case 1:
            scoreGained = 40;
            break;
        case 2:
            scoreGained = 100;
            break;
        case 3:
            scoreGained = 300;
            break;
        case 4:
            scoreGained = 1200;
            break;
        default:
            scoreGained = 1000;
            break;
    }

    score.addPoints(scoreGained);
}

void Game::movePieces() {
    secondsSinceLastMove = 0;
    if (leftHeld) mover.move(*currentPiece, PieceMover::Move::Left);
    else if (rightHeld) mover.move(*currentPiece, PieceMover::Move::Right);
    if (downHeld) mover.move(*currentPiece, PieceMover::Move::Down);

    if (leftHeld || rightHeld) projection.reset(*currentPiece);
}
