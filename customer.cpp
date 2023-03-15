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

//retutn the string of the transaction history of customer
string Customer:: getHistory(){

}