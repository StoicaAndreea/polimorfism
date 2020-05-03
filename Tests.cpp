#include "Tests.h"
#include "assert.h"
#include<iostream>
#include<string.h>
#include <vector>
#include <list>
#include "RepositoryFileCSV.h"
using namespace std;
Tests::Tests() {
}

void Tests::testDomainPhone() {
	vector<string> v;
	string c;
	c = "orange";
	v.push_back(c);
	Phone e1("pppp", "MS 74 SSC", 1, v);
	Phone e2(e1);
	Phone e3;
	Phone e4("eee eee 1 orange-cosmote",' ');
	assert(e4.getOperators()[0]== "orange");
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
	Drone e4("pp aa 1 1",' ');
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
	vector<string> v;
	string c;
	c ="orange";
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

void Tests::testRepoFilePhone() {
	RepositoryFile<Phone> repof ("Tests.txt", ' ');
	vector<string> v;
	string c;
	c = "orange";
	v.push_back(c);
	c = "cosmote";
	v.push_back(c);
	assert(repof.getSize() == 4);
	Phone a("aaa", "bbb", 1, v);
	repof.addElem(a);
	assert(repof.getSize() == 5);
	assert(repof.findElem(a) == 4);
	Phone b("abc", "aaa", 1, v);
	assert(repof.findElem(b) == -1);
	repof.deleteElem(a);
	assert(repof.getSize() == 4);
	list<Phone> rez = repof.getAll();
	assert(rez.size() == 4);
	repof.updateElem(Phone("bbb", "aaa", 1,v), b);
	assert(repof.findElem(b) == 0);
	assert(repof.getItemFromPos(0) == Phone("abc", "aaa", 1, v));
	assert(repof.getSize() == 4);

}
void Tests::testRepoFileCSV() {
	RepositoryFileCSV<Serie> repof("Tests.csv");
	vector<string> v;
	string c;
	c = "orange";
	v.push_back(c);
	c = "cosmote";
	v.push_back(c);
	assert(repof.getSize() == 4);
	Serie a("aaa", "bbb", 1);
	repof.addElem(a);
	assert(repof.getSize() == 5);
	assert(repof.findElem(a) == 4);
	Serie b("abc", "aaa", 1);
	assert(repof.findElem(b) == -1);
	repof.deleteElem(a);
	assert(repof.getSize() == 4);
	list<Serie> rez = repof.getAll();
	assert(rez.size() == 4);
	repof.updateElem(Serie("bbb", "aaa", 1), b);
	assert(repof.findElem(b) == 0);
	assert(repof.getItemFromPos(0) == Serie("abc", "aaa", 1));
	assert(repof.getSize() == 4);
}
void Tests::testRepoFileSerie() {
	//RepositoryFile<Serie*> repof("Tests.txt", ' ');
	//vector<string> v;
	//string c;
	//c = "orange";
	//v.push_back(c);
	//c = "cosmote";
	//v.push_back(c);
	//assert(repof.getSize() == 4);
	//Phone* p = new Phone("aaa", "bbb", 1, v);
	//repof.addElem(p);
	//assert(repof.getSize() == 5);
	//repof.saveToFile();
	//repof.loadFromFile("Tests.txt", ' ');
	//assert(repof.findElem(p) == 4);
	//Phone* p1 = new Phone("abc", "aaa", 1, v);
	//assert(repof.findElem(p1) == -1);
	//repof.saveToFile();
	//repof.loadFromFile("Tests.txt", ' ');
	//repof.deleteElem(p);
	//assert(repof.getSize() == 4);
	//repof.saveToFile();
	//repof.loadFromFile("Tests.txt", ' ');
	//list<Serie*> rez = repof.getAll();
	//assert(rez.size() == 4);
	//repof.saveToFile();
	//repof.loadFromFile("Tests.txt", ' ');
	//Phone* p2 = new Phone("bbb", "aaa", 1, v);
	//repof.updateElem(p2, p1);
	//assert(repof.findElem(p1) == 0);
	//repof.saveToFile();
	//repof.loadFromFile("Tests.txt", ' ');
	//assert(repof.getItemFromPos(0) == p1);
	//repof.saveToFile();
	//repof.loadFromFile("Tests.txt", ' ');
	//assert(repof.getSize() == 4);
	RepositoryFile<Serie> repof("Tests.txt", ' ');
	vector<string> v;
	string c;
	c = "orange";
	v.push_back(c);
	c = "cosmote";
	v.push_back(c);
	cout << "aici";
	assert(repof.getSize() == 4);
	Phone p = Phone("aaa", "bbb", 1, v);
	repof.addElem(p);
	assert(repof.getSize() == 5);
	repof.saveToFile();
	repof.loadFromFile("Tests.txt", ' ');
	assert(repof.findElem(p) == 4);
	Phone p1 = Phone("abc", "aaa", 1, v);
	assert(repof.findElem(p1) == -1);
	repof.saveToFile();
	repof.loadFromFile("Tests.txt", ' ');
	repof.deleteElem(p);
	assert(repof.getSize() == 4);
	repof.saveToFile();
	repof.loadFromFile("Tests.txt", ' ');
	list<Serie> rez = repof.getAll();
	assert(rez.size() == 4);
	repof.saveToFile();
	repof.loadFromFile("Tests.txt", ' ');
	Phone p2 =Phone("bbb", "aaa", 1, v);
	repof.updateElem(p2, p1);
	assert(repof.findElem(p1) == 0);
	repof.saveToFile();
	repof.loadFromFile("Tests.txt", ' ');
	assert(repof.getItemFromPos(0) == p1);
	repof.saveToFile();
	repof.loadFromFile("Tests.txt", ' ');
	assert(repof.getSize() == 4);

}
Tests::~Tests() {
}
void Tests::testService() {
	RepositoryFile<Serie> repof("Tests.txt", ' ');
	RepositoryFile<User> repo("Users.txt",' ');
	Service serv(repof, repo);
	User u1("ana", "1234");
	User u2("maria", "0000");
	User u3("cristina", "1414");
	repo.addElem(u1);
	assert(serv.login("cristina", "1414") == 0);
	assert(serv.login("ana", "1234") == 1);
	assert(serv.login("maria", "1234") == 0);
	cout<<repo.getSize();
}
	//Phone e1("aaa", "MS 74 SSC", "free");
	//Phone e2("bbb", "MS 75 SSC", "occupied");
	//Phone e3("ccc", "MS 76 SSC", "free");
	//Phone e4("ddd", "MS 77 SSC", "free");
	//Phone e0("eee", "MS 77 SSA", "free");
	//Phone e01("bbb", "aaa", "free");
	//serv.addEntity(e1);
	//serv.addEntity(e2);
	//serv.addEntity(e3);
	//serv.addEntity(e4);
	//serv.addEntity(e0);
	//assert(serv.getSize() == 5);
	//assert(serv.getItemFromPos(0) == e1);
	//assert(serv.findElem(e2) == 1);
	//int n = serv.delEntity(e0);
	//assert(serv.findElem(e0) == -1);
	//serv.updateEntity(e1, "aha", "aaa", "free");
	//assert(strcmp(serv.getItemFromPos(0).getUnits(), "free") == 0);
