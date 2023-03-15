#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>
#include <vector> 
#include "biz.fwd.h"
#include "transaction.fwd.h"
#include "hashtable.fwd.h"
#include "dvd.fwd.h"

using namespace std;
/*
    transactions starts a transaction type
*/

class HashTable;

class Transaction{

    friend class Biz;
    friend class History;
    friend class Inventory;
    friend class Return;
    friend class Borrow;

public:
    //constructor
    Transaction();

    //complete a transaction
    virtual bool doTrans(string info);

private:

};

#endif