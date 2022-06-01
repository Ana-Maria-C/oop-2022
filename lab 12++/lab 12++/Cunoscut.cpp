#include "Cunoscut.h"

Cunoscut::Cunoscut(const char* name, const char* num)
{
	this->name = name;
	this->number_ = num;
}

const char* Cunoscut::Type_of_contact()
{
	return "Cunoscut";
}
