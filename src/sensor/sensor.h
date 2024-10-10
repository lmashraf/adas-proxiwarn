#ifndef SENSOR_H
#define SENSOR_H

#include <vector>

class Sensor
{
    public:
        Sensor();
        std::vector<float> getDistances();
        std::vector<float> getSpeeds();

    private:
        std::vector<float> distances;
        std::vector<float> speeds;
};

#endif // SENSOR_H
