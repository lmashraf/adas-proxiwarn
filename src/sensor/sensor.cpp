#include "sensor.h"

#include <cstdlib>
#include <ctime>

Sensor::Sensor() {
    std::srand(std::time(0));
}

float Sensor::getDistance() {
    // Simulate a random distance between 0 and 100 meters
    return static_cast<float>(std::rand() % 100);
}
