#include "vehicle.h"

#include <cmath>

Vehicle::Vehicle(float initialX, float initialY, float speed, float direction)
    : x(initialX), y(initialY), speed(speed), direction(direction) 
{}

std::pair<float, float> Vehicle::getPosition() const
{
    return {x, y};
}

void Vehicle::updatePosition(float deltaTime)
{
    auto [newX, newY] = calculateNewPosition(deltaTime);
    x = newX;
    y = newY;
}

void Vehicle::setSpeed(float newSpeed)
{
    speed = newSpeed;
}

void Vehicle::setDirection(float newDirection)
{
    direction = newDirection;
}

std::pair<float, float> Vehicle::calculateNewPosition(float deltaTime) const
{
    float newX = x + speed * deltaTime * std::cos(direction);
    float newY = y + speed * deltaTime * std::sin(direction);

    return {newX, newY};
}
