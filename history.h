#ifndef HISTORY_H
#define HISTORY_H

#include <iostream>
#include <vector> 
#include "transaction.h"


using namespace std;
/*
    borrow an item
*/

class History : public Transaction{

public:
    //constructor
    History();

    virtual bool doTrans(string info);

private:


};

#endif