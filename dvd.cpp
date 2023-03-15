#include "dvd.h"

//constructors
DVD:: DVD(){
    genre = 'N'; //null
    string name = "null";
    string date = "null";
    string direct = "null";
}

//return the current stock of the movie
int DVD:: getStock(){
    return stock;
}

//return the history of the movie
string DVD:: getHistory(){
    return history;
}

//set the data to the item, backup
bool DVD:: setData(string info){
    cout << "Movie was not able to be added to system";
    return false;
}