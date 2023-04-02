#pragma once
#include "Weather.h"
class Car
{
protected:
	double fuel_capacity;
	double fuel_consumption;
public:
	Car();
	virtual ~Car() = 0;
	virtual double GetFuelCapacity();
	virtual double GetFuelConsumption(double length = 1);
	virtual double GetAverageSpeed(Weather::weather weather);
	virtual void Name();
};