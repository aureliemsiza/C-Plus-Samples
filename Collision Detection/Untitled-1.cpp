//This code snippet demonstrates simple collision detection between two rectangles in a 2D game.

#include <iostream>

struct Rectangle {
    float x, y, width, height;
};

bool checkCollision(const Rectangle& rect1, const Rectangle& rect2) {
    return (rect1.x < rect2.x + rect2.width &&
            rect1.x + rect1.width > rect2.x &&
            rect1.y < rect2.y + rect2.height &&
            rect1.y + rect1.height > rect2.y);
}

int main() {
    Rectangle player = { 100, 100, 50, 50 };
    Rectangle obstacle = { 200, 150, 100, 100 };

    if (checkCollision(player, obstacle)) {
        std::cout << "Collision detected!\n";
    } else {
        std::cout << "No collision.\n";
    }

    return 0;
}