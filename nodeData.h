#include <iostream>
#include <vector> 
#include <biz.h> 

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