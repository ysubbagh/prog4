#include <iostream>
#include <vector> 
#include "nodeData.h" 
#include "customer.h" 
#include "transaction.h" 
#include "dvd.h" 
#include "comedy.h" 
#include "classic.h" 
#include "drama.h" 

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
    bool addItem(Customer value);

    int findBucket(Customer value);


private:
    //items in the table
    struct Item{
        Customer* value;
        Item *next;
    };

    Item **buckets;

    int size;

};