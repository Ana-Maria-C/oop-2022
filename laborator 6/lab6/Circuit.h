#include "Car.h"
#include "Weather.h"
#include "Dacia.h"
#include "Ford.h"
#include "Mazda.h"
#include "Mercedes.h"
#include "Toyota.h"

class Circuit
{
	float length;
	Weather weather;
	int nocars = 0;
	Car* Cars[50];
	float Leaderboard[50];
public:
	void SetLength(float l);
	void SetWeather(Weather w);
	void AddCar(Car* car);
	void Race();
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();
};

