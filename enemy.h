#pragma once  // Ensures the file is included only once during compilation

#include "entity.h"  // Base class that Enemy inherits from
#include <vector>    
#include <string>    

using namespace std;  

class Enemy : public Entity {
public:
    Enemy(int startX = 8, int startY = 5);  
    void move(vector<string>& maze); // Moves the enemy based on the current state of the maze
};
