#include "game.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Reads a single key press from the user without waiting for Enter
char readKey() {
    char key = 0;
    system("stty raw"); // Set terminal to raw mode
    key = getchar();
    system("stty sane"); // Restore terminal to normal mode
    return key;
}

Game::Game() : level(1), gameOver(false) {
    srand(time(0)); // Set up random number generation for the enemy movement
    loadLevel(level);
}

void Game::loadLevel(int lvl) {
    maze.clear();  // Clear the current maze data before loading a new level
    ifstream file("level" + to_string(lvl) + ".txt");
    string line; // To store each line from the file
    int y = 0; // Y-coordinate for tracking row number in the maze
    while(getline(file, line)){
        maze.push_back(line);
        for(int x = 0; x < line.size(); x++){
            if(line[x] == 'P'){
                player.x = x;
                player.y = y;
                maze[y][x] = ' ';
            } 
            else if(line[x] == 'X'){
                enemy.x = x;
                enemy.y = y;
                maze[y][x] = ' ';
            }
        }
        y++; // Move to next row
    }
    file.close();
}

void Game::draw() {
    system("clear"); // Clear the screen
    for(int y = 0; y < 10; y++) {
        for (int x = 0; x < 10; x++) {
            if(x == player.x && y == player.y) {
                cout<<'P';  
            }
            else if(x == enemy.x && y == enemy.y) {
                cout<<'X';  
            }
            else if(maze[y][x] == '#') {
                cout<<"█";  
            }
            else {
                cout<<maze[y][x];  
            }
        }
        cout<<endl;
    }
    cout<<"Score: "<<player.score<<" | Moves: "<<player.moves<<" | Level: "<<level<<endl;
    cout<<"Controls: W/A/S/D to move, Q to quit"<<endl;
}

// Checks if the tile at (x, y) is walkable 
bool Game::isWalkable(int x, int y) {
    if(x < 0 || x >= 10 || y < 0 || y >= 10) {
        return false;
    }
    return maze[y][x] == ' ' || maze[y][x] == '*' || maze[y][x] == 'E';
}

// Handles player movement based on input (WASD)
void Game::movePlayer(char input) {
    int newX = player.x;
    int newY = player.y;

    if(input == 'w'){
        newY--;
    }
    else if(input == 's'){ 
        newY++;
    }
    else if(input == 'a'){
        newX--;
    }
    else if(input == 'd'){ 
        newX++;
    }
    else {
        cout << "Invalid input. Use W/A/S/D."<<endl;
    }
    // Check if the target tile is walkable
    if(isWalkable(newX, newY)) {
        player.x = newX;
        player.y = newY;
        player.moves++;

        if (maze[newY][newX] == '*') {
            player.score += 10;
            maze[newY][newX] = ' ';
        } 
        else if(maze[newY][newX] == 'E') {
            cout<<"You reached the exit! Moving to next level..."<<endl;
            level++;
            ifstream file("level" + to_string(level) + ".txt");
            if (file){
                loadLevel(level);
            }
            else {
                cout<<"You completed all levels! Final Score: "<<player.score<<endl;
                gameOver = true;
            }
        }
    }
}
// Checks if the player and enemy are on the same tile
void Game::enemyCollision() {
    if(player.x == enemy.x && player.y == enemy.y) {
        cout<<"Caught by the enemy! Game Over.\n";
        gameOver = true;
    }
}

void Game::run() {
    // Loop until the game is over
    while (!gameOver) {
        draw();
        char input = readKey(); // Read user input
        input = tolower(input); // Convert to lowercase

        if (input == 'q'){

         break;
        }

        movePlayer(input);
        enemy.move(maze);
        enemyCollision();
    }
}