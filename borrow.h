#ifndef BORROW_H
#define BORROW_H

#include <iostream>
#include <vector> 
#include "transaction.h"


using namespace std;
/*
    borrow an item
*/

class Borrow : public Transaction{

public:
    //constructor
    Borrow();

    virtual bool doTrans(string info);

private:


};

#endif