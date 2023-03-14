#ifndef COMEDY_H
#define COMEDY_H

#include <iostream>
#include <vector> 
#include "dvd.h" 


using namespace std;

/*
    comedy movies store name of movie, release date, stock amount, and director
*/

class Comedy : public DVD{

public:
    //constructors
    Comedy();
    Comedy(string name, int stock, string date, string director);

private:
    int stock = 0; //set stock to 0 to start
    string name;
    string date;
    string direct;

};

#endif