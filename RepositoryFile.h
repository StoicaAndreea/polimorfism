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
	char delim;
public:
	RepositoryFile();
	RepositoryFile(const char*, const char);
	int addElem( T&);
	int deleteElem(T&);
	void updateElem(T,T&);
	void loadFromFile(const char*, const char);
	void saveToFile();
	~RepositoryFile();
};

template<class T>
RepositoryFile<T>::RepositoryFile() :RepositoryTemplate<T>()
{
	fileName = "";
	delim = ' ';
}
template<class T>
RepositoryFile<T>::RepositoryFile(const char* fileName, const char delim)
{
	this->fileName = fileName;
	loadFromFile(fileName, delim);
}

template<class T>
void RepositoryFile<T>::loadFromFile(const char* fileName, const char delim)
{
	if (fileName == NULL)
		return;
	try {
		this->fileName = fileName;
		this->delim = delim;
		std::ifstream inf(this->fileName);
		RepositoryTemplate<T>::clearElem();
		string line;
		if (inf.is_open()) {
			while (getline(inf, line))
			{
				T ob;
				ob.fromString(line, delim);
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
void RepositoryFile<T>::saveToFile()
{
	if (this->fileName == NULL)
		return;
	std::ofstream out(this->fileName);
	for (T t : this->getAll())
	{
		out << t.toStringDelimiter(this->delim)<< '\n';
	}
	out.close();
}

template<class T>
RepositoryFile<T>::~RepositoryFile()
{

}

template<class T>
int RepositoryFile<T>::addElem(T& e) {
	int r = RepositoryTemplate<T>::addElem(e);
	if (r != -1) {
		saveToFile();
		return 0;
	}
	return -1;
}

template<class T>
int RepositoryFile<T>::deleteElem(T& e) {
	int r = RepositoryTemplate<T>::deleteElem(e);
	if (r != 0) {
		saveToFile();
		return 0;
	}
	else
		return -1;
}
template<class T>
void RepositoryFile<T>::updateElem(T e,T& n)
{
	RepositoryTemplate<T>::updateElem(e, n);
	saveToFile();
}