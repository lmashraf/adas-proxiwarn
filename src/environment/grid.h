#ifndef GRID_H
#define GRID_H

#include <vector>

class Grid
{
    public:
        Grid(int width, int height);

        // Add obstacle at position (x, y)
        void addObstacle(int x, int y);

        // Check if a position has an obstacle
        bool isObstacle(int x, int y);

        // Display the grid (for debugging)
        void displayGrid();

    private:
        // Helper function to convert 2D index to 1D
        int index(int x, int y) const;

    private:
        // 1D vector representing the grid
        std::vector<bool>   grid;
        int                 width;
        int                 height;
};

#endif // GRID_H
