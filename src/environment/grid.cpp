#include "grid.h"
#include <iostream>

Grid::Grid(int width, int height) : width(width), height(height), grid(width, std::vector<bool>(height, false)) {}

void Grid::addObstacle(const Obstacle& obstacle) {
    if (obstacle.getX() < width && obstacle.getY() < height) {
        grid[obstacle.getY()][obstacle.getX()] = true;
    }
}

bool Grid::isObstacle(int x, int y) const {
    if (x >= 0 && x < width && y >= 0 && y < height) {
        return grid[y][x];
    }
    return false;
}

void Grid::displayGrid() const {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            std::cout << (grid[y][x] ? "O" : ".") << " ";
        }
        std::cout << std::endl;
    }
}
