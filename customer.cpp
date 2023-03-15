#include "customer.h"

Customer:: Customer(string id, string f, string l){
    this -> id = stoi(id);
    fName = f;
    lName = l;
}

//get name of the customer
string Customer:: getName(){
    return fName + " " + lName;
}

//get the id of the customer 
string Customer:: getId(){
    return id + "";
}


bool Customer:: addTrans(string info){
    trans = trans + "\n" + info;
    return true; //base case
}