#pragma once
#include"Serie.h"
#include<string>
#include<iostream>
using namespace std;
#ifndef DRONE_H
#define DRONE_H
class Drone: public Serie {
private:
	/*char* producer;
	char* model;
	int units;*/
	int rotors;
public:
	Drone();
	Drone(const char*, const char*, int, int);
	Drone(const Drone&);
	Drone(string,char);//conversion
	//void fromString(string,char);
	~Drone();
	Serie* clone();
	/*char* getProducer();
	char* getModel();
	int getUnits();*/
	int getRotors();

	/*void setProducer(const char*);
	void setModel(const char*);
	void setUnits(int);*/
	void setRotors(int);

	Drone& operator=(const Drone&);
	/*bool operator ==(const Drone&);
	bool operator<(const Drone&);*/

	friend ostream& operator <<(ostream& os, Drone e);
	friend istream& operator >> (istream& is, Drone& e);
	string toString();
	string toStringDelimiter(char);
};
#endif