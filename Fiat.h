#pragma once
#include "Weather.h"
#include "Car.h"
class Fiat : public Car {
private:
	double fuel_capacity = 35;
	double fuel_consumption = 4;
public:
	Fiat();
	~Fiat();
	void Name() ;
	double GetFuelCapacity() ;
	double GetFuelConsumption(double length = 1) ;
	double GetAverageSpeed(Weather::weather weather) ;
};