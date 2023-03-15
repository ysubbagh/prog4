#include "dvd.h"

//constructors
DVD:: DVD(){
    genre = 'N'; //null
    string name = "null";
    string date = "null";
    string direct = "null";
}
DVD:: DVD(string info){
    //stuff
    genre = info[0];
    if(genre != 'C' || genre != 'D' || genre != 'F'){
        cout << "This line -- " << info << " -- has incorrect movie type and cannot be added";
    }
    info = info.substr(3);
    stock = stoi(info.substr(0, info.find(',')));
    info = info.substr(info.find(',') + 1 );
    direct = info.substr(0, info.find(','));
    info = info.substr(info.find(','));
}
