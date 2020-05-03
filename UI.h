#pragma once
#include "Service.h"
class UI {
private:
	Service s;
public:
	UI(Service& serv) : s(serv) {};
	int logIn();
	void logOut();
	//void addProj();
	//void findProj();
	void showUI();
	//void delProj();
	void showAll();
	//void undoProj();
	//void updateProj();
	~UI();
};