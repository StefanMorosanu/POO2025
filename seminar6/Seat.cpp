#include "Seat.h"

double Seat::GetFuelCapacity() const {
    return 50.0;
}

double Seat::GetFuelConsumption() const {
    return 7.0;
}

double Seat::GetAverageSpeed(Weather weather) const {
    switch (weather) {
        case Weather::Rain: return 80.0;
        case Weather::Sunny: return 120.0;
        case Weather::Snow: return 60.0;
        default: return 100.0;
    }
}

const char* Seat::GetModel() const {
    return "Seat";
}

bool Seat::HasEnoughFuel(double circuitLength, Weather weather) const {
    double fuelNeeded = (circuitLength / 100) * GetFuelConsumption();
    return fuelNeeded <= GetFuelCapacity();
}

double Seat::GetTimeToFinish(double circuitLength, Weather weather) const {
    double speed = GetAverageSpeed(weather);
    return circuitLength / speed;
}
