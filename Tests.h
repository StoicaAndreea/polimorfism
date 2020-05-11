#pragma once
#include"Phone.h"
#include"Drone.h"
#include "Serie.h"
//#include "Serializer.h"
#include "SerializerSerie.h"
#include "SerializerUser.h"
#include"Repository.h"
#include"RepositoryFile.h"
#include "RepositoryFileCSV.h"
#include "RepositoryFileHTML.h"
#include"Service.h"

class Tests {
private:
	//RepositoryFile<Serie*> repof;
	//RepositoryTemplate<Phone*> repo;
	//Service serv();
public:
	Tests();
	void testDomainPhone();
	void testDomainDrone();
	//void testDomainSerie();
	void testRepoTemplate();
	void testRepoFileSerie();
	void testRepoFileCSV();
	void testRepoFileHTML();
	void testService();
	~Tests();
};
