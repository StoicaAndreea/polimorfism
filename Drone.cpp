#include "Drone.h"
#include<string.h>
#include<sstream>

Drone::Drone() {
	//this->producer = NULL;
	//this->model = NULL;
	//this->units = 0;
	this->rotors = 0;
}
Drone::Drone(const char* producer, const char* model, int units, int rotors):Serie(producer, model, units) {
	/*if (producer) {
		this->producer = new char[strlen(producer) + 1];
		strcpy_s(this->producer, strlen(producer) + 1, producer);
	}
	this->units = units;
	if (model) {
		this->model = new char[strlen(model) + 1];
		strcpy_s(this->model, strlen(model) + 1, model);
	}*/
	this->rotors = rotors;
}

Drone::Drone(const Drone&e):Serie(e) {
	/*if (e.producer) {
		this->producer = new char[strlen(e.producer) + 1];
		strcpy_s(this->producer, strlen(e.producer) + 1, e.producer);
	}
	this->units = e.units;
	if (e.model) {
		this->model = new char[strlen(e.model) + 1];
		strcpy_s(this->model, strlen(e.model) + 1, e.model);
	}*/
	this->rotors = e.rotors;
}

Drone::Drone(string line) {
	std::istringstream iss(line);
	string tok1, tok2, tok3, tok4;
	iss >> tok1 >> tok2 >> tok3>>tok4;
	this->producer = new char[tok1.length() + 1];
	strcpy_s(this->producer, tok1.length() + 1, tok1.c_str());
	this->model = new char[tok2.length() + 1];
	strcpy_s(this->model, tok2.length() + 1, tok2.c_str());
	this->units = stoi(tok3);
	this->rotors = stoi(tok4);
}
Drone::~Drone() {
	if (this->producer) {
		delete[] this->producer;
		this->producer = NULL;
	}
	if (this->model) {
		delete[] this->model;
		this->model = NULL;
	}
}
Serie* Drone::clone() {
	Drone* newSerie = new Drone();
	newSerie->setProducer(this->producer);
	newSerie->setModel(this->model);
	newSerie->setUnits(this->units);
	newSerie->setRotors(this->rotors);
	return newSerie;
}
//char* Drone::getProducer() {
//	return this->producer;
//}
//
//char* Drone::getModel() {
//	return this->model;
//}
//
//int Drone::getUnits() {
//	return this->units;
//}

int Drone::getRotors() {
	return this->rotors;
}
//void Drone::setProducer(const char* producer) {
//	if (this->producer) {
//		delete[] this->producer;
//	}
//	this->producer = new char[strlen(producer) + 1];
//	strcpy_s(this->producer, strlen(producer) + 1, producer);
//}
//
//void Drone::setModel(const char* model) {
//	if (this->model) {
//		delete[] this->model;
//	}
//	this->model = new char[strlen(model) + 1];
//	strcpy_s(this->model, strlen(model) + 1, model);
//}
//
//void Drone::setUnits(int units) {
//	this->units = units;
//}

void Drone::setRotors(int rotors) {
	this->rotors = rotors;
}

Drone& Drone::operator =(const Drone& e) {
	if (this == &e) return *this;
	if (e.producer) {
		if (this->producer) delete[] this->producer;
		this->producer = new char[strlen(e.producer) + 1];
		strcpy_s(this->producer, strlen(e.producer) + 1, e.producer);
	}
	if (e.model) {
		if (this->model)delete[]this->model;
		this->model = new char[strlen(e.model) + 1];
		strcpy_s(this->model, strlen(e.model) + 1, e.model);
	}
	this->units = e.units;
	this->rotors = e.rotors;
}

//bool Drone::operator ==(const Drone& e) {
//	if (this->producer and e.producer and this->model and e.model) {
//		return (strcmp(this->producer, e.producer) == 0) and (strcmp(this->model, e.model) == 0) and (this->units == e.units);
//	}
//	return false;
//}
//
//bool Drone::operator<(const Drone& e) {
//	return (strcmp(this->producer, e.producer) < 0);
//}

ostream& operator<<(ostream& os, Drone e) {
	os << e.producer << " " << e.model << " " << e.units << " "<<e.rotors << endl;
	return os;
}

istream& operator>>(istream& is, Drone& e) {
	cout << "Give the producer: ";
	char* producer = new char[10];
	is >> producer;
	cout << "Give the model: ";
	char* model = new char[10];
	is >> model;
	cout << "Give the units: ";
	int units;
	is >> units;
	cout << "Give the rotors: ";
	int rotors;
	is >> rotors;
	e.setProducer(producer);
	e.setModel(model);
	e.setUnits(units);
	e.setRotors(rotors);
	delete[] producer;
	delete[] model;
	return is;
}