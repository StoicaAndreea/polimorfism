#include "Phone.h"
#include <string.h>
#include <sstream>

Phone::Phone():Serie(){
	//this->producer = NULL;
	//this->model = NULL;
	//this->units = 0;
	//this->operators = {};
}

Phone::Phone(const char* producer, const char* model, int units, vector<char*>operators):Serie(producer,model, units){
	/*if (producer) {
		this->producer = new char[strlen(producer) + 1];
		strcpy_s(this->producer, strlen(producer) + 1, producer);
	}
	this->units = units;
	if (model) {
		this->model = new char[strlen(model) + 1];
		strcpy_s(this->model, strlen(model) + 1, model);
	}*/
	this->operators = operators;
}

Phone::Phone(const Phone& e):Serie(e) {
	/*if (e.producer) {
		this->producer = new char[strlen(e.producer) + 1];
		strcpy_s(this->producer, strlen(e.producer) + 1, e.producer);
	}
	this->units = e.units;
	if (e.model) {
		this->model = new char[strlen(e.model) + 1];
		strcpy_s(this->model, strlen(e.model) + 1, e.model);
	}*/
	this->operators = e.operators;
}

Phone::Phone(string line) {
	std::istringstream iss(line);
	string tok1, tok2, tok3, tok4;
	iss >> tok1 >> tok2 >> tok3>> tok4;
	this->producer = new char[tok1.length() + 1];
	strcpy_s(this->producer, tok1.length() + 1, tok1.c_str());
	this->model = new char[tok2.length() + 1];
	strcpy_s(this->model, tok2.length() + 1, tok2.c_str());
	this->units = stoi(tok3);
	
	std::string delim = "-";
	//cout << tok4 << endl;

	//size_t pos = 0;
	std::string token;
	//while ((pos = tok4.find(delimiter)) != std::string::npos) {
	//	token = tok4.substr(0, pos);
	//	cout <<"token:"<< token << endl;
	//	char* c = new char[sizeof(token)+1];
	//	for (int i = 0; i < sizeof(token); i++) {
	//		c[i] = token[i];
	//		//cout << c[i];
	//	}
	//	this->operators.push_back(c);
	//	//cout << this->operators[0]<<endl;
	//	tok4.erase(0, pos + delimiter.length());
	//	delete[] c;
	//}
	//char* c = new char[sizeof(token) + 1];
	//for (int i = 0; i < sizeof(token); i++) {
	//	c[i] = token[i];
	//}
	//if(c) this->operators.push_back(c);
	//delete[]c;

	size_t prev = 0, pos = 0;
	do
	{
		pos = tok4.find(delim, prev);
		if (pos == string::npos) pos = tok4.length();
		{string token = tok4.substr(prev, pos - prev);
		}
		if (!token.empty()) { 
			char* c = new char[sizeof(token) + 1];
			for (int i = 0; i < sizeof(token); i++) {
				c[i] = token[i];
			}
			if (c) { this->operators.push_back(c);}
			delete[] c;
		}
		prev = pos + delim.length();
	} while (pos < tok4.length() && prev < tok4.length());
	cout << "hihi";
	//AICI TREBUIE GANDITTT
}
Serie* Phone::clone() {
	Phone* newSerie = new Phone();
	newSerie->setProducer(this->producer);
	newSerie->setModel(this->model);
	newSerie->setUnits(this->units);
	newSerie->setOperators(this->operators);
	return newSerie;
}
//char* Phone::getProducer() {
//	return this->producer;
//}
//
//char* Phone::getModel() {
//	return this->model;
//}
//
//int Phone::getUnits() {
//	return this->units;
//}
vector<char*> Phone::getOperators() {
	return this->operators;
}

//void Phone::setProducer(const char* producer) {
//	if (this->producer) {
//		delete[] this->producer;
//	}
//	this->producer = new char[strlen(producer) + 1];
//	strcpy_s(this->producer, strlen(producer) + 1, producer);
//}
//
//void Phone::setModel(const char* model) {
//	if (this->model) {
//		delete[] this->model;
//	}
//	this->model = new char[strlen(model) + 1];
//	strcpy_s(this->model, strlen(model) + 1, model);
//}
//
//void Phone::setUnits(int units) {
//	this->units = units;
//}
void Phone::setOperators(vector<char*> operators) {
	this->operators =operators;
}
Phone::~Phone() {
	if (this->producer) {
		delete[] this->producer;
		this->producer = NULL;
	}
	if (this->model) {
		delete[] this->model;
		this->model = NULL;
	}
}

Phone& Phone::operator =(const Phone& e) {
	if (this == &e) return *this; //in case of self assignment
	if (e.producer) {
		if (this->producer)delete[]this->producer;
		this->producer = new char[strlen(e.producer) + 1];
		strcpy_s(this->producer, strlen(e.producer) + 1, e.producer);
	}
	if (e.model) {
		if (this->model)delete[]this->model;
		this->model = new char[strlen(e.model) + 1];
		strcpy_s(this->model, strlen(e.model) + 1, e.model);
	}
	this->units = e.units;
	this->operators = e.operators; //VEZI SI AICI
	return *this;
}

//bool Phone::operator==(const Phone& e) {
//	if (this->producer and e.producer and this->model and e.model) {
//		return (strcmp(this->producer, e.producer) == 0) and (strcmp(this->model, e.model) == 0) and (this->units==e.units);
//	}
//	return false;
//}
//
//bool Phone::operator<(const Phone& e) {
//	return (strcmp(this->producer, e.producer) < 0);
//}

ostream& operator<<(ostream& os, Phone e) {
	os << e.producer << " " << e.model << " " << e.units << " "; //<< endl;
	for (int i = 0; i < e.operators.size() - 1; i++)
		os << e.operators[i] << "-";
	os << e.operators[e.operators.size() - 1] << endl;
	return os;
	//de verificat
}

istream& operator >>(istream& is, Phone& e) {
	cout << "Give the producer: ";
	char* producer = new char[10];
	is >> producer;
	cout << "Give the model: ";
	char* model = new char[10];
	is >> model;
	cout << "Give the units: ";
	int units;
	is >> units;
	int ok = 0;
	vector<char*> operators;
	cout << "Give the operators";
	char* op = new char[10];
	is >> op;
	while (strcmp(op, "0") != 0)
		operators.push_back(op);

	e.setProducer(producer);
	e.setModel(model);
	e.setUnits(units);
	e.setOperators(operators);
	delete[] producer;
	delete[] model;
	delete[] op;
	//vezi aici de stergerea vectorului
	return is;
}