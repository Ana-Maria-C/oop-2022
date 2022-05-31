#pragma once
#include<iostream>
using namespace std;
template<typename T>

int compare(T x, T y)
{
	if (x == y)
		return 0;
	if (x < y)
		return 1;
	return -1;
}

class Compare{

public:
	virtual int CompareElements(void* e1, void* e2) = 0;
};

template<typename T>
class VectorIterator{

	int Current; // mai adaugati si alte date si functii necesare pentru iterator
	T *vector;
	int Last;

public:

	VectorIterator()
	{
		Current = 0;
	};
	VectorIterator& operator ++ ()
	{
		Current++;
		return *this;
	};
	VectorIterator& operator -- ()
	{
		Current--;
		return *this;
	};
	bool operator= (VectorIterator<T>&it)
	{
		if (it.Current == Current)
			return true;
		return false;
	};
	bool operator!=(VectorIterator<T>&it)
	{
		if (!(it.Current == Current))
			return true;
		return false;
	};
	T* GetElement()
	{
		return vector[Current];
	};

};

template<typename T>
class Vector {
	T* vector;
	int size;
	int capacity;
	VectorIterator<T> begin()
	{
		VectorIterator<T> ar;
		ar.Last = size;
		ar.vector = vector;
		return ar;
	};
	VectorIterator<T> end()
	{
		VectorIterator<T> ar;
		ar.Last = size;
		ar.vector = vector;
		ar.Current = size - 1;
		return ar;
	}
	;
public:
	Vector()
	{
		vector = nullptr;
		size = 0;
	};    // constructor 
	~Vector()
	{
		delete[] vector;
		size = 0;
	}; // destructor
    Vector(int capacity)
	{
		this->capacity = capacity;
	};
	Vector(const Vector<T> &otherVector)
	{
		vector = new T[otherVector.size];
		size = otherVector.size;
		capacity = otherVector.capacity;
		for (int i = 0; i < otherVector.size; i++)
		{
			vector[i] = otherVector.vector[i];
		}
	};  //constructor de copiere
	T& operator[] (int index)
	{
		try {
			if (index >= size || index < 0)
				throw "Nu exista element pentru indexul curent";
		}
		catch (const char* txt) {
			cout << "Exception: " << txt << endl;
		}
		for (int i = 0; i < size; i++)
		{
			if (i == index)
			{
				return vector[i];
			}
		}
	};// arunca exceptie daca index este out of range
	const Vector<T>& operator+=(const T& newElem)
	{
		try {
			if (size >= capacity - 1)
				throw "Nu exista spatiu pentru a adauga noul element";
		}
		catch (const char* txt) {
			cout << "Exception: " << txt << endl;
		}

		vector[size] = newElem;
		size++;
		return *this;
	}; // adauga un element de tipul T la sfarsitul listei si returneaza this
	const Vector<T>& Insert(int index, const T& newElem)
	{
		try {
			if (size >= capacity - 1)
				throw "Nu se poate adauga elementul curent";
			if (index > size || index < 0)
				throw " Indexul este incorect";
		}
		catch (const char* txt) {
			cout << "Exception: " << txt << endl;
		}
		for (int i = size; i >= index; i--)
		{
			vector[i] = vector[i - 1];
		}
		vector[index] = newElem;
		size++;
		return *this;
	}; // adauga un element pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
	const Vector<T>& Insert(int index, const Vector<T> otherVector)
	{
		try {
			if (size + otherVector.size > capacity - 1)
				throw "Nu exista spatiu pentru a adauga lista de elemente";
			if (index >= size - otherVector.size || index < 0)
				throw "Indexul este incorect";
		}
		catch (const char* txt) {
			cout << "Exception: " << txt << endl;
		}
		for (int i = size + otherVector.size - 1; i > index; i--)
		{
			vector[i] = vector[i - otherVector.size];
		}
		for (int j = 0; j < otherVector.size; j++)
		{
			vector[index + j] = otherVector.vector[j];
		}
		size += otherVector.size;
		return *this;
	}; // adauga o lista pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
	const Vector<T>& Delete(int index)
	{
		try {
			if (index >= size || index < 0)
				throw "Index incorect";
		}
		catch (const char* txt) {
			cout << "Exception: " << txt << endl;
		}
		for (int i = index; i < size; i++)
		{
			vector[i] = vector[i + 1];
		}
		size--;
		return *this;
	}; // sterge un element de pe pozitia index, returneaza this. Daca index e invalid arunca o exceptie
	bool operator=(const Vector<T>& otherVector)
	{
		if (size != otherVector.size)
			return false;
		for (auto i : vector)
		{
			if (vector[i] != otherVector.vector[i])
				return false;
		}
		return true;
	};
	void Sort()
	{
		for (int i = 0; i < size; i++)
			for (auto j = i + 1; j < size; j++)
			{
				if (vector[i] > vector[j])
				{
					int aux = vector[i];
					vector[i] = vector[j];
					vector[j] = aux;
				}
			}
	}; // sorteaza folosind comparatia intre elementele din T
	void Sort(int(*compare)(const T&, const T&))
	{
		for (auto i : vector)
			for (auto j = i + 1; j < size; j++)
			{
				if (compare(vector[i], vector[j]) == -1)
				{
					int aux = vector[i];
					vector[i] = vector[j];
					vector[j] = aux;
				}
			}
	}
	; // sorteaza folosind o functie de comparatie
	void Sort(Compare* comparator)
	{
		for (auto i : vector)
			for (auto j = i + 1; j < size; j++)
			{
				if (comparator->CompareElements(vector[i], vector[j]))
				{
					int aux = vector[i];
					vector[i] = vector[j];
					vector[j] = aux;
				}
			}
	}; // sorteaza folosind un obiect de comparatie

