#include<iostream>
#include "Vector.h"
using namespace std;

int main()
{
	Vector<int> a(20);
	a += 2;
	a += 5;
	a += 2;
	a.Insert(3, 79);
	a.Insert(4, 34);
	a.Insert(20, 5);
	cout << a[0];
	for (int i = 0; i < a.GetSize(); i++)
		cout << a[i] << ' ';
	Vector<int> b(20);
	b.Insert(0, 55);
	b += 0;

	a.Delete(4);
	a.Delete(0);
	a.Insert(0, 3231);
	for (int i = 0; i < a.GetSize(); i++)
		cout << a[i] << " ";
	cout << endl;

	a.Sort();

	for (int i = 0; i < a.GetSize(); i++)
		cout << a[i] << " ";

	return 0;
}