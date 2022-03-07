#include<iostream>
#include "NumberList.h"
int main()
{
	NumberList X;
	X.Init();
	X.Add(10);
	X.Add(3);
	X.Add(1);
	X.Add(8);
	X.Add(13);
	X.Sort();
	X.Print();
}