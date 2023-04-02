#include "Audi.h"
#include "Weather.h"
#include "Car.h"
#include <iostream>
Audi::Audi() {}
Audi::~Audi() {}
void Audi::Name() {
	printf("Audi");
}
double Audi::GetFuelCapacity() 
{
	return fuel_capacity;
}
double Audi::GetFuelConsumption(double lenght) 
{
	return lenght * fuel_consumption;
}
double Audi::GetAverageSpeed(Weather::weather weather) 
{
	switch (weather)
	{
	case Weather::Rain:
		return 70;
		break;
	case Weather::Sunny:
		return 100;
		break;
	case Weather::Snow:
		return 35;
		break;
	default:
		break;
	}
}