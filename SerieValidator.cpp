#include "SerieValidator.h"
using namespace std;

SerieException::SerieException(vector<string>_errors) : errors{ _errors } {}
vector<string> SerieException::getErrors() const {
	return this->errors;
}

void SerieValidator::validate(Serie& s) {
	vector<string> errors;
	if (s.getUnits() < 100) {
		errors.push_back("The units must be >100\n");
	}
}