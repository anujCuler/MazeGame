cmake_minimum_required(VERSION 3.10)
project(maze)

set(CMAKE_CXX_STANDARD 17)

# Add all source files
set(SOURCES
        main.cpp
        entity.cpp
        player.cpp
        enemy.cpp
        game.cpp
)

# Add the executable
add_executable(maze ${SOURCES})
