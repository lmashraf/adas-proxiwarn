#include "routing.h"
#include <cmath>

Routing::Routing(const Vehicle& vehicle, const Grid& grid)
    : vehicle(vehicle), grid(grid)
{}

std::pair<float, float> Routing::predictFuturePosition(float time) const
{
    // Use vehicle's internal method to calculate the new position after 'time' seconds
    return vehicle.calculateNewPosition(time);
}

bool Routing::checkCollisionPrediction(float time) const
{
    auto [futureX, futureY] = predictFuturePosition(time);

    // Check if the predicted position has an obstacle in the grid
    return grid.isObstacle(static_cast<int>(futureX), static_cast<int>(futureY));
}
