#pragma once
#include "Car.h"
#include "BMW.h"
#include "Fiat.h"
#include "RangeRover.h"
#include "Seat.h"
#include "Audi.h"
class Circuit
{
	int nr_masinni;
	Car* cars[256];
	Weather::weather weather;
	double length;
	Car* Ranks[256];
	int ranks_nr = 0;
	Car* DidNotFinish[256];
	int DNF_nr = 0;

public:
	Circuit();
	~Circuit();
	void SetWeather(Weather::weather weather_in);
	void SetLength(double length_in);
	void AddCar(Car* car_new);
	void Race();
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();

};