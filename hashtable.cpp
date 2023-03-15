#include "hashTable.h"
#include "biz.cpp"

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
            delete temp -> data;
            delete temp;
        }
    }
    delete temp;
    delete[] buckets;
}

//add an item to the table
bool HashTable:: addItem(Customer *value){
    int buck = findBucket(value);
    Item *head = buckets[buck]; 
    Item *person;
    person -> data = value;
    person -> next = nullptr; 
    while(head != nullptr){
        head = head -> next;
    }
    head = person;
    return false; // base case
}

//algo to hash
int HashTable:: findBucket(Customer *value){
    return 7 % (value -> id / 7) + 3;
}