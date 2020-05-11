#include "PhoneValidator.h"
using namespace std;
PhoneException::PhoneException(vector<string>_errors) : errors{ _errors } {}
vector<string> PhoneException::getErrors() const {
	return this->errors;
}
void PhoneValidator::validate(Phone* s){
	vector<string> errors;
	if ((*s).getUnits() < 100) {
		errors.push_back("The units must be >100\n");
	}
	if ((*s).getOperators().size()<1) {
		errors.push_back(string("The phone must have at least one operator in the list"));

	}
	if (errors.size() > 0) throw PhoneException(errors);
}