#include <iostream>
#include <vector> 
#include <cmath>
#include "customer.h" 
#include "biz.fwd.h"
#include "transaction.fwd.h"
#include "hashtable.fwd.h"
#include "dvd.fwd.h"

using namespace std;

/*
    Hashtable to store the custoners
*/

class HashTable{

    friend class Biz;

public:

    //constructor
    HashTable();
    HashTable(int size);

    //destructor
    ~HashTable();

    //add an item to the table
    bool addItem(Customer *value);

    //return the custoemr given their id
    Customer* getCust(int num);

    //clear the memory allocated to the table, helper function for destrucor in Biz
    void clearTable();


private:
    //items in the table
    struct HashNode{
        int key;
        Customer* data;
        HashNode* next;
        HashNode(int key, Customer* value){
            this -> key = key;
            this -> data = value;
            this -> next = nullptr;
        }
    };

    //the hashtable
    HashNode **htable;

    //size of table
    int size;

    //helper functions//
    //find the correct bucket given the algorthim of the hash
    int findBucket(int num);

    //help check the table
    void printTable();

};