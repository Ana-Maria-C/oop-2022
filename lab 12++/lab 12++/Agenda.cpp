#include "Agenda.h"
Agenda::Agenda()
{
	*this->C = new Contact;
	this->nr_of_contacts = 0;
}

Contact* Agenda::Search_by_name(const char* n)
{
	if (nr_of_contacts == 0)
		throw "Nu exista nume in agenda";
	for (int i = 0; i < nr_of_contacts; i++)
	{
		if (C[i]->name == n)
			return C[i];
	}
	return nullptr;
}

Contact** Agenda::Friends_contact()
{
	Contact* list_of_friends[50];
	int friend_ = 0;
	for (int i = 0; i < nr_of_contacts; i++)
	{
		if (C[i]->Type_of_contact() == "Prieten")
		{
			list_of_friends[friend_++] = C[i];
		}
	}
	if (friend_ == 0)
		throw "Contactul nu are prieteni :((";
	return list_of_friends;
}



void Agenda::Delete_contact(const char* n)
{
	int ok = 0;
	for (int i = 0; i < nr_of_contacts; i++)
	{
		if (C[i]->name == n)
		{
			ok = 1;
			for (int j = i; j < nr_of_contacts; j++)
			{
				C[j] = C[j + 1];
			}
		}
	}
	if (ok)
		nr_of_contacts--;
	else
		throw "Contactul nu a fost gasit";
}

void Agenda::Add_contact(Contact* contact)
{
	C[nr_of_contacts]->name = contact->name;
	nr_of_contacts++;
}
