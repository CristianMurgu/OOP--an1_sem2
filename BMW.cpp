#include "BMW.h"
#include "Weather.h"
#include "Car.h"
#include <iostream>

BMW::BMW() {}
BMW::~BMW() {}
void BMW::Name()  {
	printf("BMW ");
}
double BMW::GetFuelCapacity()
{
	return fuel_capacity;
}
double BMW::GetFuelConsumption(double lenght)
{
	return lenght * fuel_consumption;
}
double BMW::GetAverageSpeed(Weather::weather weather)
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
		break;
	}
}