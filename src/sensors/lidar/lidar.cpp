#include "lidar.h"

#include <cstdlib>

LiDAR::LiDAR() : Sensor() {}

std::vector<float> LiDAR::getDistances() {
    std::vector<float> distances;
    for (int i = 0; i < 5; ++i) {
        distances.push_back(static_cast<float>(std::rand() % 100));
    }
    return distances;
}

std::vector<float> LiDAR::getSpeeds() {
    std::vector<float> speeds;
    for (int i = 0; i < 5; ++i) {
        speeds.push_back(static_cast<float>((std::rand() % 30) + 1));
    }
    return speeds;
}
