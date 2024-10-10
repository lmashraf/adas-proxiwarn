#include "sensor/sensor.h"

#include <iostream>
#include <thread>
#include <chrono>

int main() {
    Sensor sensor;

    while (true) {
        float distance = sensor.getDistance();
        std::cout << "Distance to obstacle: " << distance << " meters" << std::endl;

        // Collision warning threshold
        if (distance < 10) {
            std::cout << "WARNING: Obstacle too close!" << std::endl;
        }

        // Simulate time delay between sensor readings
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    return 0;
}
