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
#include "nodeData.h" 

using namespace std;

/*
    business class to store the movies and customer data and initate transactions
*/

class Biz{

public:
    //constructor
    Biz();

    //build a movie profile
    bool buildMovie(string info);

    //build a customer profile
    bool buildCust(string info);

    //process a transaction
    bool transaction(string info);

private:
    //for the bs tree for movie ordering
    struct Node{
        NodeData* data;
        Node* left;
        Node* right;
    };

    //movies
    Node* root;

    //customers
    HashTable table;

};

#endif