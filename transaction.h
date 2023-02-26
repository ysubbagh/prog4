#include <iostream>
#include <vector> 
#include <biz.h> 

using namespace std;
/*
    transactions starts a transaction type
*/

class Transaction{

    friend class Biz;

public:
    //constructor
    Transaction();

    //complete a transaction
    bool doTrans();

    //set data
    bool setData();

private:
    //do a return transaction
    bool doReturn(int cust, DVD item);

    //do a borrow transaction
    bool doBorrow(int cust, DVD item);

    //show cust info
    string doShow(int cust);
    
    //show customer history transaction records
    string doHistory(int cust);
};