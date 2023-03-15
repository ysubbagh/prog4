#ifndef DRAMA_H
#define DRAMA_H

#include <iostream>
#include <vector> 
#include "dvd.h" 


using namespace std;

/*
    drama movies store name of movie, release date, stock amount, and director. Much inherited from DVD class
*/

class Drama : public DVD{

public:
    //constructors
    Drama();
    Drama(string info);

    //set data to the movie
    virtual bool setData(string info);


private:

};

#endif