#ifndef SENSOR_H
#define SENSOR_H

#include <vector>

class Sensor
{
    public:
        Sensor() {}
        virtual std::vector<float> getDistances()   = 0;  // Pure virtual method
        virtual std::vector<float> getSpeeds()      = 0;     // Pure virtual method
};

#endif // SENSOR_H
