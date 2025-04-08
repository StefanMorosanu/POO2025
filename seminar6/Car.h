#pragma once
#include "Weather.h"

class Car {
public:
    virtual ~Car() {}
    virtual double GetFuelCapacity() const = 0;
    virtual double GetFuelConsumption() const = 0;
    virtual double GetAverageSpeed(Weather weather) const = 0;
    virtual const char* GetModel() const = 0;
    virtual bool HasEnoughFuel(double circuitLength, Weather weather) const = 0;
    virtual double GetTimeToFinish(double circuitLength, Weather weather) const = 0;
};


