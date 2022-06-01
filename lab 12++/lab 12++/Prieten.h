#pragma once
#include "Contact.h"
class Prieten :
    public Contact
{
    const char* date;
    const char* number;
    const char* adress;
public:
    Prieten(const char *name, const char* d, const char* num, const char* a);
    const char* Type_of_contact() override;
};

