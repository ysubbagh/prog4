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
    Comedy(string info);

    virtual bool setData(string info);

private:


};

#endif