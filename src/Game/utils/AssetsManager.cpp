#include "AssetsManager.h"

void AssetsManager::load() {

    // audio
    theme.openFromFile(assets + "Tetris.ogg");

    // font
    font.loadFromFile(assets + "simplistic_regular.ttf");

    // textures
    sf::Texture texture{};

    texture.loadFromFile(assets + "pitv3.png");
    textures.insert(std::make_pair(Textures::Board, std::make_unique<sf::Texture>(texture)));

    texture.loadFromFile(assets + "I.png");
    textures.insert(std::make_pair(Textures::LinePiece, std::make_unique<sf::Texture>(texture)));

    texture.loadFromFile(assets + "L.png");
    textures.insert(std::make_pair(Textures::LPiece, std::make_unique<sf::Texture>(texture)));

    texture.loadFromFile(assets + "J.png");
    textures.insert(std::make_pair(Textures::JPiece, std::make_unique<sf::Texture>(texture)));

    texture.loadFromFile(assets + "Z.png");
    textures.insert(std::make_pair(Textures::ZPiece, std::make_unique<sf::Texture>(texture)));

    texture.loadFromFile(assets + "S.png");
    textures.insert(std::make_pair(Textures::SPiece, std::make_unique<sf::Texture>(texture)));

    texture.loadFromFile(assets + "O.png");
    textures.insert(std::make_pair(Textures::OPiece, std::make_unique<sf::Texture>(texture)));

    texture.loadFromFile(assets + "T.png");
    textures.insert(std::make_pair(Textures::TPiece, std::make_unique<sf::Texture>(texture)));

}
