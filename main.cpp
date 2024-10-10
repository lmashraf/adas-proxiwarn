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

        for (std::vector<float>::size_type i = 0; i < distances.size(); ++i)
        {
            std::cout << "Obstacle " << i + 1 << " distance: " << distances[i] << " meters" << std::endl;

            // Collision warning if obstacle is closer than 10 meters
            if (distances[i] < 10)
            {
                std::cout << "WARNING: Obstacle " << i + 1 << " is too close!" << std::endl;
            }
        }

        // Simulate a delay between sensor readings
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}
