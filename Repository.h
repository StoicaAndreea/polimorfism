#pragma once
#include"Phone.h"
#include<iterator>
#include <list>
#include <algorithm>
#include <iostream>
using namespace std;

template <class T>class RepositoryTemplate {
protected:
	list<T> elem;
public:
	RepositoryTemplate<T>() {}
	virtual int addElem(const T&);
	virtual int deleteElem(const T&);
	int findElem(const T&);
	int getSize();
	virtual void updateElem(const T& s, const T nou);
	list<T> getAll();
	T getItemFromPos(int);
	void clearElem();
	~RepositoryTemplate();
};





template<class T>
int RepositoryTemplate<T>::addElem(const T& e)
{
	typename list<T>::iterator it;
	it = find(elem.begin(), elem.end(), e);
	if (it == elem.end())
	{
		elem.push_back(e);
		return 0;
	}
	return -1;
}

template<class T>
int RepositoryTemplate<T>::deleteElem(const T& e)
{
	typename list<T>::iterator it;
	it = find(elem.begin(), elem.end(), e);
	if (it != elem.end())
	{
		elem.erase(it);
		return 0;
	}
	return -1;
}

template<class T>
int RepositoryTemplate<T>::findElem(const T& e)
{
	typename list<T>::iterator it;
	int i = 0;
	for (it = elem.begin(); it != elem.end(); ++it)
	{
		if (*it == e)
		{
			return i;
		}
		i++;
	}
	return -1;
}

template<class T>
int RepositoryTemplate<T>::getSize()
{
	return elem.size();
	return 0;
}

template<class T>
void RepositoryTemplate<T>::updateElem(const T& vechi, const T nou)
{
	replace(elem.begin(), elem.end(), vechi, nou);

}

template<class T>
list<T> RepositoryTemplate<T>::getAll()
{
	return elem;
	return list<T>();
}

template<class T>
T RepositoryTemplate<T>::getItemFromPos(int i) {
	typename list<T>::iterator it;
	int k = 0;
	for (it = elem.begin(); it != elem.end(); it++)
	{
		if (k == i)
			return *it;
		k++;

	}
}
template<class T> void RepositoryTemplate<T>::clearElem() {
	elem.clear();
}
template <class T> RepositoryTemplate<T>::~RepositoryTemplate()
{
}