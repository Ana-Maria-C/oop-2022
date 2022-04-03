#include "Mazda.h"
#include "Weather.h"
#include <iostream>

Mazda::Mazda()
{
	FuelCapacity = 100;
	FuelConsumption = 20;
	AverageSpeed[Sunny] = 80; AverageSpeed[Rain] = 55; AverageSpeed[Snow] = 60;
}
void Mazda::PrintName()
{
	std::cout << "Mazda" << '\n';
}
