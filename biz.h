#ifndef BIZ_H
#define BIZ_H

#include <iostream>
#include <vector> 
#include "biz.fwd.h"
#include "transaction.fwd.h"
#include "hashtable.fwd.h"
#include "dvd.fwd.h"
#include "hashTable.h" 
#include "customer.h" 
#include "transaction.h" 
#include "dvd.h" 
#include "comedy.h" 
#include "classic.h" 
#include "drama.h" 
#include "history.h"
#include "inventory.h"
#include "borrow.h"
#include "return.h"

using namespace std;

/*
    business class to store the movies and customer data and initate transactions
*/

class Biz{

    friend class Transaction;

public:
    //constructor
    Biz();

    //destructor
    ~Biz();

    //build a movie profile
    bool buildMovie(string info);

    //build a customer profile
    bool buildCust(string info);

    //process a transaction
    bool transaction(string info);

private:
    //movie storage0
    vector<vector<DVD*>> movieStock;

    //customer storage
    HashTable custTable;

    //helper functions//
    bool insertMovie(DVD *movie);

    //movie factory pattern
    DVD* createMovie(char type, string info);

    //transaction factory pattern
    Transaction* createTrans(char type, string info);

};

#endif