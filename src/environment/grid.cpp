#include "grid.h"
#include <iostream>

Grid::Grid(int width, int height) : width(width), height(height), grid(width * height, false)
{}

int Grid::index(int x, int y) const 
{
    // Convert 2D coordinates (x, y) to 1D index
    return y * width + x;
}

void Grid::addObstacle(int x, int y)
{
    if (x >= 0 && x < width && y >= 0 && y < height)
    {
        // Mark the position as an obstacle
        grid[index(x, y)] = true;
    }
}

bool Grid::isObstacle(int x, int y) 
{
    if (x >= 0 && x < width && y >= 0 && y < height) 
    {
        return grid[index(x, y)];
    }

    return false;
}

void Grid::displayGrid()
{
    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            // O for obstacle, . for free space
            std::cout << (grid[index(x, y)] ? "O" : ".") << " ";
        }

        std::cout << std::endl;
    }
}
