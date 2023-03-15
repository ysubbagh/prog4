#include "drama.h"
#include <bits/stdc++.h>

//constructor
Drama:: Drama(){


}

//set the data to the drama movie
bool Drama:: setData(string info){
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
                direct = v[i];
                break;
            }
            case 3:{
                name = v[i];
                break;
            }
            case 4:{
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