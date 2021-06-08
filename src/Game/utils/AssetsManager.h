#ifndef TETRIS_ASSETSMANAGER_H
#define TETRIS_ASSETSMANAGER_H

#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/Audio/Music.hpp>

static constexpr char ASSETS_FOLDER[] = "./assets/";

class AssetsManager {
public:
    enum class Textures;
private:
    std::string assets{ASSETS_FOLDER};
    std::map<Textures, std::unique_ptr<sf::Texture>> textures{};
    sf::Music theme{};
    sf::Font font{};
private:
    void load();
public:
    AssetsManager() { load(); }

    const sf::Texture& getTexture(const Textures& tex) const { return *textures.at(tex); }

    sf::Music& getTheme() { return theme; }

    sf::Font& getFont() { return font; }

    enum class Textures {
        Board, LinePiece, TPiece, OPiece, LPiece, JPiece, SPiece, ZPiece
    };

};


#endif //TETRIS_ASSETSMANAGER_H
