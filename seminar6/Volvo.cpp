#include "Volvo.h"

double Volvo::GetFuelCapacity() const {
    return 50.0;  // Example value in liters
}

double Volvo::GetFuelConsumption() const {
    return 8.0;  // Example value in liters per 100 km
}

double Volvo::GetAverageSpeed(Weather weather) const {
    switch (weather) {
        case Weather::Rain: return 80.0;
        case Weather::Sunny: return 120.0;
        case Weather::Snow: return 60.0;
        default: return 100.0;
    }
}

const char* Volvo::GetModel() const {
    return "Volvo";
}

bool Volvo::HasEnoughFuel(double circuitLength, Weather weather) const {
    double fuelNeeded = (circuitLength / 100) * GetFuelConsumption();
    return fuelNeeded <= GetFuelCapacity();
}

double Volvo::GetTimeToFinish(double circuitLength, Weather weather) const {
    double speed = GetAverageSpeed(weather);
    return circuitLength / speed;
}
