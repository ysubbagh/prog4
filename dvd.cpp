#include "dvd.h"

//constructors
DVD:: DVD(){
    genre = 'N'; //null
    string name = "null";
    string date = "null";
    string direct = "null";
}

int DVD:: getStock(){
    return stock;
}

bool DVD:: setData(string info){
    cout << "Movie was not able to be added to system";
    return false;
}