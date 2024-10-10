#ifndef LIDAR_H
#define LIDAR_H

#include "../sensor.h"

class LiDAR : public Sensor
{
    public:
        LiDAR();
        std::vector<float> getDistances() override;
        std::vector<float> getSpeeds() override;
};

#endif // LIDAR_H
