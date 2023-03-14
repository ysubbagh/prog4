#include "hashTable.h"

//constructors
HashTable:: HashTable(){
    size = 10; //base case
    buckets = new Item*[size];
}
HashTable:: HashTable(int size){
    this -> size = size;
    buckets = new Item*[size];
}

//destructor
HashTable:: ~HashTable(){
    Item *temp;
    for(int i = 0; i < size; i++){
        while(buckets[i] != nullptr){
            temp = buckets[i];
            buckets[i] = buckets[i] -> next;
            delete temp;
        }
    }
    delete temp;
    delete[] buckets;
}

//add an item to the table
bool HashTable:: addItem(Customer value){
    return false; // base case
}

int HashTable:: findBucket(Customer value){
    int x = 0;
    
    return x;
}