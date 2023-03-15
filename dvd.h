#ifndef DVD_H
#define DVD_H

#include <iostream>
#include <vector> 
#include "comedy.h"
#include "classic.h"
#include "drama.h"

using namespace std;

/*
    head movies store name of movie, release date, stock amount, and director
    but mainly used to be overloaded by other classes, 
*/

class DVD{

    //print output
    friend ostream &operator<<(ostream &out, const DVD &movie);
    friend class NodeData;
    friend class Transaction;
    friend class Biz;

public:
    //constructors
    DVD();
    DVD(string info);

    //set the data of the movie
    bool setData(string info);

    int getStock();

private:
    char genre;
    int stock = 0; //set stock to 0 to start
    string name;
    string date;
    string direct;

    //helper functions//


};

#endif