#include "Dacia.h"
#include "Weather.h"
#include <iostream>

Dacia::Dacia()
{
	FuelCapacity = 100;
	FuelConsumption = 30;
	AverageSpeed[Sunny] = 60; AverageSpeed[Rain] = 50; AverageSpeed[Snow] = 40;
}

void Dacia::PrintName()
{
	std::cout << "Dacia" << '\n';
}
