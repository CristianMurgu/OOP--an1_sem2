#include "RangeRover.h"
#include "Weather.h"
#include "Car.h"
#include <iostream>

RangeRover::RangeRover() {}
RangeRover::~RangeRover() {}
void RangeRover::Name() {
	printf("BMW ");
}
double RangeRover::GetFuelCapacity()
{
	return fuel_capacity;
}
double RangeRover::GetFuelConsumption(double lenght)
{
	return lenght * fuel_consumption;
}
double RangeRover::GetAverageSpeed(Weather::weather weather)
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