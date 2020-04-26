#include "Tests.h"
#include "assert.h"
#include<iostream>
#include<string.h>
#include <vector>
#include <list>
using namespace std;
Tests::Tests() {
}

void Tests::testDomainPhone() {
	vector<char*> v;
	Phone e1("pppp", "MS 74 SSC", 1, v);
	Phone e2(e1);
	Phone e3;
	Phone e4("eee eee 1 orange-cosmote");
	assert(strcmp(e4.getOperators()[0], "orange") == 0);
	assert(e3.getProducer() == NULL);
	assert(e3.getModel() == NULL);
	assert(e3.getUnits() == 0);
	e3 = e2;
	assert(strcmp(e3.getProducer(), "pppp") == 0);
	assert(strcmp(e2.getProducer(), "pppp") == 0);
	assert(e1 == e2);
	e2.setModel("MS 74 AAA");
	assert(strcmp(e2.getModel(), "MS 74 AAA") == 0);
	cout << "super"<<endl;
}

void Tests::testDomainDrone() {
	Drone e1("pppp", "MS 74 SSC", 1, 1);
	Drone e2(e1);
	Drone e3;
	Drone e4("pp aa 1 1");
	assert(e4.getRotors() == 1);
	assert(e3.getProducer() == NULL);
	assert(e3.getModel() == NULL);
	assert(e3.getUnits() == 0);
	e3 = e2;
	assert(strcmp(e3.getProducer(), "pppp") == 0);
	assert(strcmp(e2.getProducer(), "pppp") == 0);
	assert(e1 == e2);
	e2.setModel("MS 74 AAA");
	assert(strcmp(e2.getModel(), "MS 74 AAA") == 0);
}
void Tests::testRepoTemplate() {
	vector<char*> v;
	char* c = new char[10];
	strcpy_s(c, 7, "orange");
	v.push_back(c);
	Phone e1("aaa", "MS 74 SSC", 1,v);
	Phone e2("bbb", "MS 75 SSC", 1,v);
	Phone e3("ccc", "MS 76 SSC", 1,v);
	Phone e4("ddd", "MS 77 SSC", 1,v);
	RepositoryTemplate<Phone> rep;
	rep.addElem(e1);
	rep.addElem(e2);
	rep.addElem(e3);
	rep.addElem(e4);
	assert(rep.getSize() == 4);
	assert(rep.getAll().front() == e1);
	assert(rep.getAll().back() == e4);
	assert(rep.getItemFromPos(0) == e1);
	Phone elemArray[] = { e1,e2,e3,e4 };
	list <Phone> elem;
	elem = rep.getAll();
	list <Phone>::iterator it;
	int i = 0;
	for (it = elem.begin(); it != elem.end() and i < 4; ++it)
	{
		assert(*it == elemArray[i]);
		i++;

	}
	Phone e0("eee", "MS 77 SSA", 1,v);
	Phone e01("bbb", "aaa", 1,v);
	assert(rep.findElem(e4) == 3);
	assert(rep.findElem(e0) == -1);
	rep.deleteElem(e3);
	assert(rep.findElem(e3) == -1);
	assert(rep.getSize() == 3);
	Phone e("bbb", "aaa", 1,v);
	rep.updateElem(e1, e);
	assert(rep.getItemFromPos(0) == e01);
}

