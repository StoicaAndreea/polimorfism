#pragma once
#include "Repository.h"
#include"RepositoryFile.h"
#include"User.h"
#include"Serie.h"
#include"Phone.h"
#include"Drone.h"

class Service
{
private:
	RepositoryTemplate<Serie>& repo;
	RepositoryTemplate<User>& repoUser;
	User activeUser;
public:
	//Service();
	Service(RepositoryTemplate<Serie> &r, RepositoryTemplate<User> &rep) :repo(r), repoUser(rep) { repo = r; repoUser = rep; };
	bool login(string, string);
	bool logedIn();
	void logout(/*string, string*/);
	//void loadFromFile(string, char);
	list<Serie> getAllSeries();
	int getSize();
	Serie getItemFromPos(int);
		//vector<Serie> getAllPhones();
	~Service();
};

