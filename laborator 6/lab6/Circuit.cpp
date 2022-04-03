#include "Circuit.h"
#include <iostream>

void Circuit::SetLength(float l)
{
	length = l;
}

void Circuit::SetWeather(Weather w)
{
	weather = w;
}

void Circuit::AddCar(Car* car)
{
	Cars[nocars++] = car;
}

void Circuit::Race()
{
	int i, j;
	for (i = 0; i < nocars; i++) {
		if (Cars[i]->FuelCapacity / Cars[i]->FuelConsumption * 100 >= length)
			Cars[i]->TimeToFinish = length / Cars[i]->AverageSpeed[weather];
		else
			Cars[i]->TimeToFinish = 0;
	}
	float temp;
	for (i = 0; i < nocars; i++) {
		Leaderboard[i] = Cars[i]->TimeToFinish;
	}
	for (i = 0; i < nocars; i++)
	{
		for (j = 0; j < nocars - i - 1; j++)
		{
			if (Leaderboard[j] > Leaderboard[j + 1])
			{
				temp = Leaderboard[j];
				Leaderboard[j] = Leaderboard[j + 1];
				Leaderboard[j + 1] = temp;
			}
		}
	}
}

void Circuit::ShowFinalRanks()
{
	int i, j, loc = 1;
	std::cout << "Clasamentul este urmatorul:" << '\n';
	for (i = 0; i < nocars; i++) {
		for (j = 0; j < nocars; j++)
			if ((Cars[j]->TimeToFinish == Leaderboard[i]) && Leaderboard[i]) {
				std::cout << "Pe locul " << loc++ << " este ";
				Cars[j]->PrintName();
				break;
			}
	}

}

void Circuit::ShowWhoDidNotFinish()
{
	int i, j, ultim = 0;
	std::cout << "Nu au terminat urmatorii:" << '\n';
	for (i = 0; i < nocars; i++) {
		for (j = ultim; j < nocars; j++)
			if ((Cars[j]->TimeToFinish == Leaderboard[i]) && !Leaderboard[i]) {
				Cars[j]->PrintName();
				ultim = j + 1;
				break;
			}
	}
}
