#ifndef VEHICLE_H
#define VEHICLE_H

#include <utility>  // For std::pair

class Vehicle {
public:
    Vehicle(float initialX, float initialY, float speed, float direction);

    // Get the current position of the vehicle
    std::pair<float, float> getPosition() const;

    // Update the position based on speed and direction over time
    void updatePosition(float deltaTime);

    // Set the vehicle's speed
    void setSpeed(float newSpeed);

    // Set the vehicle's direction (in radians)
    void setDirection(float newDirection);

    // Public method to calculate the new position based on speed, direction, and time
    std::pair<float, float> calculateNewPosition(float deltaTime) const;  // <-- Make this public

private:
    float x, y;       // Current position of the vehicle
    float speed;      // Speed of the vehicle in meters per second
    float direction;  // Direction the vehicle is facing in radians (0 = right, π/2 = up)
};

#endif // VEHICLE_H