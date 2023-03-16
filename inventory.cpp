#include "inventory.h"

Inventory:: Inventory(){

}

bool Inventory:: doTrans(string info){

    return true; //basecase
}

/*
bool Inventory:: doTrans(){
    sort(movieStock[0].begin(), movieStock[0].end(), compareTitles);
    sort(movieStock[1].begin(), movieStock[1].end(), CompareDirectors);
    for(int i = 0; i < movieStock.size(); i++){
        cout << "---------------------------" << endl;
        if(i == 0) cout << "Comedies: " << endl;
        if(i == 1) cout << "Dramas: " << endl;
        if(i == 2) cout << "Classics: " << endl;
        cout << "   Genre   Media                       Title                       Director" << endl;
        if(i == 2) cout << "Month    ";
        cout << "Stock   Year" << endl;
        for(int j = 0; j < movieStock[i].size(); j++){
            cout << "   " << movieStock[i][j] -> genre << " D               " << movieStock[i][j] -> name << "      "  <<  movieStock[i][j] -> direct << endl;
            if(i == 2) cout << movieStock[i][j] -> numDate << " ";
            cout << movieStock[i][j] -> stock << "  ";
            cout << movieStock[i][j] -> date << endl;
            if(i == 2) cout << "                                        " << movieStock[i][j] -> star << endl;
        }
        cout << endl;
    }
    return true;
}
*/