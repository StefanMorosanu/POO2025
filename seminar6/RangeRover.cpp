#include "RangeRover.h"

double RangeRover::GetFuelCapacity() const {
    return 80.0;
}

double RangeRover::GetFuelConsumption() const {
    return 12.0;
}

double RangeRover::GetAverageSpeed(Weather weather) const {
    switch (weather) {
        case Weather::Rain: return 100.0;
        case Weather::Sunny: return 140.0;
        case Weather::Snow: return 80.0;
        default: return 110.0;
    }
}

const char* RangeRover::GetModel() const {
    return "RangeRover";
}

bool RangeRover::HasEnoughFuel(double circuitLength, Weather weather) const {
    double fuelNeeded = (circuitLength / 100) * GetFuelConsumption();
    return fuelNeeded <= GetFuelCapacity();
}

double RangeRover::GetTimeToFinish(double circuitLength, Weather weather) const {
    double speed = GetAverageSpeed(weather);
    return circuitLength / speed;
}
