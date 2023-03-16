#include "return.h"

Return:: Return(){

}

bool Return:: doTrans(string info){
    
    return true; //basecase
}

/*
bool Return:: doTrans(string info){
    vector<string> data = parse(info);
    if(!checkFormat(data)) return false;
    DVD* movieToCheckOut = findMovie(data[2][0], data[3]);
    if(movieToCheckOut == nullptr) return false;
    Customer* shopper = custTable.getCust(stoi(data[0]));
    movieToCheckOut -> stock += 1;
    shopper -> addTrans("Returned " + movieToCheckOut -> name);
    return true;//basecase
}
*/