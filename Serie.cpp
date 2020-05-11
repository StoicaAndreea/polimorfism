#include"Serie.h"
#include<string.h>
#include <sstream>

Serie::Serie() {
	this->producer = NULL;
	this->model = NULL;
	this->units = 0;
}

Serie::Serie(const char* producer, const char* model, int units) {
	if (producer) {
		this->producer = new char[strlen(producer) + 1];
		strcpy_s(this->producer, strlen(producer) + 1, producer);
	}
	this->units = units;
	if (model) {
		this->model = new char[strlen(model) + 1];
		strcpy_s(this->model, strlen(model) + 1, model);
	}
}

Serie::Serie(const Serie& e) {
	if (e.producer) {
		this->producer = new char[strlen(e.producer) + 1];
		strcpy_s(this->producer, strlen(e.producer) + 1, e.producer);
	}
	this->units = e.units;
	if (e.model) {
		this->model = new char[strlen(e.model) + 1];
		strcpy_s(this->model, strlen(e.model) + 1, e.model);
	}
}

Serie::Serie(string line,char delim) {
	vector<string> tokens = splitLine(line, delim);
	this->producer = new char[tokens[0].length() + 1];
	strcpy_s(this->producer, tokens[0].length() + 1, tokens[0].c_str());

	this->model = new char[tokens[1].length() + 1];
	strcpy_s(this->model, tokens[1].length() + 1, tokens[1].c_str());
	units = stoi(tokens[2]);
}

//void Serie::fromString(string line, char delim) {
//	//Serie(line, delim);
//	vector<string> tokens = splitLine(line, delim);
//	this->producer = new char[tokens[0].length() + 1];
//	strcpy_s(this->producer, tokens[0].length() + 1, tokens[0].c_str());
//
//	this->model = new char[tokens[1].length() + 1];
//	strcpy_s(this->model, tokens[1].length() + 1, tokens[1].c_str());
//	units = stoi(tokens[2]);
//}
Serie::~Serie() {
	if (this->producer) {
		delete[] this->producer;
		this->producer = NULL;
	}
	if (this->model) {
		delete[] this->model;
		this->model = NULL;
	}
}
Serie* Serie::clone() {
	Serie* newSerie = new Serie();
	newSerie->setProducer(this->producer);
	newSerie->setModel(this->model);
	newSerie->setUnits(this->units);
	return newSerie;
}
char* Serie::getProducer() {
	return this->producer;
}

char* Serie::getModel() {
	return this->model;
}

int Serie::getUnits() {
	return this->units;
}


void Serie::setProducer(const char* producer) {
	if (this->producer) {
		delete[] this->producer;
	}
	this->producer = new char[strlen(producer) + 1];
	strcpy_s(this->producer, strlen(producer) + 1, producer);
}

void Serie::setModel(const char* model) {
	if (this->model) {
		delete[] this->model;
	}
	this->model = new char[strlen(model) + 1];
	strcpy_s(this->model, strlen(model) + 1, model);
}

void Serie::setUnits(int units) {
	this->units = units;
}
Serie& Serie::operator =(const Serie& e) {
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
	return *this;
}

bool Serie::operator==(const Serie& e) {
	if (this->producer and e.producer and this->model and e.model) {
		return (strcmp(this->producer, e.producer) == 0) and (strcmp(this->model, e.model) == 0) and (this->units == e.units);
	}
	return false;
}

bool Serie::operator<(const Serie& e) {
	return (strcmp(this->producer, e.producer) < 0);
}
string Serie::toString() {
	string x, y;
	x = this->producer;
	y = this->model;
	return  x + " " + y + " " + to_string(this->units);
}
string Serie::toStringDelimiter(char delim) {
	string x, y;
	x = this->producer;
	y = this->model;
	return  x + delim + y + delim + to_string(this->units);
}
ostream& operator<<(ostream& os, Serie e) {
	os << e.producer << " " << e.model << " " << e.units << endl;
	return os;
}

istream& operator >>(istream& is, Serie& e) {
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


	e.setProducer(producer);
	e.setModel(model);
	e.setUnits(units);
	delete[] producer;
	delete[] model;
	return is;
}