#include "src/sensor/sensor.h"

#include <gtest/gtest.h>
#include <vector>

// Test that the sensor generates the correct number of distances
TEST(SensorTest, GeneratesCorrectNumberOfDistances) {
    Sensor sensor;
    std::vector<float> distances = sensor.getDistances();
    EXPECT_EQ(distances.size(), 5);  // We expect 5 distances
}

// Test that the distances are within the expected range
TEST(SensorTest, DistancesWithinRange) {
    Sensor sensor;
    std::vector<float> distances = sensor.getDistances();
    for (float distance : distances) {
        EXPECT_GE(distance, 0);
        EXPECT_LE(distance, 100);
    }
}
