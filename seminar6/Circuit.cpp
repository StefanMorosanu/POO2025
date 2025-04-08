#include "Circuit.h"
#include <iostream>

Circuit::Circuit() : numCars(0), length(0.0), weather(Weather::Sunny) {}

Circuit::~Circuit() {
    for (int i = 0; i < numCars; i++) {
        delete cars[i];
    }
}

void Circuit::SetLength(double len) {
    length = len;
}

void Circuit::SetWeather(Weather w) {
    weather = w;
}

void Circuit::AddCar(Car* car) {
    if (numCars < 5) {
        cars[numCars++] = car;
    }
}

void Circuit::Race() {
    for (int i = 0; i < numCars; i++) {
        if (!cars[i]->HasEnoughFuel(length, weather)) {
            std::cout << cars[i]->GetModel() << " does not have enough fuel to finish the race!" << std::endl;
        }
    }
}

void Circuit::ShowFinalRanks() const {
    // Simplified race results (you can add sorting logic for real race results)
    for (int i = 0; i < numCars; i++) {
        if (cars[i]->HasEnoughFuel(length, weather)) {
            double time = cars[i]->GetTimeToFinish(length, weather);
            std::cout << cars[i]->GetModel() << " finished in: " << time << " hours." << std::endl;
        }
    }
}

void Circuit::ShowWhoDidNotFinish() const {
    for (int i = 0; i < numCars; i++) {
        if (!cars[i]->HasEnoughFuel(length, weather)) {
            std::cout << cars[i]->GetModel() << " did not finish the race!" << std::endl;
        }
    }
}
