#ifndef BORROW_H
#define BORROW_H

#include <iostream>
#include <vector> 


using namespace std;
/*
    borrow an item
*/

class Borrow{

    friend class Transaction;

public:
    //constructor
    Borrow();

    void borrowItem();

private:


};

#endif