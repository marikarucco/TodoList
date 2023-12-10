#include "ActivityList.h"
#include <fstream>
#include <filesystem>
#include <iostream>
#include <algorithm>
using namespace std;


void ActivityList::addActivity(const int _id, const string d) {
    Activity a (_id, d);
    this->activitiesToDo.push_back(a);
}


void ActivityList::saveList(string fileName) {
    ofstream documento(fileName);
    for(Activity item : this->activitiesToDo){
        int id = item.getId();
        string description = item.getDescription();
        documento << id << ' ' << description << endl ;
    }
    documento.close();
}

void ActivityList::readList(const string fileName, int n) {
    this->activitiesToDo.clear();
    ifstream documento (fileName);
    if(!filesystem::exists(fileName)){
       cout << "Il file richiesto non esiste, provare con un altro nome.";
    } else {

       for(int i=1; i<n+1; i++) {
            string description;
            int _id;
            documento >> _id >> description;
            replace(description.begin(), description.end(), '_', ' ');
            this->addActivity(_id, description);
        }
        cout << "Ecco la tua todo list!" << endl;
        for( Activity item : this->activitiesToDo){
            cout << item.getId() << " "<< item.getDescription() << endl;
        }

        documento.close();
    }

}



