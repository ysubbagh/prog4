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
    //custTable.clearTable();
}

//functions//
//load in new movie
bool Biz:: buildMovie(string info){
    DVD *movie = createMovie(info[0], info);
    if(movie == nullptr) {
        //cout << "Improper movie genre entered" << endl;
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
            //cout << "Improper movie genre type entered" << endl;;
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
            doBorrow(info);
            break;
        }
        case 'R':{
            action = new Return();
            doReturn(info);
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
            string transError = "ERROR: " + type;
            transError += " Invalid Transaction Type. Try Again.";
            addError(transError);
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
    cout << ppl -> getTrans() << endl << endl;
}

//testing print function to make sure hashtable is correct
void Biz:: printT(){
    custTable.printTable();
}

//help sort comdies
bool Biz::compareTitles(const DVD *a, const DVD *b){
    return a -> name < a -> name;
}

//help sort the drama
bool Biz::CompareDirectors(const DVD *a, const DVD *b){
    return a -> direct < a -> direct;
}

//add an error to the list
void Biz:: addError(string info){
    errorHist = errorHist + "\n" + info;
}

void Biz:: printErrors(){
    cout << errorHist << endl;
}

//complete a borrow transaction
bool Biz:: doBorrow(string info){
    vector<string> data = parse(info);
    if(!checkFormat(data)) return false;
    DVD* movieToCheckOut = findMovie(data[2][0], data[3]);
    if(movieToCheckOut == nullptr) return false;
    if(movieToCheckOut -> stock <= 0){
        addError("ERROR:  Borrow Transaction Failed -- Not enough in stock");
        return false;
    }
    movieToCheckOut -> stock -= 1;
    Customer* shopper = custTable.getCust(stoi(data[0]));
    shopper -> addTrans("Borrowed " + movieToCheckOut -> name);
    return true;//basecase
}

//complete a return transaction
bool Biz:: doReturn(string info){
    vector<string> data = parse(info);
    if(!checkFormat(data)) return false;
    DVD* movieToCheckOut = findMovie(data[2][0], data[3]);
    if(movieToCheckOut == nullptr) return false;
    Customer* shopper = custTable.getCust(stoi(data[0]));
    movieToCheckOut -> stock += 1;
    shopper -> addTrans("Returned " + movieToCheckOut -> name);
    return true;//basecase
}

//make sure all the data passed for the transaction is legeal
bool Biz:: checkFormat(vector<string> info){
    //invalid custoemr
    if(custTable.getCust(stoi(info[0])) == nullptr){
        addError("ERROR: Transaction Failed -- Customer " + info[0] + " does not exist.");
        return false;
    }
    if(info[1] != "D"){
        addError("ERROR: " + info[1] + " Invalid Media Type. Try Again.");
        return false;
    }
    if(!(info[2] == "C" || info[2] == "D" || info[2] == "F")){
        addError("ERROR: " + info[2] + " Invalid Movie Genre. Try Again.");
        return false;
    }
    return true; //base case
}

//parse the string into a vector for easy usage
vector<string> Biz:: parse(string info){
    vector<string> ss;
    string id = info.substr(2,4);
    ss.push_back(id);
    string media = info.substr(7,1);
    ss.push_back(media);
    string type = info.substr(9,1);
    ss.push_back(type);
    string data = info.substr(11);
    ss.push_back(data);
    return ss;
}

//find the movie to be checkout or return nullptr
DVD* Biz:: findMovie(char type, string info){
    DVD* copy;
    switch (type){
        case 'C':{
            string infoMonth = info.substr(info.find_first_of("0123456789"), info.find(" "));
            for(int i = 0; i < movieStock[2].size(); i++){
                if(infoMonth.compare(movieStock[2][i] -> numDate) == 0 ){
                    string infoYear = info.substr(info.find_last_of("0123456789") - 3, 4);
                    if(stoi(infoYear) == stoi(movieStock[2][i] -> date)){
                        string infoActor = info.substr(info.find_last_of("0123456789") + 2);
                        //if(infoActor.compare(movieStock[2][i] -> star) == 0){ //idk why but this just wont work
                            return movieStock[2][i];
                        //}
                    }
                }
                
            }
            break;
        }
        case 'F':{
            string title = info.substr(0, info.find(','));
            for(int i = 0; i < movieStock[0].size(); i++){
                if(movieStock[0][i] -> name.compare(title) == 0){
                    return movieStock[0][i];
                }
            }
            break;
        }
        case 'D':{
            for(int i = 0; i < movieStock[1].size(); i++){
                if(movieStock[1][i] -> direct.compare(info.substr(0, info.find(','))) == 0 ){
                    return movieStock[1][i];
                }
            }
            break;
        }
        default:{
            break;
        }
    }
    addError("ERROR: Transaction Failed -- Movie does not exist");
    return nullptr; //basecase
}