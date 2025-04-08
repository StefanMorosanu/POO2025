#include "BMW.h"

double BMW::GetFuelCapacity() const {
    return 60.0;
}

double BMW::GetFuelConsumption() const {
    return 10.0;
}

double BMW::GetAverageSpeed(Weather weather) const {
    switch (weather) {
        case Weather::Rain: return 90.0;
        case Weather::Sunny: return 150.0;
        case Weather::Snow: return 70.0;
        default: return 120.0;
    }
}

const char* BMW::GetModel() const {
    return "BMW";
}

bool BMW::HasEnoughFuel(double circuitLength, Weather weather) const {
    double fuelNeeded = (circuitLength / 100) * GetFuelConsumption();
    return fuelNeeded <= GetFuelCapacity();
}

double BMW::GetTimeToFinish(double circuitLength, Weather weather) const {
    double speed = GetAverageSpeed(weather);
    return circuitLength / speed;
}
