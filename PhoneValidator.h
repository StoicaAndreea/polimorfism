#pragma once
#include "Phone.h"
#include"SerieValidator.h"

class PhoneException
{
private:
   vector<string>errors;
public:
    PhoneException(vector<string> _errors);
    vector<string> getErrors() const;
};

class PhoneValidator/*: public SerieValidator*/ {
public:
    PhoneValidator() {}
    void validate(Phone* m);
};