#include "Service.h"
#include "User.h"
#include "SerieValidator.h"
#include "PhoneValidator.h"
#include <sstream>
//Service::Service()
//{
//}

//Service::Service(RepositoryTemplate<Serie> repo,RepositoryTemplate<User> repoUseri):this->repo(repo)
//{
//	this->repo = repo;
//	this->repoUser = repoUseri;
//	User u1("Ana", "123");
//	User u2("Ion", "1234");
//	repoUser.addElem(u1);
//	repoUser.addElem(u2);
//}

bool Service::login(string u, string p)
{
	User *usr= new User(u, p);
	this->activeUser = (*usr);
	return ((repoUser.findElem(usr) != -1) and (!this->activeUser.getUserName().empty()));
}

bool Service::logedIn() {
	return !this->activeUser.getUserName().empty();
}
void Service::logout(/*string name, string pass*/)
{
	this->activeUser.setUserName("");
	this->activeUser.setPassword("");
	//User u(name, pass);
	//repoUser.deleteElem(u);
}

list<Serie*> Service::getAllSeries()
{
	return repo.getAll();
}

list<Serie*> Service::findProducer(string prod) {
	list<Serie*>l;
	list<Serie*>all=repo.getAll();
	list <Serie*>::iterator it;
	int i = 0;
	string x;
	for (it = all.begin(); it != all.end(); ++it)
	{
		x = (*it)->getProducer();
		if (x==prod) 
		{ l.push_back(*it); }
	}
	return l;

}
int Service::getSize() {
	return repo.getSize();
}

Serie* Service::getItemFromPos(int i) {
	return (repo.getItemFromPos(i));
}
bool Service::isPositiveInteger(const std::string& s)
{
	return !s.empty() &&
		(std::count_if(s.begin(), s.end(), std::isdigit) == s.size());
}

void Service::addElem(Serie*& s) {
	vector<string> tokens;
	string line = s->toStringDelimiter('|');
	stringstream ss(line);
	string item;
	while (getline(ss, item, '|')) {
		tokens.push_back(item);
	}
	if (tokens.size() == 4) {
		if(isPositiveInteger(tokens[3])){
			int i = stoi(tokens[3]);
			Serie* d = new Drone(line, '|');
			sv.validate(d);
			repo.addElem(d);
			delete[]d;
		}
		else{
			Serie* d = new Phone(line, '|');
			Phone* p = new Phone(line, '|');
			pv.validate(p);
			repo.addElem(d);
			delete[]d;
			delete[]p;
		}
	}
}

void Service::deleteElem(Serie*& s) {
	if (repo.findElem(s) == -1) {
		throw exception("could not find item");
	}
	else {
		repo.deleteElem(s);
	}
}
void Service::updateElem(Serie* s, Serie*& ns) {
	if (repo.findElem(s) == -1) {
		throw exception("could not find item");
	}
	else {
		repo.updateElem(s,ns);
	}
}

Service::~Service()
{
}
