#include "Service.h"
#include "User.h"

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
	User usr(u, p);
	this->activeUser = usr;
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

//void Service::loadFromFile(string f, char delim) {
//	repo.loadFromFile(f, delim);
//}

list<Serie> Service::getAllSeries()
{
	return repo.getAll();
}

int Service::getSize() {
	return repo.getSize();
}

Serie Service::getItemFromPos(int i) {
	return repo.getItemFromPos(i);
}

Service::~Service()
{
}
