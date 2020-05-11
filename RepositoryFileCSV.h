#pragma once
#include <list>
#include <iostream>
#include<fstream>
#include "Phone.h"
#include "Repository.h"
using namespace std;


template<class T>
class RepositoryFileCSV :public RepositoryTemplate<T>
{
private:
	const char* fileName;
	Serializer<T>* s;
public:
	RepositoryFileCSV();
	RepositoryFileCSV(const char*,Serializer<T>* sr);
	int addElem(T);
	int deleteElem(T);
	void updateElem(T, T);
	void loadFromFile(const char*);
	void saveToFile();
	~RepositoryFileCSV();
};

template<class T>
RepositoryFileCSV<T>::RepositoryFileCSV() :RepositoryTemplate<T>()
{
	fileName = "";
}
template<class T>
RepositoryFileCSV<T>::RepositoryFileCSV(const char* fileName, Serializer<T>* sr)
{
	this->fileName = fileName;
	s = sr;
	loadFromFile(fileName);
}

template<class T>
void RepositoryFileCSV<T>::loadFromFile(const char* fileName)
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
			
				RepositoryTemplate<T>::addElem(s->fromString(line, ','));
			}
			inf.close();
		}
	}
	catch (int e) {
		std::cout << "Failed loading from file.\n";
	};
}

template<class T>
void RepositoryFileCSV<T>::saveToFile()
{
	if (this->fileName == NULL)
		return;
	std::ofstream out(this->fileName);
	for (T t : this->getAll())
	{
		out << t->toStringDelimiter(',') << '\n';
	}
	out.close();
}

template<class T>
RepositoryFileCSV<T>::~RepositoryFileCSV()
{
}

template<class T>
int RepositoryFileCSV<T>::addElem(T e) {
	int r = RepositoryTemplate<T>::addElem(e);
	if (r != -1) {
		saveToFile();
		return 0;
	}
	return -1;
}

template<class T>
int RepositoryFileCSV<T>::deleteElem(T e) {
	int r = RepositoryTemplate<T>::deleteElem(e);
	saveToFile();
	if (r != 0) {
		return 0;
	}
	else
		return -1;
}
template<class T>
void RepositoryFileCSV<T>::updateElem(T e, T n)
{
	RepositoryTemplate<T>::updateElem(e, n);
	saveToFile();
}