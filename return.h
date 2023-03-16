#ifndef RETURN_H
#define RETURN_H

#include <iostream>
#include <vector>  
#include "transaction.h"

using namespace std;
/*
    return an item
*/

class Return : public Transaction{

public:
    //constructor
    Return();

    bool doTrans(string info);

private:


};

#endif