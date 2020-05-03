#include "PhoneValidator.h"
using namespace std;
//SerieException::SerieException(vector<string>_errors) : errors{ _errors } {}
//vector<string> SerieException::getErrors() const {
//	return this->errors;
//}
void PhoneValidator::validate(Phone& s){
	vector<string> errors;
	if (s.getUnits() < 100) {
		errors.push_back("The units must be >100\n");
	}
	if (s.getOperators().size()<1) {
		errors.push_back("The phone must have at least obe operator in the list");

	}
}