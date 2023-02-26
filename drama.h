#include <iostream>
#include <vector> 
#include <DVD.h> 
#include <biz.h> 

using namespace std;

/*
    drama movies store name of movie, release date, stock amount, and director
*/
class Drama : public DVD{

public:
    //constructors
    Drama();
    Drama(string name, int stock, string date, string direct);


private:
    int stock = 0; //set stock to 0 to start
    string name;
    string date;
    string direct;

};