#include "customer.h"

Customer:: Customer(string id, string f, string l){
    this -> id = stoi(id);
    fName = f;
    lName = l;
}