#pragma once
#include "player.h"
#include "enemy.h"
#include <vector>
#include <string>
using namespace std;

class Game {
private:
    vector<string> maze;
    Player player;
    Enemy enemy;
    int level;
    bool gameOver;

public:
    Game();
    void loadLevel(int lvl);
    void draw();
    bool isWalkable(int x, int y);
    void movePlayer(char input);
    void enemyCollision();
    void run();
};