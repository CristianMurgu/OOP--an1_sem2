#pragma once
#include "Car.h"
class Seat : public Car {
private:
	double fuel_capacity = 35;
	double fuel_consumption = 4;
public:
	Seat();
	~Seat();
	void Name();
	double GetFuelCapacity();
	double GetFuelConsumption(double length = 1);
	double GetAverageSpeed(Weather::weather weather);
};