#include "Ford.h"
#include "Weather.h"
#include <iostream>

Ford::Ford()
{
	FuelCapacity = 150;
	FuelConsumption = 50;
	AverageSpeed[Sunny] = 60; AverageSpeed[Rain] = 45; AverageSpeed[Snow] = 30;
}

void Ford::PrintName()
{
	std::cout << "Ford" << '\n';
}
