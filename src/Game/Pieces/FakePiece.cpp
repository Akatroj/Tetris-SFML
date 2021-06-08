#include <cmath>
#include <iostream>
#include "FakePiece.h"

void FakePiece::moveTopLeftToPos(const sf::Vector2f& pos) {
    float minX = findMinX();

    float minY = findMinY();

    sf::Vector2f reset{minX, minY};

    std::for_each(pieceSprites.begin(), pieceSprites.end(), [reset, pos]
    (sf::Sprite& sprite) { sprite.setPosition(sprite.getPosition() - reset + pos); });

}

float FakePiece::getBottomY() {
    std::vector<float> bottomYVec{};
    std::transform(pieceSprites.begin(), pieceSprites.end(), std::back_inserter(bottomYVec),
                   [] (sf::Sprite& sprite) {
        return sprite.getGlobalBounds().top + sprite.getGlobalBounds().height;
    });
    return *std::max_element(bottomYVec.begin(), bottomYVec.end());
}

void FakePiece::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    for (const auto& sprite : pieceSprites) {
        target.draw(sprite);
    }
}

void FakePiece::setColor(sf::Color color) {
    for(auto& sprite : pieceSprites) {
        sprite.setColor(color);
    }
}

void FakePiece::moveCenterToPos(const sf::Vector2f& pos) {
    float minX = findMinX();
    float minY = findMinY();
    float centerX = std::floor((findMaxX()+20 + minX)/2);
    float centerY = std::floor((findMaxY()+20 + minY)/2);

    sf::Vector2f offset{minX-centerX, minY-centerY};
    moveTopLeftToPos(pos+offset);
}

float FakePiece::findMinX() {
    return std::min_element(pieceSprites.begin(), pieceSprites.end(),
                                  [] (const sf::Sprite& sprite1, const sf::Sprite& sprite2) {
                                      return sprite1.getPosition().x < sprite2.getPosition().x;
                                  })->getPosition().x;
}

float FakePiece::findMinY() {
    return std::min_element(pieceSprites.begin(), pieceSprites.end(),[]
            (const sf::Sprite& sprite1, const sf::Sprite& sprite2) {
        return sprite1.getPosition().y < sprite2.getPosition().y;
    })->getPosition().y;
}

float FakePiece::findMaxX() {
    return std::max_element(pieceSprites.begin(), pieceSprites.end(),
                            [] (const sf::Sprite& sprite1, const sf::Sprite& sprite2) {
                                return sprite1.getPosition().x < sprite2.getPosition().x;
                            })->getPosition().x;
}

float FakePiece::findMaxY() {
    return std::max_element(pieceSprites.begin(), pieceSprites.end(),[]
            (const sf::Sprite& sprite1, const sf::Sprite& sprite2) {
        return sprite1.getPosition().y < sprite2.getPosition().y;
    })->getPosition().y;
}

void FakePiece::resetSprites() {
    pieceSprites.clear();
    for (const Block& block : fakedPiece.getBlocks()) {
        pieceSprites.push_back(block.getSprite());
    }
}

void FakePiece::resetRotation() {
    fakedPiece.resetRotation();
    resetSprites();
}
