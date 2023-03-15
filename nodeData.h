#ifndef NODEDATA_H
#define NODEDATA_H

#include <iostream>
#include <vector> 
#include "dvd.h"

using namespace std;
/*
    transactions starts a transaction type
*/

class NodeData{

    friend class Biz;

public:
    //constructor
    NodeData();
    NodeData(DVD *movie);

private:

    NodeData* next;
    DVD* data;

};

#endif