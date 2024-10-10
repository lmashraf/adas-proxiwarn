#ifndef SENSOR_H
#define SENSOR_H

#include <vector>

class Sensor
{
    public:
        Sensor();
        std::vector<float> getDistances();

    private:
        std::vector<float> distances;
};

#endif // SENSOR_H