void Tests::testRepoFile() {
	RepositoryFile<Drone> repof ("Tests.txt", "Tests.csv");
	vector<char*> v;
	char* c = new char[10];
	strcpy_s(c, 7, "orange");
	v.push_back(c);
	//assert(repof.getSize() == 0);
	//repof.loadFromFile("Tests.txt");
	assert(repof.getSize() == 4);
	repof.addElem(Drone("aaa", "bbb", 1,1));
	assert(repof.getSize() == 5);
	repof.saveToFile();
	repof.loadFromFile("Tests.txt");
	assert(repof.findElem(Drone("aaa", "bbb", 1,1)) == 4);
	assert(repof.findElem(Drone("abc", "aaa", 1,1)) == -1);
	repof.saveToFile();
	repof.loadFromFile("Tests.txt");
	repof.deleteElem(Drone("aaa", "bbb", 1,1));
	assert(repof.getSize() == 4);
	repof.saveToFile();
	repof.loadFromFile("Tests.txt");
	list<Drone> rez = repof.getAll();
	assert(rez.size() == 4);
	repof.saveToFile();
	repof.loadFromFile("Tests.txt");
	repof.updateElem(Drone("bbb", "aaa", 1,1), Drone("abc", "aaa", 1,1));
	assert(repof.findElem(Drone("abc", "aaa", 1,1)) == 0);
	repof.saveToFile();
	repof.loadFromFile("Tests.txt");
	assert(repof.getItemFromPos(0) == Drone("abc", "aaa", 1,1));
	repof.saveToFile();
	repof.loadFromFile("Tests.txt");
	assert(repof.getSize() == 4);

}
void Tests::testRepoFilePhone() {
	RepositoryFile<Phone> repof("Tests.txt", "Tests.csv");
	vector<char*> v;
	char* c = new char[10];
	strcpy_s(c, 7, "orange");
	delete[] c;
	//char* c = new char[10];
	strcpy_s(c, 7, "-cosmote");
	v.push_back(c);
	//assert(repof.getSize() == 0);
	//repof.loadFromFile("Tests.txt");
	assert(repof.getSize() == 4);
	repof.addElem(Phone("aaa", "bbb", 1, v));
	assert(repof.getSize() == 5);
	repof.saveToFile();
	repof.loadFromFile("Tests.txt");
	assert(repof.findElem(Phone("aaa", "bbb", 1, v)) == 4);
	assert(repof.findElem(Phone("abc", "aaa", 1, v)) == -1);
	repof.saveToFile();
	repof.loadFromFile("Tests.txt");
	repof.deleteElem(Phone("aaa", "bbb", 1, v));
	assert(repof.getSize() == 4);
	repof.saveToFile();
	repof.loadFromFile("Tests.txt");
	list<Phone> rez = repof.getAll();
	assert(rez.size() == 4);
	repof.saveToFile();
	repof.loadFromFile("Tests.txt");
	repof.updateElem(Phone("bbb", "aaa", 1, v), Phone("abc", "aaa", 1, v));
	assert(repof.findElem(Phone("abc", "aaa", 1, v)) == 0);
	repof.saveToFile();
	repof.loadFromFile("Tests.txt");
	assert(repof.getItemFromPos(0) == Phone("abc", "aaa", 1, v));
	repof.saveToFile();
	repof.loadFromFile("Tests.txt");
	assert(repof.getSize() == 4);
}
Tests::~Tests() {
}
//void Tests::testService() {
//	RepositoryFile<Phone> repof("servTest.txt");
//	//repof.loadFromFile("servTest.txt");
//	Service serv(repof);
//	Phone e1("aaa", "MS 74 SSC", "free");
//	Phone e2("bbb", "MS 75 SSC", "occupied");
//	Phone e3("ccc", "MS 76 SSC", "free");
//	Phone e4("ddd", "MS 77 SSC", "free");
//	Phone e0("eee", "MS 77 SSA", "free");
//	Phone e01("bbb", "aaa", "free");
//	serv.addEntity(e1);
//	serv.addEntity(e2);
//	serv.addEntity(e3);
//	serv.addEntity(e4);
//	serv.addEntity(e0);
//	assert(serv.getSize() == 5);
//	assert(serv.getItemFromPos(0) == e1);
//	assert(serv.findElem(e2) == 1);
//	int n = serv.delEntity(e0);
//	assert(serv.findElem(e0) == -1);
//	serv.updateEntity(e1, "aha", "aaa", "free");
//	assert(strcmp(serv.getItemFromPos(0).getUnits(), "free") == 0);
//	Phone e("aha", "aaa", "free");
//	try {
//		serv.intrare(e);
//		assert(strcmp(serv.getItemFromPos(0).getUnits(), "occupied") == 0);
//		serv.intrare(e3);
//		serv.intrare(e4);
//	}
//	catch (exception e) { cout << endl; }
//	e.setStatus("occupied");
//	try {
//		serv.iesire(e);
//		assert(strcmp(serv.getItemFromPos(0).getUnits(), "free") == 0);
//	}
//	catch (exception e) { cout << endl; }
//	assert(serv.maxEntitys() == 1);
//}
