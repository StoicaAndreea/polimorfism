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
	vector<string>operators;
public:
	Phone();
	Phone(const char*, const char*, int, vector<string>);
	Phone(const Phone&);
	Phone& operator= (const Phone&);
	Phone(string,char); //conversion
	Serie* clone();
	//void fromString(string, char);
	/*char* getProducer();
	char* getModel();
	int getUnits();*/
	vector<string> getOperators();
	/*void setProducer(const char*);
	void setModel(const char*);
	void setUnits(int);*/
	void setOperators(vector<string>);

	//bool operator ==(const Phone&);
	//bool operator <(const Phone&);
	friend ostream& operator <<(ostream& os, Phone e);
	friend istream& operator >>(istream& is, Phone& e);
	string toString();
	string toStringDelimiter(char);
	~Phone();
};