#include "Seat.h"
#include "Weather.h"
#include "Car.h"
#include <iostream>

Seat::Seat() {}
Seat::~Seat() {}
void Seat::Name() {
	printf("Seat ");
}
double Seat::GetFuelCapacity()
{
	return fuel_capacity;
}
double Seat::GetFuelConsumption(double lenght)
{
	return lenght * fuel_consumption;
}
double Seat::GetAverageSpeed(Weather::weather weather)
{
	switch (weather)
	{
	case Weather::Rain:
		return 55;
		break;
	case Weather::Sunny:
		return 75;
		break;
	case Weather::Snow:
		return 45;
		break;
	default:
		return -1;
	}
}