#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <vector> 
#include "transaction.h"
#include "biz.h"


using namespace std;
/*
    borrow an item
*/

class Inventory : public Transaction{

public:
    //constructor
    Inventory();

    bool doTrans(string info);

private:


};

#endif