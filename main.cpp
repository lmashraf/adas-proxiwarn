#include "sensors/lidar/lidar.h"
#include "sensors/radar/radar.h"
#include "vehicle/vehicle.h"
#include "environment/grid.h"
#include "navigation/routing.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <stdexcept>

// Function to process sensor data
template <typename SensorType>
void processSensorData(SensorType& sensor, const std::string& sensorName, Grid& grid) {
    std::vector<float> distances = sensor.getDistances();
    std::vector<float> speeds = sensor.getSpeeds();

    for (std::size_t i = 0; i < distances.size(); ++i) {
        if (speeds[i] == 0) {
            throw std::runtime_error("Speed cannot be zero to calculate time to collision.");
        }

        float timeToCollision = distances[i] / speeds[i];

        std::cout << sensorName << " Obstacle " << i + 1
                  << " time to collision: " << timeToCollision << " seconds"
                  << std::endl;

        if (grid.isObstacle(static_cast<int>(distances[i]), 0)) {
            std::cout << "WARNING: " << sensorName << " Obstacle " << i + 1
                      << " is too close!" << std::endl;
        }
    }
}

int main() {
    Grid grid(10, 10);  // Create a 10x10 grid
    Obstacle obstacle1(5, 5);  // Create an obstacle at (5,5)
    grid.addObstacle(obstacle1);  // Add obstacle to the grid

    Vehicle vehicle(0, 0, 10, 0);  // Vehicle starting at (0,0)
    Routing routing(vehicle, grid);  // Routing logic for the vehicle and grid

    LiDAR lidar;
    Radar radar;

    while (true) {
        vehicle.updatePosition(1);  // Update vehicle position every second
        grid.displayGrid();  // Display the grid with obstacles

        // Process sensor data for LiDAR and Radar
        processSensorData(lidar, "LiDAR", grid);
        processSensorData(radar, "Radar", grid);

        // Check for collisions
        if (routing.checkCollisionPrediction(2)) {
            std::cout << "Collision predicted! Taking action." << std::endl;
            break;
        }

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}