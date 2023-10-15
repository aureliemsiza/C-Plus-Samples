#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

class Player {
public:
    string name;
    int health;
    int attack;

    Player(string playerName, int playerHealth, int playerAttack) {
        name = playerName;
        health = playerHealth;
        attack = playerAttack;
    }

    void takeDamage(int damage) {
        health -= damage;
    }

    bool isAlive() {
        return health > 0;
    }
};

class Enemy {
public:
    string type;
    int health;
    int attack;

    Enemy(string enemyType, int enemyHealth, int enemyAttack) {
        type = enemyType;
        health = enemyHealth;
        attack = enemyAttack;
    }

    void takeDamage(int damage) {
        health -= damage;
    }

    bool isAlive() {
        return health > 0;
    }
};

int main() {
    srand(static_cast<unsigned>(time(0));

    Player player("YourName", 100, 10);
    Enemy enemy("Dragon", 150, 15);

    cout << "Welcome to the Text-based Game!" << endl;
    cout << "You are a brave adventurer named " << player.name << " facing a fearsome " << enemy.type << "." << endl;

    while (player.isAlive() && enemy.isAlive()) {
        int playerAttack = rand() % player.attack;
        int enemyAttack = rand() % enemy.attack;

        cout << player.name << " attacks " << enemy.type << " for " << playerAttack << " damage." << endl;
        enemy.takeDamage(playerAttack);

        cout << enemy.type << " counterattacks for " << enemyAttack << " damage." << endl;
        player.takeDamage(enemyAttack);

        cout << "Your health: " << player.health << " | " << enemy.type << " health: " << enemy.health << endl;
    }

    if (player.isAlive()) {
        cout << "Congratulations! You defeated the " << enemy.type << "." << endl;
    } else {
        cout << "You were defeated by the " << enemy.type << ". Game Over!" << endl;
    }

    return 0;
}
