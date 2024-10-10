#include "src/sensors/radar/radar.h"

#include <gtest/gtest.h>
#include <vector>


TEST(RadarTest, GeneratesCorrectNumberOfDistances)
{
    Radar radar;
    std::vector<float> distances = radar.getDistances();
    EXPECT_EQ(distances.size(), 5);  // Expect 5 distances
}

TEST(RadarTest, DistancesAreWithinRange) 
{
    Radar radar;

    std::vector<float> distances = radar.getDistances();

    for (float distance : distances)
    {
        // Radar has a range of 0-200 meters
        EXPECT_GE(distance, 0);
        EXPECT_LE(distance, 200);
    }
}
