
//Quinn Caton
//CS303 Data Structures
//4-21-2022


#include <iostream>
#include <map>
#include <iterator>
#include <string>
using namespace std;

void outputMapData(map<string, string>);
void userSearch(map<string, string>);

int main()
{
    map<string, string> stateDataMap;
    
    //statements to add state keys and capital data to map
    stateDataMap.insert(pair<string, string>("Nebraska", "Lincoln"));
    stateDataMap.insert(pair<string, string>("New York", "Albany"));
    stateDataMap.insert(pair<string, string>("Ohio", "Columbus"));
    stateDataMap.insert(pair<string, string>("California", "Sacramento"));
    stateDataMap.insert(pair<string, string>("Massachusetts", "Boston"));
    stateDataMap.insert(pair<string, string>("Texas", "Austin"));

    //statement: change capital of Cali to Los Angeles
    stateDataMap["California"] = "Los Angeles";

    outputMapData(stateDataMap);
    userSearch(stateDataMap);
}

//method: output data in stateDataMap
//pre: a map of key (state string) and data (capital string)
//post: output keys followed by data, separated by a comma
void outputMapData(map<string, string> sdm) {
    //iterators for begin/end of map
    map<string, string>::iterator mb = sdm.begin();
    map<string, string>::iterator me = sdm.end();
    for (; mb != me; mb++) {
        //outputs key (state) first, then data (capital)
        cout << mb->first << ", " << mb->second << endl;
    }
}

//method: output capitalName from stateName entered by user
//pre: a map of data with key (state) and data (capital)
//post: output capital data through with key input from user
//      loop if key isn't found in map
void userSearch(map<string, string> sdm) {
    string searchKey;
    while (true) {
        cout << "Enter the state to search: ";
        getline(cin, searchKey); //gets state name from user
        if (sdm.find(searchKey) == sdm.end()) { // checks membership in keys through iterator
            cout << "That state is not found in the set of data." << endl;
            continue;
        }
        else {
            cout << "The capital of " << searchKey << " is " << sdm[searchKey] << endl;
            break;
        }
    }
}