#ifndef RETURN_H
#define RETURN_H

#include <iostream>
#include <vector>  

using namespace std;
/*
    return an item
*/

class Return{

    friend class Transaction;

public:
    //constructor
    Return();

    bool returnItem();

private:


};

#endif