	// functii de cautare - returneaza pozitia elementului sau -1 daca nu exista
	int BinarySearch(const T& elem)
	{
		int l = 0;
		int r = size - 1;
		while (l <= r) {
			int m = (l + r) / 2;

			if (vector[m] == elem)
				return m;

			if (vector[m] < elem)
				l = m + 1;
			else
				r = m - 1;
		}
		return -1;
	}; // cauta un element folosind binary search in Vector
	int BinarySearch(const T& elem, int(*compare)(const T&, const T&))
	{
		int l = 0;
		int r = size - 1;
		while (l <= r) {
			int m = (l + r) / 2;

			if (compare(vector[m], elem) == 0)     // vector[m]=elem
				return m;

			if (compare(vector[m], elem) == 1)  // vector[m]<elem
				l = m + 1;
			else
				r = m - 1;
		}
		return -1;
	};//  cauta un element folosind binary search si o functie de comparatie
	int BinarySearch(const T& elem, Compare* comparator)
	{
		int l = 0;
		int r = size - 1;
		while (l <= r) {
			int m = (l + r) / 2;

			if (comparator->CompareElements(vector[m], elem) == 0)  // vector[m]=elem
				return m;
			if (comparator->CompareElements(vector[m], elem) == 1) // vector[m]<elem
				l = m + 1;
			else
				r = m - 1;
		}
		return -1;
	}
	;//  cauta un element folosind binary search si un comparator
	int Find(const T& elem)
	{
		int ok = 0;
		try {
			for (auto i : vector)
			{
				if (vector[i] == elem)
				{
					ok = 1;
					return i;
				}
			}
			if (ok == 0)
				throw "Elementul nu s-a gasit in vector";
		}
		catch (const char* txt) {
			cout << "Exceptions: " << txt;
		}
	}; // cauta un element in Vector
	int Find(const T& elem, int(*compare)(const T&, const T&))
	{
		int ok = 0;
		try {
			for (auto i : vector)
			{
				if (compare(vector[i] == elem) == 0)
				{
					ok = 1;
					return i;
				}
			}
			if (ok == 0)
				throw "Elementul nu s-a gasit in vector";
		}
		catch (const char* txt) {
			cout << "Exceptions: " << txt;
		}

	};//  cauta un element folosind o functie de comparatie
	int Find(const T& elem, Compare* comparator)
	{
		int ok = 0;
		try {
			for (auto i : vector)
			{
				if (comparator->CompareElements(vector[i] == elem) == 0)
				{
					ok = 1;
					return i;
				}
			}
			if (ok == 0)
				throw "Elementul nu s-a gasit in vector";
		}
		catch (const char* txt) {
			cout << "Exceptions: " << txt;
		}

	};//  cauta un element folosind un comparator
	int GetSize()
	{
		return size;
	};
	int GetCapacity()
	{
		return capacity;
	};

	VectorIterator<T> GetBeginIterator()
	{
		return begin();
	};
	VectorIterator<T> GetEndIterator()
	{
		return end();
	};
};

