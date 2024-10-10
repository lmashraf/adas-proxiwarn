#ifndef SENSOR_H
#define SENSOR_H

#include <iostream>
#include <cstdlib>
#include <ctime>

class Sensor {
    public:
        Sensor();
        float getDistance();
    private:
        float distance;
};

#endif // SENSOR_H