#pragma once
#include"Serie.h"
#include <string>
#include<vector>
using namespace std;

class SerieException
{
private:
    vector<string>errors;
public:
    SerieException(vector<string> _errors);
    vector<string> getErrors() const;
};

class SerieValidator {
public:
    SerieValidator() {};
    void validate(Serie*& m);
};