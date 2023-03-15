#ifndef BIZ_H
#define BIZ_H

#include <iostream>
#include <vector> 
#include "customer.h" 
#include "transaction.h" 
#include "dvd.h" 
#include "comedy.h" 
#include "classic.h" 
#include "drama.h" 
#include "hashTable.h" 


using namespace std;

/*
    business class to store the movies and customer data and initate transactions
*/

class Biz{

public:
    //constructor
    Biz();

    //destructor
    ~Biz();

    //build a movie profile
    bool buildMovie(string info);

    //build a customer profile
    bool buildCust(string info);

    //process a transaction
    bool transaction(string info);

private:
    //for the bs tree for movie ordering
    struct NodeData {
        DVD data; 
    };
    struct Node{
        NodeData *data;
        Node* left;
        Node* right;
    };

    //movie storage0
    Node *movieRoot;

    //customer storage
    HashTable custTable;

    //helper functions//
    bool insertMovie(DVD movie);

};

#endif