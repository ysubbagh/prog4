#ifndef NODEDATA_H
#define NODEDATA_H

#include <iostream>
#include <vector> 
#include "dvd.h"

using namespace std;

/*
    Node data for the binary search tree, stores movie info
*/

class NodeData{

    friend class Biz;

public:
    //constructor
    NodeData();
    NodeData(DVD copy);


private:

    DVD data;

};

#endif