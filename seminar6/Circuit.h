#pragma once
#include "Car.h"
#include "Weather.h"

class Circuit {
private:
    Car* cars[5];   // Array to store cars, maximum 5 for this example
    int numCars;
    double length;
    Weather weather;

public:
    Circuit();
    ~Circuit();
    void SetLength(double len);
    void SetWeather(Weather w);
    void AddCar(Car* car);
    void Race();
    void ShowFinalRanks() const;
    void ShowWhoDidNotFinish() const;
};


