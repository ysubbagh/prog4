#include "biz.h"

//constructor
Biz:: Biz(){
    vector<DVD*> row;
    for(int i = 0; i < 3; i++){
        movieStock.push_back(row);
    }
}

//destructor
Biz:: ~Biz(){
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < movieStock[i].size(); j++) {
            delete movieStock[i][j];
        }
        movieStock[i].clear();
    }
    custTable.clearTable();
}

//functions//
//load in new movie
bool Biz:: buildMovie(string info){
    DVD *movie = createMovie(info[0], info);
    if(movie == nullptr) {
        cout << "Improper movie genre entered" << endl;
        return false;
    }
    insertMovie(movie);
    return true; // basecase
}

//insert the movie into the 
bool Biz:: insertMovie(DVD *movie){
    int index = 0;
    if(movie -> genre == 'D') index = 1;
    if(movie -> genre == 'C') index = 2;
    for(int i = 0; i < movieStock[index].size(); i++){
        if(movieStock[index][i] -> name.compare(movie -> name) == 0) return false;
    }
    movieStock[index].push_back(movie);
    return true; // base case
}

//build a customer profile
bool Biz:: buildCust(string info){
    string num = info.substr(0, 4);
    info = info.substr(info.find(' ') + 1);
    string f = info.substr(0, info.find(' '));
    info = info.substr(info.find(' '));
    Customer *person = new Customer(num, f, info);
    //cout << person -> getName() << "    " << person -> getId() << endl;
    custTable.addItem(person);
    return true; // basecase
}

//process a transaction
bool Biz:: transaction(string info){
    Transaction* doStuff = createTrans(info[0], info);
    return true; //base case
}

//factory pattern to choose the correct movie type
DVD* Biz:: createMovie(char type, string info){
    DVD *movie = nullptr;
    switch (type) {
        case 'C':{
            movie = new Classic();
            break;
        }
        case 'D':{
            movie = new Drama();
            break;
        }
        case 'F':{
            movie = new Comedy();
            break;
        }
        default:{
            cout << "Improper movie genre type entered" << endl;;
            return nullptr;
        }
    }
    movie -> setData(info);
    return movie;
}

// factory design for the transactions
Transaction* Biz:: createTrans(char type, string info){
    Transaction *action = nullptr;
    switch (type){
        case 'B':{
            action = new Borrow();
            break;
        }
        case 'R':{
            action = new Return();
            break;
        }
        case 'I':{
            action = new Inventory();
            printStock();
            break;
        }
        case 'H':{
            action = new History();
            int cust = stoi(info.substr(info.find(' ')));
            custHist(cust);
            break;
        }
        default:{
            cout << "Improper transaction action code entered" << endl;
            return nullptr;
        }
    }
    action -> doTrans(info);
    return action; // basecase
} 

//print out the currnet stock of the Biz
void Biz:: printStock(){
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
}

//print out the history of a customer
void Biz:: custHist(int num){
    Customer* ppl = custTable.getCust(num);
    if(ppl == nullptr) return;
    cout << "History for " << ppl -> getName() << ":" << endl;
    cout << ppl -> getTrans() << endl;
}

//testing print function to make sure hashtable is correct
void Biz:: printT(){
    custTable.printTable();
}

//helper function for sorting the funny movies
bool Biz::compareTitles(const DVD *a, const DVD *b) {
    return a -> name < b -> name;
}

//helper function for sorting drama movies
bool Biz:: CompareDirectors(const DVD *a, const DVD *b){
    return a -> direct < b -> direct;
}

