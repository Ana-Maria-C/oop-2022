#define _CRT_SECURE_NO_WARNINGS
#include "Sort.h"
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cstdarg>
#include <iostream>
using namespace std;

Sort::Sort(int count, int min, int max)
{
	this->count = count;
	this->v = new int[count];
	for (int i = 0; i < count; ++i)
	{
		this->v[i] = min+rand() % max;
	}
}

Sort::Sort(int count, int* v)
{
	this->v = new int[count];
	this->count = count;
	for (int i = 0; i < count; ++i)
	{
		this->v[i] = v[i];
	}
}

Sort::Sort(int count, ...)
{
	va_list args;
	va_start(args, count);
	this->v = new int[count];
	this->count = count;
	for (int i = 0; i < count; ++i)
	{
		this->v[i] = va_arg(args, int);
	}
	va_end(args);
}

Sort::Sort(const char* sir)
{
	int ok = 1;
	for (int i = 0; i < strlen(sir); ++i)
	{
		if (sir[i] == ',')
			++ok;
	}
	this->count = ok;
	this->v = new int[count];
	char* aux = new char[strlen(sir) + 1];
	strcpy(aux, sir);
	char* p = strtok(aux, ",");
	int index = 0;
	while (p)
	{
		this->v[index++] = atoi(p);
		p = strtok(nullptr, ",");
	}
	delete[]aux;
}

void Sort::InsertSort(bool ascendent)
{
	for (int i = 0; i < count; ++i)
	{
		int p = i;
		bool shouldSwap = ascendent ? this->v[p] < this->v[p - 1] : this->v[p] > this->v[p - 1];
		while (p > 0 && shouldSwap)
		{
			int aux = this->v[p];
			this->v[p] = this->v[p - 1];
			this->v[p - 1] = aux;
			p--;
			shouldSwap = ascendent ? this->v[p] < this->v[p - 1] : this->v[p] > this->v[p - 1];
		}
	}
}

void partition(int* a, int p, int q, int& k, bool asc)
{
	int x = a[p];
	int i = p + 1;
	int j = q;
	while (i <= j)
	{
		if (asc)
		{
			if (a[i] <= x)
				i++;
			if (a[j] >= x)
				j--;
			if (i < j && a[i] > x && x > a[j])
			{
				swap(a[i], a[j]);
				i++;
				j--;
			}
		}
		else
		{
			if (a[i] >= x)
				i++;
			if (a[j] <= x)
				j--;
			if (i < j && a[i] < x && x < a[j])
			{
				swap(a[i], a[j]);
				i++;
				j--;
			}
		}

	}
	k = i - 1;
	a[p] = a[k];
	a[k] = x;
}
void sorteaza(int* v, int p, int q, bool asc)
{
	int k = 0;
	if (p < q)
	{
		partition(v, p, q, k, asc);
		sorteaza(v, p, k - 1, asc);
		sorteaza(v, k + 1, q, asc);
	}
}
void Sort::QuickSort(bool ascendent)
{
	sorteaza(this->v, 0, this->count - 1, ascendent);
}
void Sort::BubbleSort(bool ascendent)
{
	int n = this->count;
	bool ok = false;
	do
	{
		ok = false;
		for (int i = 1; i < n; i++)
		{
			bool shouldSwap = ascendent ? this->v[i] < this->v[i - 1] : this->v[i] > this->v[i - 1];
			if (shouldSwap)
			{
				int aux = this->v[i];
				this->v[i] = this->v[i - 1];
				this->v[i - 1] = aux;
				ok = true;
			}
		}
	} while (ok == true);
}

void Sort::Print() 
{
	for (int i = 0; i < this->count; ++i)
	{
		printf("%d ", this->v[i]);
	}
}

int Sort::GetElementsCount() 
{
	int n = count;
	return n;
}

int Sort::GetElementFromIndex(int index) 
{
	int el;
	if (index < count)
	{
		el = v[index];
		return el;
	}

}
