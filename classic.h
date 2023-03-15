#ifndef CLASSIC_H
#define CLASSIC_H

#include <iostream>
#include <vector> 
#include "dvd.h" 


using namespace std;

/*
    classic movies store name of movie, release date, stock amount, lead role / star, and director
*/

class Classic : public DVD{

public:
    //constructors
    Classic();
    Classic(string info);
    Classic(DVD copy, string info);

private:
    int stock = 0; //set stock to 0 to start
    string name;
    string date;
    string direct;
    string star;

};

#endif