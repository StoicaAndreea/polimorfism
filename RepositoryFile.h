#pragma once
#include <list>
#include <iostream>
#include<fstream>
#include "Phone.h"
#include "Repository.h"
using namespace std;


template<class T>
class RepositoryFile :public RepositoryTemplate<T>
{
private:
	const char* fileName;
	const char* outputFile;
public:
	RepositoryFile();
	RepositoryFile(const char*, const char*);
	int addElem(const T&);
	int deleteElem(const T&);
	void updateElem(const T&, const T);
	void loadFromFile(const char*);
	void saveToFile();
	~RepositoryFile();
};

template<class T>
RepositoryFile<T>::RepositoryFile() :RepositoryTemplate<T>()
{
	fileName = "";
	outputFile = "";
}
template<class T>
RepositoryFile<T>::RepositoryFile(const char* fileName, const char* outputFile)
{
	this->fileName = fileName;
	this->outputFile=outputFile;
	loadFromFile(fileName);
	//RepositoryTemplate::clearElem();
	//fis = fileName;
	//ifstream f(fileName);
	//string linie;
	//char* name = new char[10];
	//char* numar = new char[10];
	//char* status = new char[10];
	//while (!f.eof()) {
	//	f >> name >> numar >> status;
	//	if (name != "") {
	//		Entity e(name, numar, status);
	//		//elem.push_back(e);
	//		RepositoryTemplate::addElem(e);

	//	}
	//}
	//delete[] name;
	//delete[] numar;
	//delete[] status;
	//f.close();
}

template<class T>
void RepositoryFile<T>::loadFromFile(const char* fileName)
{
	////elem.clear();
	//RepositoryTemplate::clearElem();
	//fis = fileName;
	//ifstream f(fileName);
	//char* name = new char[10];
	//char* numar = new char[10];
	//char* status = new char[10];
	//while (!f.eof())
	//{
	//	f >> name >> numar >> status;
	//	if (strcmp(name, "") != 0)
	//	{
	//		T t;
	//		//Entity e(name, numar, status);
	//		//elem.push_back(e);
	//		RepositoryTemplate::addElem(t);
	//	}
	//}
	//delete[] name;
	//delete[] numar;
	//delete[] status;
	//f.close();
	if (fileName == NULL)
		return;
	try {
		this->fileName = fileName;
		std::ifstream inf(this->fileName);
		RepositoryTemplate<T>::clearElem();
		string line;
		if (inf.is_open()) {
			while (getline(inf, line))
			{
				//T t;
				//std::string inStr;
				//t.fromString(inStr);
				this->addElem(T(line));
				//cout << line << endl;
			}
			inf.close();
		}
	}
	catch (int e) {
		std::cout << "Failed loading from file.\n";
	};
}

template<class T>
void RepositoryFile<T>::saveToFile()
{
	/*ofstream f(fis);
	typename list<T>::iterator it;
	list<T> elem = RepositoryTemplate::getAll();
	for (it = elem.begin(); it != elem.end(); ++it)
	{
		f << *it;
	}
	f.close();*/
	if (this->fileName == NULL)
		return;
	std::ofstream out(this->fileName);
	//out << this->dim() << '\n';
	for (T t : this->getAll())
	{
		out << t;// << '\n';
	}
	out.close();

	if (this->outputFile == NULL)
		return;
	std::ofstream ou(this->outputFile);
	//out << this->dim() << '\n';
	for (T t : this->getAll())
	{
		ou << t;// << '\n';
	}
	ou.close();
}

template<class T>
RepositoryFile<T>::~RepositoryFile()
{

}

template<class T>
int RepositoryFile<T>::addElem(const T& e) {
	int r = RepositoryTemplate<T>::addElem(e);
	if (r != -1) {
		saveToFile();
		return 0;
	}
	return -1;
}

template<class T>
int RepositoryFile<T>::deleteElem(const T& e) {
	int r = RepositoryTemplate<T>::deleteElem(e);
	if (r != 0) {
		saveToFile();
		return 0;
	}
	else
		return -1;
}
template<class T>
void RepositoryFile<T>::updateElem(const T& e, const T n)
{
	RepositoryTemplate<T>::updateElem(e, n);
	saveToFile();
}