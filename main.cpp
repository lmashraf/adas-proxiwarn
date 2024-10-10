#include "sensors/lidar/lidar.h"
#include "sensors/radar/radar.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <vector>

// Function to process sensor data
template <typename SensorType>
void processSensorData(SensorType& sensor, const std::string& sensorName)
{
    std::vector<float> distances = sensor.getDistances();
    std::vector<float> speeds = sensor.getSpeeds();

    for (std::vector<float>::size_type i = 0; i < distances.size(); ++i)
    {
        float timeToCollision = distances[i] / speeds[i];

        std::cout << sensorName << " Obstacle " << i + 1
                  << " time to collision: " << timeToCollision << " seconds"
                  << std::endl;

        if (timeToCollision < 5) 
        {
            std::cout << "WARNING: " << sensorName << " Obstacle " << i + 1 
                      << " is too close!" << std::endl;
        }
    }
}

int main()
{
    LiDAR lidar;
    Radar radar;

    while (true)
    {
        processSensorData(lidar, "LiDAR");  // Process LiDAR data
        processSensorData(radar, "Radar");  // Process Radar data

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}
