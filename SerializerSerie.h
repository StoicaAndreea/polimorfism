#pragma once
#include <sstream>
#include "Serie.h"
#include "Phone.h"
#include "Drone.h"
#include "Serializer.h"
class SerializerSerie:public Serializer<Serie*> {
public:
	SerializerSerie(){}
	inline Serie* fromString(string, char);
	~SerializerSerie(){}
};

Serie* SerializerSerie::fromString(string line, char delim) {
	vector<string> tokens;
	stringstream ss(line);
	string item;
	while (getline(ss, item, delim)) {
		tokens.push_back(item);
	}
	if (tokens.size() == 4) {
		try {
			int i = stoi(tokens[3]);
			Serie* d = new Drone(line, delim);
			return d;
		}
		catch (...) {
			Serie* d = new Phone(line, delim);
			return d;
		}
	}
}