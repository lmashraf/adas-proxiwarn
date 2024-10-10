#ifndef RADAR_H
#define RADAR_H

#include "../sensor.h"

class Radar : public Sensor 
{
    public:
        Radar();
        std::vector<float> getDistances() override;
        std::vector<float> getSpeeds() override;
};

#endif // RADAR_H
