#include "enemy.h"
#include <cstdlib>
using namespace std;

Enemy::Enemy(int startX, int startY){
    x = startX;  // Set enemy's x position
    y = startY;  // Set enemy's y position
}

void Enemy::move(vector<string>& maze){
    int randomIndex = rand() % 4;

    // Start with current position
    int newX = x;
    int newY = y;

    if(randomIndex == 0){   // Up
        newY--;
    } 
    else if(randomIndex == 1){  // Down
        newY++;
    } 
    else if(randomIndex == 2){  // Left
        newX--;
    } 
    else if(randomIndex == 3){  // Right
        newX++;
    }

    // Check if the new position is inside the maze and not a wall
    bool insideMaze = (newX >= 0 && newX < 10 && newY >= 0 && newY < 10);
    bool isWalkable = (maze[newY][newX] == ' ' || maze[newY][newX] == '*' ||  maze[newY][newX] == 'E');

    // If it's a valid move, update the enemy's position
    if (insideMaze && isWalkable) {
        x = newX;
        y = newY;
    }
}