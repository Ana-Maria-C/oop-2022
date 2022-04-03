#include "Mercedes.h"
#include "Weather.h"
#include <iostream>

Mercedes::Mercedes()
{
	FuelCapacity = 300;
	FuelConsumption = 35;
	AverageSpeed[Sunny] = 100; AverageSpeed[Rain] = 85; AverageSpeed[Snow] = 70;
}

void Mercedes::PrintName()
{
	std::cout << "Mercedes" << '\n';
}
