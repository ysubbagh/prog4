#include "transaction.h"

//constructor
Transaction:: Transaction(){}

bool Transaction:: doTrans(string info){
    cout << "Unable to complete a transaction" << endl;
    return false;
}

/*
//help sort comdies
bool Transaction::compareTitles(const DVD *a, const DVD *b){
    return a -> name < a -> name;
}

//help sort the drama
bool Transaction::CompareDirectors(const DVD *a, const DVD *b){
    return a -> direct < a -> direct;
}

//add an error to the list
void Transaction:: addError(string info){
    errorHist = errorHist + "\n" + info;
}

void Transaction:: printErrors(){
    cout << errorHist << endl;
}

bool Transaction:: checkFormat(vector<string> info){
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
vector<string> Transaction:: parse(string info){
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
DVD* Transaction:: findMovie(char type, string info){
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

*/