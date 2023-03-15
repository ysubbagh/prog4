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
    return 7 % (num / 7);
}

Customer* HashTable:: getCust(int num){
    HashNode* person = htable[findBucket(num)];
    while(person -> data != nullptr && person -> next != nullptr){
        if(person -> data -> id == num) return person -> data;
        person = person -> next;
    }
    
    return nullptr; //basecase
}

void HashTable:: printTable(){
    for(int i = 0; i < size; i++){
        HashNode* copy = htable[i];
        while(copy != nullptr){
            cout << htable[i] -> data -> getName() << "     "; 
            copy = copy -> next;
        }
        cout << endl;
    }
}