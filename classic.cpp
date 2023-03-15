#include "classic.h"
#include <bits/stdc++.h>

//constructor
Classic:: Classic(){}
Classic:: Classic(string info){
    this -> setData(info);
}

//set the data to the classic movie
bool Classic:: setData(string info){
    genre = info[0];

    vector<string> v;
    stringstream ss(info);
    while (ss.good()) {
        string substr;
        getline(ss, substr, ',');
        v.push_back(substr);
    }
    for (int i = 0; i < v.size(); i++){
        v[i] = v[i].substr(1);
        switch (i) {
            case 0:{ // genre already set
                break;
            }
            case 1:{ //set stock size
                stock = stoi(v[i]);
                if(stock < 0) stock = 0;
                break;
            }
            case 2:{ //set director
                direct = v[i];
                break;
            }
            case 3:{ //set title
                name = v[i];
                break;
            }
            case 4:{ //set star, releas date, and release date
                star = v[i].substr(0, v[i].find(' '));
                v[i] = v[i].substr(v[i].find(' ') + 1);
                numDate =  v[i].substr(0, v[i].find(' ')) ;
                v[i] = v[i].substr(v[i].find(' ') + 1);
                date = v[i];
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