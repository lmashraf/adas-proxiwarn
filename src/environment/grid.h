#ifndef GRID_H
#define GRID_H

#include "obstacle.h"
#include <vector>

class Grid {
public:
    Grid(int width, int height);

    void addObstacle(const Obstacle& obstacle);
    bool isObstacle(int x, int y) const;
    void displayGrid() const;

private:
    int index(int x, int y) const;

private:
    int width;
    int height;
    std::vector<std::vector<bool>> grid;
    std::vector<Obstacle> obstacles;
};

#endif // GRID_H
