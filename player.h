#pragma once  
#include "entity.h"  // Base class that Player inherits from

// Player class represents the user-controlled character in the game.
class Player : public Entity {
public:
    int score;  // Tracks the player's score 
    int moves;  // Tracks the number of moves the player has made

    Player(int startX = 1, int startY = 1); // Constructor initializes player position with default values (1, 1)
};
