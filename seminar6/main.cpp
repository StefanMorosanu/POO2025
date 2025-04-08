#include <iostream>
#include "Circuit.h"
#include "Volvo.h"
#include "BMW.h"
#include "Seat.h"
#include "Fiat.h"
#include "RangeRover.h"
#include "Weather.h"
#include "Car.h"
#include "Circuit.cpp"
#include "Volvo.cpp"    
#include "BMW.cpp"
#include "Seat.cpp"
#include "Fiat.cpp"
#include "RangeRover.cpp"


int main() {
    Circuit c;
    c.SetLength(100);   // 100 km circuit
    c.SetWeather(Weather::Rain);  // Race under rain
    c.AddCar(new Volvo());
    c.AddCar(new BMW());
    c.AddCar(new Seat());
    c.AddCar(new Fiat());
    c.AddCar(new RangeRover());
    
    c.Race();
    c.ShowFinalRanks();
    c.ShowWhoDidNotFinish();
    
    return 0;
}
