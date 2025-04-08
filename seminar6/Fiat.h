#pragma once
#include "Car.h"

class Fiat : public Car {
public:
    double GetFuelCapacity() const;
    double GetFuelConsumption() const;
    double GetAverageSpeed(Weather weather) const;
    const char* GetModel() const;
    bool HasEnoughFuel(double circuitLength, Weather weather) const;
    double GetTimeToFinish(double circuitLength, Weather weather) const;
};


