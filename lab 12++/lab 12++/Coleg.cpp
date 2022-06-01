#include "Coleg.h"

Coleg::Coleg(const char* name,const char* num, const char* c, const char* a)
{
	this->name = name;
	this->company = c;
	this->num = num;
	this->adress = a;

}

const char* Coleg::Type_of_contact()
{
	return "Coleg";
}
