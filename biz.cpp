#include "biz.h"

//constructor
Biz:: Biz(){
    vector<DVD*> row;
    for(int i = 0; i < 2; i++){
        movieStock.push_back(row);
    }
}

//destructor
Biz:: ~Biz(){

}

//functions//
//load in new movie
bool Biz:: buildMovie(string info){
    DVD *movie = createMovie(info[0], info);
    if(movie == nullptr) {
        cout << "Improper movie genre entered" << endl;
        return false;
    }
    return true; // basecase
}

//insert the movie into the 
bool Biz:: insertMovie(DVD *movie){
    int index = 0;
    if(movie -> genre == 'D') index = 1;
    if(movie -> genre == 'C') index = 2;
    movieStock[index].push_back(movie);
    return true; // base case
}

//build a customer profile
bool Biz:: buildCust(string info){
    string num = info.substr(0, 4);
    info = info.substr(info.find(' ') + 1);
    string f = info.substr(0, info.find(' '));
    info = info.substr(info.find(' '));
    Customer *person = new Customer(num, f, info);
    custTable.addItem(person);
    return true; // basecase
}

//process a transaction
bool Biz:: transaction(string info){
    Transaction* doStuff = createTrans(info[0], info);
    return true; //base case
}

//factory pattern to choose the correct movie type
DVD* Biz:: createMovie(char type, string info){
    DVD *movie = nullptr;
    switch (type) {
        case 'C':{
            movie = new Classic();
            break;
        }
        case 'D':{
            movie = new Drama();
            break;
        }
        case 'F':{
            movie = new Comedy();
            break;
        }
        default:{
            cout << "Improper movie genre type entered" << endl;;
            return nullptr;
        }
    }
    movie -> setData(info);
    return movie;
}

// factory design for the transactions
Transaction* Biz:: createTrans(char type, string info){
    Transaction *action = nullptr;
    switch (type){
        case 'B':{
            action = new Borrow();
            break;
        }
        case 'R':{
            action = new Return();
            break;
        }
        case 'I':{
            action = new Inventory();
            break;
        }
        case 'H':{
            action = new History();
            break;
        }
        default:{
            cout << "Improper transaction action code entered" << endl;
            return nullptr;
        }
    }
    action -> doTrans(info);
    return action; // basecase
} 