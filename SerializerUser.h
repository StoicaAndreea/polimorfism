#pragma once
#include <sstream>
#include "User.h"
#include "Phone.h"
#include "Drone.h"
#include "Serializer.h"
class SerializerUser :public Serializer<User*> {
public:
	SerializerUser() {}
	inline User* fromString(string, char);
	~SerializerUser() {}
};

User* SerializerUser::fromString(string line, char delim) {
	vector<string> tokens;
	stringstream ss(line);
	string item;
	while (getline(ss, item, delim)) {
		tokens.push_back(item);
	}
	User*u = new User(line, delim);
	return u;
	/*if (tokens.size() == 4) {
		try {
			int i = stoi(tokens[3]);
			User* d = new Drone(line, delim);
			return d;
		}
		catch (...) {
			User* d = new Phone(line, delim);
			return d;
		}
	}*/
}