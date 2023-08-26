//This code snippet demonstrates how to handle player character movement using keyboard input in a 2D game.

#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Player Movement");

    sf::CircleShape player(20);
    player.setFillColor(sf::Color::Green);
    player.setPosition(400, 300);

    float playerSpeed = 5.0f;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            player.move(0, -playerSpeed);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            player.move(0, playerSpeed);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            player.move(-playerSpeed, 0);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            player.move(playerSpeed, 0);

        window.clear();
        window.draw(player);
        window.display();
    }

    return 0;
}