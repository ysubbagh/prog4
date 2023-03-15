#include <iostream>
#include <vector> 
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


private:
    //items in the table
    struct Item{
        Customer* data;
        Item *next;
    };

    Item **buckets;

    int size;

    //helper functions//
    //find the correct bucket given the algorthim of the hash
    int findBucket(Customer *value);

};