#ifndef OBSTACLE_H
#define OBSTACLE_H

class Obstacle {
public:
    Obstacle(int x, int y);  // Constructor to set the obstacle position
    int getX() const;        // Get the X position of the obstacle
    int getY() const;        // Get the Y position of the obstacle

private:
    int x, y;  // Position of the obstacle
};

#endif // OBSTACLE_H
