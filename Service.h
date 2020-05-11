#pragma once
#include "Repository.h"
#include"RepositoryFile.h"
#include"User.h"
#include"Serie.h"
#include"Phone.h"
#include"Drone.h"
#include "SerieValidator.h"
#include "PhoneValidator.h"

class Service
{
private:
	RepositoryTemplate<Serie*>& repo;
	RepositoryTemplate<User*>& repoUser;
	User activeUser;
	SerieValidator sv;
	PhoneValidator pv;
public:
	//Service();
	Service(RepositoryTemplate<Serie*>& r, RepositoryTemplate<User*>& rep) :repo(r), repoUser(rep) { repo = r; repoUser = rep;};
	bool login(string, string);
	bool logedIn();
	void logout(/*string, string*/);
	bool isPositiveInteger(const std::string& s);
	list<Serie*> findProducer(string);
	list<Serie*> getAllSeries();
	int getSize();
	Serie* getItemFromPos(int);
	void addElem(Serie* &s);
	void deleteElem(Serie*& s);
	void updateElem(Serie* s, Serie*& n);
	~Service();
};

