#pragma once
#include<string>
#include<iostream>
using namespace std;

#ifndef SERIE_H
#define SERIE_H
class Serie {
protected:
	char* producer;
	char* model;
	int units;
public:
	Serie();
	Serie(const char*, const char*, int);
	Serie(const Serie&);
	virtual Serie& operator= (const Serie&);
	Serie(string); //conversion
	virtual ~Serie();
	virtual Serie* clone();
	char* getProducer();
	char* getModel();
	int getUnits();
	void setProducer(const char*);
	void setModel(const char*);
	void setUnits(int);

	virtual bool operator ==(const Serie&);
	virtual bool operator <(const Serie&);
	friend ostream& operator <<(ostream& os, Serie e);
	friend istream& operator >>(istream& is, Serie& e);
};
#endif