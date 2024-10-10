#include "src/sensor/sensor.h"

#include <iostream>
#include <thread>
#include <chrono>
#include <vector>

int main() 
{
    Sensor sensor;

    while (true)
    {
        std::vector<float> distances = sensor.getDistances();

        // Get the relative speeds
        std::vector<float> speeds = sensor.getSpeeds();

        for (std::vector<float>::size_type i = 0; i < distances.size(); ++i)
        {
            // Calculate time to collision
            float timeToCollision = distances[i] / speeds[i];

            std::cout << "Obstacle " << i + 1 << " distance: " << distances[i]
                      << " meters, speed: " << speeds[i] << " m/s, time to collision: "
                      << timeToCollision << " seconds" << std::endl;

            // Warning if time to collision is less than 5 seconds
            if (timeToCollision < 5) {
                std::cout << "WARNING: Obstacle " << i + 1 << " is too close! Collision likely in "
                          << timeToCollision << " seconds." << std::endl;
            }
        }

        // Simulate a delay between sensor readings
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}