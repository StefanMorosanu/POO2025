#include "Fiat.h"

double Fiat::GetFuelCapacity() const {
    return 40.0;
}

double Fiat::GetFuelConsumption() const {
    return 100.0;
}

double Fiat::GetAverageSpeed(Weather weather) const {
    switch (weather) {
        case Weather::Rain: return 80.0;
        case Weather::Sunny: return 130.0;
        case Weather::Snow: return 70.0;
        default: return 120.0;
    }
}

const char* Fiat::GetModel() const {
    return "Fiat";
}

bool Fiat::HasEnoughFuel(double circuitLength, Weather weather) const {
    double fuelNeeded = (circuitLength / 100) * GetFuelConsumption();
    return fuelNeeded <= GetFuelCapacity();
}

double Fiat::GetTimeToFinish(double circuitLength, Weather weather) const {
    double speed = GetAverageSpeed(weather);
    return circuitLength / speed;
}
