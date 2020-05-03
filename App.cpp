// Lab 8- polimorfism.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include"Tests.h"
#include "Phone.h"
#include "Repository.h"
#include"RepositoryFile.h"
#include"Service.h"
#include"UI.h"
using namespace std;
#include <iostream>
#include "RepositoryFileCSV.h"
#include "RepositoryFileHTML.h"

int main()
{
    cout << "start"<<endl;
    Tests test;
    test.testDomainPhone();
    test.testDomainDrone();
    //test.testRepoTemplate();
   //test.testRepoFilePhone();
    test.testRepoFileCSV();
   // test.testRepoFileSerie();
    //test.testService();
    cout << "succes" << endl;
    //RepositoryFile<Serie> repof("Tests.txt",' ');
    //RepositoryFileCSV<Serie>repof("Tests.csv");
    RepositoryFileHTML<Serie>repof("Tests.html");
    RepositoryFile<User> repo("Users.txt", ' ');
    Service serv(repof, repo);
    UI ui(serv);
    ui.showUI();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
