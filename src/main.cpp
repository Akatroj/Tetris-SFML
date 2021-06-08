#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Game/utils/AssetsManager.h"
#include "Game/Game.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Tetris");
    window.setFramerateLimit(60);
    Game game{};
    sf::Clock clock{};
    game.start();
    while(game.isRunning()) {
        sf::Event event{};
        while(window.pollEvent(event)) {
            game.handleEvent(event);
        }
        game.update(clock.restart());
        window.draw(game);
        window.display();
    }

    window.close();
    return 0;
}
