#pragma once
#include "Weather.h"

class Car
{

public:
	float FuelCapacity;
	float FuelConsumption;
	float TimeToFinish;
	float AverageSpeed[3];
	virtual void PrintName() = 0;
};