#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <vector> 


using namespace std;

/*
    customer class, have ids, and history
*/

class Customer{

    friend class Biz;
    friend class HashTable;

public:
    //constructor
    Customer();

    //get the name of the customer
    string getName();

    //get the id of the cusotmer 
    string getId();

    //retutn the string of the transaction history of customer
    string getHistory();

    //add a transaction under customer profilr and add to their history
    bool addTrans();

private:
    string fName;
    string lName;
    int id;

    string trans;

};

#endif