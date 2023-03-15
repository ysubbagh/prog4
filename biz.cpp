#include "biz.h"

//constructor
Biz:: Biz(){
    movieRoot -> data = nullptr;
    movieRoot -> left = nullptr;
    movieRoot -> right = nullptr; 
}

//desctrucot
Biz:: ~Biz(){

}

//functions//
//load in new movie
bool Biz:: buildMovie(string info){
    DVD *movie = createMovie(info[0], info);
    return true; // basecase
}

//insert the movie into the 
bool Biz:: insertMovie(DVD movie){

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


    return true; // basecase
}

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
            cout << "Improper movie genre type entered";
            return nullptr;
        }
    }
    movie -> setData(info);
    return movie;
}