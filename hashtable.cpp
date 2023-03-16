#include "hashTable.h"

//constructors
HashTable:: HashTable(){
    size = 10; //base case
    htable = new HashNode*[size];
}
HashTable:: HashTable(int size){
    this -> size = size;
    htable = new HashNode*[size];
}

//destructor
HashTable:: ~HashTable(){
    for(int i = 0; i < size; i++){
        HashNode* entry = htable[i];
        while(entry != nullptr){
            HashNode* prev = entry;
            entry = entry -> next;
            delete prev;
        }
    }
    delete[] htable;
}

//add an item to the table
bool HashTable:: addItem(Customer *value){
    int key  = findBucket(value -> id);
    HashNode* prev = nullptr;
        HashNode* entry = htable[key];
        while (entry != nullptr){
            prev = entry;
            entry = entry->next;
        }
        if (entry == nullptr){
            entry = new HashNode(key, value);
            if (prev == nullptr){
                htable[key] = entry;
            }else{
                prev -> next = entry;
            }
        }else{
            entry -> data = value;
        }
    return true; // base case
}

//algo to hash
int HashTable:: findBucket(int num){
    double A = 0.6180339887; // the golden ratio
    double fracPart = modf(num * A, &A); // get the fractional part of key*A
    int hashValue = (int)(size * fracPart);
    return hashValue;
}

//return the customer pointer given their id number
Customer* HashTable:: getCust(int num){
    HashNode* person = htable[findBucket(num)];
    while(person != nullptr){
        if(person -> data -> id == num) return person -> data;
        person = person -> next;
    }
    return nullptr; //basecase
}

//help check that table is filled in correctly 
void HashTable:: printTable(){
    for(int i = 0; i < size; i++){
        HashNode* copy = htable[i];
        while(copy != nullptr){
            cout << copy -> data -> getName() << "     "; 
            copy = copy -> next;
        }
        cout << endl;
    }
}

//clean out the memory of the table, help Biz destructor
void HashTable:: clearTable(){
    for(int i = 0; i < size; i++){
        HashNode* entry = htable[i];
        while(entry != nullptr){
            HashNode* prev = entry;
            entry = entry -> next;
            delete prev;
        }
    }
}