#include <iostream>
#include <vector> 
#include <DVD.h> 
#include <biz.h> 

using namespace std;

/*
    comedy movies store name of movie, release date, stock amount, and director
*/

class Comedy : public DVD{

public:
    //constructors
    Comedy();
    Comedy(string name, int stock, string date, string director);

private:
    int stock = 0; //set stock to 0 to start
    string name;
    string date;
    string direct;

};