#pragma once
#include "Serie.h"
#include<iostream>
#include<string>
using namespace std;
#include <vector>
class Phone:public Serie {
private:
	//char* producer;
	//char* model;
	//int units;
	vector<char*>operators;
public:
	Phone();
	Phone(const char*, const char*, int, vector<char*>);
	Phone(const Phone&);
	Phone& operator= (const Phone&);
	Phone(string); //conversion
	Serie* clone();
	/*char* getProducer();
	char* getModel();
	int getUnits();*/
	vector<char*> getOperators();
	/*void setProducer(const char*);
	void setModel(const char*);
	void setUnits(int);*/
	void setOperators(vector<char*>);

	//bool operator ==(const Phone&);
	//bool operator <(const Phone&);
	//void fromString(std::string info);
	friend ostream& operator <<(ostream& os, Phone e);
	friend istream& operator >>(istream& is, Phone& e);

	~Phone();
};