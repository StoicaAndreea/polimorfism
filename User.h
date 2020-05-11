#pragma once
#include <string>
using namespace std;

class User
{
private:
	string userName;
	string password;
public:
	User();
	User(string, char);
	User(string, string);
	void fromString(string,char);
	User* clone();
	string getUserName();
	string getPassword();
	void setUserName(string);
	void setPassword(string);
	bool operator==(const User& u);
	string toString();
	string toStringDelimiter(char delimiter);
	~User();
};

