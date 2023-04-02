#include "Fiat.h"
#include "Weather.h"
#include "Car.h"
#include <iostream>

Fiat::Fiat() {}
Fiat::~Fiat() {}
void Fiat::Name() {
	printf("Fiat ");
}
double Fiat::GetFuelCapacity()
{
	return fuel_capacity;
}
double Fiat::GetFuelConsumption(double lenght)
{
	return lenght * fuel_consumption;
}
double Fiat::GetAverageSpeed(Weather::weather weather)
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