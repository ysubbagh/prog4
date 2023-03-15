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

    friend class Transaction;

public:
    //constructors
    Classic();
    Classic(string info);

    virtual bool setData(string info);

private:
    string star;
    int numDate;

};

#endif