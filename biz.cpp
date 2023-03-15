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
    DVD thisMovie(info);
    if(thisMovie.genre == 'N' || thisMovie.name == "null" || thisMovie.direct == "null" || thisMovie.date == "null") return false; 
    Node* hold = new Node();
    if(thisMovie.genre == 'F') {
        thisMovie = Comedy(thisMovie);
    }
    if(thisMovie.genre == 'D') {
        thisMovie = Drama(thisMovie); 
    }
    if(thisMovie.genre == 'C') {
        thisMovie = Classic(thisMovie, info);
    } 
    insertMovie(thisMovie);
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