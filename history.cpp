#include "history.h"

//constrctor
History:: History(){}

bool History:: doTrans(string info){

    return true; //basecase
}

/*
bool History:: doTrans(string info){
    int num = stoi(info.substr(info.find(' ')));
    Customer* ppl = custTable.getCust(num);
    if(ppl == nullptr) return;
    cout << "History for " << ppl -> getName() << ":" << endl;
    cout << ppl -> getTrans() << endl << endl;
    return true;
}
*/