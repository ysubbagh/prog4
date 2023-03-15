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
    Customer(string id, string f, string l);

    //get the name of the customer
    string getName();

    //get the id of the cusotmer 
    int getId();

    string getTrans();

private:
    string fName;
    string lName;
    int id;

    string trans;

    bool addTrans(string info);

};

#endif