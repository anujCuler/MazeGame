# 🧩 Anuj's Maze Game

Welcome to **Anuj's Maze Game**, a simple terminal-based maze adventure where you navigate a player through tricky mazes, collect points, avoid the enemy, and reach the exit to level up!

## 🎮 Gameplay Features

- Move the player using **W/A/S/D** keys.
- Collect `*` items to earn points.
- Avoid the enemy (`X`) — if it catches you, it’s game over!
- Reach the exit (`E`) to proceed to the next level.
- Each level is loaded from a separate `.txt` file for easy customization.


## 🕹️ Controls

- `W` - Move up
- `A` - Move left
- `S` - Move down
- `D` - Move right
- `Q` - Quit the game

## 🧠 How it Works

- The game reads a level from a file like `level1.txt`.
- `P` marks the starting player position.
- `X` marks the starting enemy position.
- `#` are walls, `*` are collectibles, and `E` is the exit.
- The maze is a 10x10 grid.

🏆 Scoring System
Each * collected gives 10 points.

Finishing a level adds a bonus of 50 points.

Display your score after every level and at game over.


