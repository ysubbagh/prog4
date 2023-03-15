#ifndef DVDFACT_H
#define DVDFACT_H

#include <iostream>
#include <vector> 
#include "dvd.h"
#include "comedy.h"
#include "classic.h"
#include "drama.h"

using namespace std;

/*
    choose which movie to make of type
*/

class DVDFactory{

    friend class Biz;

public:
    
    static DVD* createMovie(char type, string info){
        DVD *movie = NULL;
        switch (type) {
            case 'C':{
                movie = new Classic(info);
                break;
            }
            case 'D':{
                movie = new Drama(info);
                break;
            }
            case 'F':{
                movie = new Comedy(info);
                break;
            }
            default:{
                cout << "Improper movie genre type entered";
                break;
            }
        }
        return movie;
    }
    
};

#endif