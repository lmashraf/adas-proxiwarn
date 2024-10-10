#include "src/sensors/lidar/lidar.h"

#include <gtest/gtest.h>
#include <vector>


TEST(LiDARTest, GeneratesCorrectNumberOfDistances)
{
    LiDAR lidar;

    std::vector<float> distances = lidar.getDistances();

    // Expect 5 distances
    EXPECT_EQ(distances.size(), 5); 
}

TEST(LiDARTest, DistancesAreWithinRange)
{
    LiDAR lidar;

    std::vector<float> distances = lidar.getDistances();

    for (float distance : distances)
    {
        // LiDAR has a range of 0-100 meters
        EXPECT_GE(distance, 0);
        EXPECT_LE(distance, 100);
    }
}
