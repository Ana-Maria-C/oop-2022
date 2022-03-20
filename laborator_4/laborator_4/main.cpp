#include "sort.h"
#include<iostream>
int main()
{
	Sort l("12,3,67,19,28");
	Sort l1(7, -3, 20);
	int t[] = {23, 5, 56,19,0,-3,4};
	Sort l2(7,t);
	//Sort l3(6, 7, 8, 9, 1, 2, 4);
	Sort l3 = { 6, 7, 8, 9, 1, 2, 4 };
	//Sort l3 ({ 7, 7, 4, 2, 1, 3, 4, 6, 5 });
	l3.QuickSort(true);
	l3.Print();
	return 0;
}