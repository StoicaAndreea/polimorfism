#pragma once
#include "Repository.h"
#include"RepositoryFile.h"
#include"User.h"
#include"Phone.h"
#include"Phone.h"
#include"Drone.h"

class Service
{
private:
	RepositoryTemplate<Phone>& repo;
	RepositoryTemplate<User>& repoUser;
	User activeUser;
public:
	//Service();
	Service(RepositoryTemplate<Phone> &r, RepositoryTemplate<User> &rep) :repo(r), repoUser(rep) { repo = r; repoUser = rep; };
	bool login(string, string);
	bool logedIn();
	void logout(/*string, string*/);
	//void loadFromFile(string, char);
	list<Phone> getAllSeries();
	int getSize();
	Phone getItemFromPos(int);
		//vector<Phone> getAllPhones();
	~Service();
};

