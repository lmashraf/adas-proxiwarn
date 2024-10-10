#include "sensor.h"
#include <cstdlib>
#include <ctime>
#include <vector>

Sensor::Sensor()
{
    // Seed random number generator
    std::srand(std::time(0));
}

std::vector<float> Sensor::getDistances()
{
    // Simulate distances for multiple obstacles (5 in this example)
    std::vector<float> distances;

    for (int i = 0; i < 5; ++i) {
        distances.push_back(static_cast<float>(std::rand() % 100));
    }

    return distances;
}
