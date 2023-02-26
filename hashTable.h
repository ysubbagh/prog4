#include <iostream>
#include <vector> 
#include <nodeData.h> 
#include <customer.h> 
#include <transaction.h> 
#include <DVD.h> 
#include <comedy.h> 
#include <classic.h> 
#include <drama.h> 

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
    addItem(int key, Customer value);


private:
    //items in the table
    struct Item{
        int* key;
        Customer* value;
    }

    Item* root;
    int size;
    int count;

};