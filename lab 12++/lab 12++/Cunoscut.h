#pragma once
#include "Contact.h"
class Cunoscut :
    public Contact
{
    const char* number_;
public:
    Cunoscut(const char* name, const char* num);
    const char* Type_of_contact()override;
};

