#pragma once
#include "Contact.h"
class Coleg :
    public Contact
{
    const char* num;
    const char* company;
    const char* adress;
public:
    Coleg(const char* name, const char* n, const char* c, const char* a);
    const char* Type_of_contact()override;
};

