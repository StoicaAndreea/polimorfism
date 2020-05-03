#pragma once
#include"Phone.h"
#include"Drone.h"
#include "Serie.h"
#include"Repository.h"
#include"RepositoryFile.h"
#include"Service.h"
class Tests {
private:
	RepositoryFile<Drone> repof;
	RepositoryTemplate<Phone> repo;
	//Service serv();
public:
	Tests();
	void testDomainPhone();
	void testDomainDrone();
	//void testDomainSerie();
	void testRepoTemplate();
	//void testRepoFile();
	void testRepoFilePhone();
	void testRepoFileSerie();
	void testRepoFile();
	void testService();
	~Tests();
};
