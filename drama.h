#ifndef DRAMA_H
#define DRAMA_H

#include <iostream>
#include <vector> 
#include "dvd.h" 


using namespace std;

/*
    drama movies store name of movie, release date, stock amount, and director
*/
class Drama : public DVD{

public:
    //constructors
    Drama();
    Drama(DVD copy);
    Drama(string name, int stock, string date, string direct);


private:
    int stock = 0; //set stock to 0 to start
    string name;
    string date;
    string direct;

};

#endif