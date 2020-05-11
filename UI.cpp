#include "UI.h"
#include <iostream>
#include<string.h>
using namespace std;

void UI::addElem() {
	cout << "what yould you like to add? :"<<endl;
	cout << "	a. Phone" << endl;
	cout << "	b.Drone" << endl;
	try {
	string ras = "";
	cin >> ras;
	Serie* ser;
	if (ras == "a") {
		try {
			Phone p;
			cin >> p;
			ser = p.clone();
			s.addElem(ser);
			delete[]ser;
		}
		catch (PhoneException e)
		{
			for (int i = 0; i < e.getErrors().size(); i++)
				cout << e.getErrors()[i];
		}
	}
	else {
		try {
			Drone p;
			cin >> p;
			ser = p.clone();
			s.addElem(ser);
			delete[]ser;
		}
		catch (SerieException e) {
			for (int i = 0; i < e.getErrors().size(); i++)
				cout << e.getErrors()[i];
		}
	}
	}
	catch (exception e) { cout << "exception occuredddd!" << "->"; cout << e.what(); }
}



void UI::findElem() {
	string prod;
	cout << "give the producer: ";
	cin >> prod;
	list<Serie*> l = s.findProducer(prod);
	list <Serie*>::iterator it;
	for (it = l.begin(); it != l.end(); ++it) {
		cout << (*it)->toString() << endl;
	}

}

void UI::delElem() {
	cout << "what yould you like to delete? :" << endl;
	cout << "	a. Phone" << endl;
	cout << "	b.Drone" << endl;
	try {
		string ras = "";
		cin >> ras;
		Serie* ser;
		if (ras == "a") {
			Phone p;
			cin >> p;
			ser = p.clone();
		}
		else {
			Drone p;
			cin >> p;
			ser = p.clone();
		}
		s.deleteElem(ser);
		cout << "the seria has been successfully deleted" << endl;
		delete[]ser;
	}
	catch (exception e) { cout << "exception occuredddd!" << "->"; cout << e.what(); }
}


int UI::logIn() {
	cout << "Username: ";
	string user;
	cin >> user;
	cout << "Password: ";
	string pass;
	cin >> pass;
	return s.login(user, pass);
}

void UI::logOut() {
	s.logout();
}

void UI::showAll() {
	//list <Serie*>::iterator it;
	for (int i = 0; i < s.getSize(); i++)
	{
		cout << (*s.getItemFromPos(i)).toString() << endl;
	}
}

void UI::updateElem() {
	cout << "what yould you like to update? :" << endl;
	cout << "	a. Phone" << endl;
	cout << "	b.Drone" << endl;
	try {
		string ras = "";
		cin >> ras;
		Serie* ser;
		Serie* nser;
		if (ras == "a") {
			Phone p;
			Phone np;
			cin >> p;
			ser = p.clone();
			cout << "update with:" << endl;
			cin >> np;
			nser = np.clone();
		}
		else {
			Drone p,np;
			cin >> p;
			ser = p.clone();
			cout << "update with:" << endl;
			cin >> np;
			nser = np.clone();
		}
		s.updateElem(ser,nser);
		delete[]ser;
		delete[]nser;
	}
		catch (exception e) { cout << "exception occuredddd!" << "->"; cout << e.what(); }
}

void UI::showUI()
{
	bool gata = false;
	bool stop = false;
	while (!gata) {
		cout << "would you like to log on? " << endl;
		cout << "		a.yes" << endl;
		cout << "		b.no" << endl;
		char r;
		cin >> r;
		if (r == 'a') {
			if (logIn()) {
				/*cout << "what format would you like? " << endl;
				cout << "		a. csv" << endl;
				cout << "		b.html" << endl;
				cin>> r;
				if (r == 'a') { s.loadFromFile("Tests.csv",','); }
				else { s.loadFromFile("Tests.html", '/'); }*/

				while (s.logedIn() and !gata) {
					cout << endl;
					cout << "#####################~~ MENU ~~###################" << endl;
					cout << endl;
					cout << "OPTIONS: " << endl;
					cout << "	1. Add " << endl;
					cout << "	2. Search by producer " << endl;
					cout << "	3. Delete " << endl;
					cout << "	4. Update " << endl;
					cout << "	5. Show " << endl;
					cout << "	6. Log out" << endl;
					cout << "	0. EXIT!" << endl;
					cout << "option: (give the number):  ";
					int opt;
					cin >> opt;
					cout << endl;
					cout << endl;
					switch (opt) {
						case 1: {addElem(); break; }
						case 2: {findElem(); break; }
						case 3: {delElem(); break; }
						case 4: {updateElem(); break; }
					case 5: {showAll(); break; }
					case 6: {logOut(); cout << "you have been logged outtttt" << endl; break; }
					case 0: {gata = true; cout << "BYE BYE..." << endl; }
					}
				}
			} else{ cout << "incorrect username or password" << endl; }
		}
			else {
				if (r == 'b') gata = true;
			}
		}
	}

UI::~UI()
{

}
