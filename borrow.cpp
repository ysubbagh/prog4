#include "borrow.h"

//constructor
Borrow:: Borrow(){

}

bool Borrow:: doTrans(string info){

    return true; //basecase
}

/*
bool Borrow:: doBorrow(string info){
    vector<string> data = parse(info);
    if(!checkFormat(data)) return false;
    DVD* movieToCheckOut = findMovie(data[2][0], data[3]);
    if(movieToCheckOut == nullptr) return false;
    if(movieToCheckOut -> stock <= 0){
        addError("ERROR:  Borrow Transaction Failed -- Not enough in stock");
        return false;
    }
    movieToCheckOut -> stock -= 1;
    Customer* shopper = custTable.getCust(stoi(data[0]));
    shopper -> addTrans("Borrowed " + movieToCheckOut -> name);
    return true;//basecase
}
*/