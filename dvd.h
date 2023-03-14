#ifndef DVD_H
#define DVD_H

#include <iostream>
#include <vector> 


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
    DVD(string name);
    DVD(string name, int stock);
    DVD(string name, char type);
    DVD(string name, int stock, char type);

    //set the data of the movie
    bool setData(string info);

    int getStock();

private:
    char genre;
    int stock = 0; //set stock to 0 to start
    string name;
    string date;
    string direct;

};

#endif