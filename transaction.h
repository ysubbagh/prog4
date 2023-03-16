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

/* 
    static bool compareTitles(const DVD *a, const DVD *b);

    //help sort teh drama
    static bool CompareDirectors(const DVD *a, const DVD *b);

    //add an error to the list
    void addError(string info);

    //make sure the info passed is formatted correctly / has the correct data types
    bool checkFormat(vector<string> info);

    //parse the data into a vector for easier access
    vector<string> parse(string info);

    //find the dvd or return null
    DVD* findMovie(char type, string info);
*/

};

#endif