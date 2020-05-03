#pragma once
#include <list>
#include <iostream>
#include<fstream>
#include "Phone.h"
#include "Repository.h"
using namespace std;


template<class T>
class RepositoryFileHTML :public RepositoryTemplate<T>
{
private:
	const char* fileName;
public:
	RepositoryFileHTML();
	RepositoryFileHTML(const char*);
	int addElem(T&);
	int deleteElem(T&);
	void updateElem(T, T&);
	void loadFromFile(const char*);
	void saveToFile();
	~RepositoryFileHTML();
};

template<class T>
RepositoryFileHTML<T>::RepositoryFileHTML() :RepositoryTemplate<T>()
{
	fileName = "";
}
template<class T>
RepositoryFileHTML<T>::RepositoryFileHTML(const char* fileName)
{
	this->fileName = fileName;
	loadFromFile(fileName);
}

template<class T>
void RepositoryFileHTML<T>::loadFromFile(const char* fileName)
{
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
				T ob;
				ob.fromString(line, '/');
				RepositoryTemplate<T>::addElem(ob);
			}
			inf.close();
		}
	}
	catch (int e) {
		std::cout << "Failed loading from file.\n";
	};
}

template<class T>
void RepositoryFileHTML<T>::saveToFile()
{
	if (this->fileName == NULL)
		return;
	std::ofstream out(this->fileName);
	for (T t : this->getAll())
	{
		out << t.toStringDelimiter('/') << '\n';
	}
	out.close();
}

template<class T>
RepositoryFileHTML<T>::~RepositoryFileHTML()
{

}

template<class T>
int RepositoryFileHTML<T>::addElem(T& e) {
	int r = RepositoryTemplate<T>::addElem(e);
	if (r != -1) {
		saveToFile();
		return 0;
	}
	return -1;
}

template<class T>
int RepositoryFileHTML<T>::deleteElem(T& e) {
	int r = RepositoryTemplate<T>::deleteElem(e);
	if (r != 0) {
		saveToFile();
		return 0;
	}
	else
		return -1;
}
template<class T>
void RepositoryFileHTML<T>::updateElem(T e, T& n)
{
	RepositoryTemplate<T>::updateElem(e, n);
	saveToFile();
}
