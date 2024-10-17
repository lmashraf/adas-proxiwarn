#include "sensors/lidar/lidar.h"
#include "sensors/radar/radar.h"
#include "vehicle/vehicle.h"
#include "environment/grid.h"
#include "navigation/routing.h"
#include <iostream>
#include <thread>
#include <chrono>

int main() {
    Grid grid(10, 10);
    grid.addObstacle(5, 5);

    Vehicle vehicle(0, 0, 10, 0);  // Start at (0,0) with speed 10 m/s
    Routing routing(vehicle, grid);  // Set up routing with the vehicle and grid

    while (true) {
        vehicle.updatePosition(1);  // Update vehicle position every second
        grid.displayGrid();  // Show the grid (optional)

        // Check for collisions in the vehicle's future path
        if (routing.checkCollisionPrediction(2)) {  // Predict 2 seconds into the future
            std::cout << "Collision predicted! Taking action." << std::endl;
            break;
        }

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}
