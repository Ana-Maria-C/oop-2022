#include "Toyota.h"
#include "Weather.h"
#include <iostream>

Toyota::Toyota()
{
	FuelCapacity = 200;
	FuelConsumption = 20;
	AverageSpeed[Sunny] = 80; AverageSpeed[Rain] = 65; AverageSpeed[Snow] = 50;
}

void Toyota::PrintName()
{
	std::cout << "Toyota" << '\n';
}
