#include "comedy.h"
#include <bits/stdc++.h>

//constructors
Comedy::Comedy(){}
Comedy:: Comedy(string info){
    this -> setData(info);
}


//set the data to the comedy movie
bool Comedy:: setData(string info){
    vector<string> v;
    stringstream ss(info);
    while (ss.good()) {
        string substr;
        getline(ss, substr, ',');
        v.push_back(substr);
    }
    for (int i = 0; i < v.size(); i++){
        switch (i) {
            case 0:{
                genre = info[0];
                break;
            }
            case 1:{
                stock = stoi(v[i]);
                if(stock < 0) stock = 0;
                break;
            }
            case 2:{
                direct = v[i].substr(1);
                break;
            }
            case 3:{
                name = v[i].substr(1);;
                break;
            }
            case 4:{
                date = v[i].substr(1);
                break;
            }
            default:{
                cout << "Too much info passed into movie4data" << endl;
                return false;
            }
        }
    }
    return true; 
}