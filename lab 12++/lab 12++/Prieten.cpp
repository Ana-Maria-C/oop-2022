#include "Prieten.h"

Prieten::Prieten(const char* name, const char* d, const char* num, const char* a)
{
	this->name = name;
	this->date = d;
	this->number = num;
	this->adress = a;
}

const char* Prieten::Type_of_contact()
{
	return "Prieten";
}
