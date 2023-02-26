#include <iostream>
#include <vector> 
#include <DVD.h> 
#include <biz.h> 

using namespace std;

/*
    classic movies store name of movie, release date, stock amount, lead role / star, and director
*/

class Classic : public DVD{

public:
    //constructors
    Classic();
    Classic(string name, int stock, string date, string star);

private:
    int stock = 0; //set stock to 0 to start
    string name;
    string date;
    string direct;
    string star;

};