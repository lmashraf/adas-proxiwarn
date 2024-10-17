#ifndef ROUTING_H
#define ROUTING_H

#include "vehicle.h"
#include "environment/grid.h"

class Routing 
{
    public:
        Routing(const Vehicle& vehicle, const Grid& grid);

        // Predict if the vehicle's path will collide with an obstacle in 'time' seconds
        bool checkCollisionPrediction(float time) const;

private:
    // Internal method to predict the vehicle's future position
    std::pair<float, float> predictFuturePosition(float time) const;

private:
    // Reference to the vehicle
    const Vehicle&  vehicle;

    // Reference to the grid
    const Grid&     grid;

};

#endif // ROUTING_H