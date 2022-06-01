#pragma once
#include "Contact.h"
class Agenda
{
	Contact** C;
	int nr_of_contacts;
public:
	Agenda();
	Contact* Search_by_name(const char* n);
	Contact** Friends_contact();
	void Delete_contact(const char* n);
	void Add_contact(Contact* contact);
};

