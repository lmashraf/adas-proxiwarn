#include "radar.h"

#include <cstdlib>

Radar::Radar() : Sensor() {}

std::vector<float> Radar::getDistances() {
    std::vector<float> distances;
    for (int i = 0; i < 5; ++i) {
        distances.push_back(static_cast<float>(std::rand() % 200));  // Longer range for Radar
    }
    return distances;
}

std::vector<float> Radar::getSpeeds() {
    std::vector<float> speeds;
    for (int i = 0; i < 5; ++i) {
        speeds.push_back(static_cast<float>((std::rand() % 40) + 1));  // Radar simulates faster speeds
    }
    return speeds;
}
