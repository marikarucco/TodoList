#include "ActivityList.h"
#include <fstream>
#include <filesystem>
#include <iostream>
#include <string>
using namespace std;


void ActivityList::addActivity(const Activity& a) {
    this->activitiesToDo.push_back(a);
    size++;
    activitiesToDo.sort();
}

void ActivityList::removeActivity(const Activity& a) {
    activitiesToDo.remove(a);
    size--;
}

bool ActivityList::searchActivity(const Activity& a) {
    bool found = false;
    for(const Activity& item : activitiesToDo){
        if(item != a){
            found = false;
        }else{
            found = true;
            break;
        }
    }
    cout << (!found ? "Task non trovato" : "Task trovato con successo") << endl;
    return found;
}

int ActivityList::getActivitiesToDo() {
    int count = 0;
    for(Activity item : activitiesToDo){
        if(!item.getDone()){
            count++;
        }
    }
    cout << "I task che devono essere ancora svolti sono" << " " << count << ":"<< endl;
    for(Activity item : activitiesToDo){
        if(!item.getDone()){
            cout << item.getDescription() <<endl;
        }
    }
    return count;
}

void ActivityList::modifyActivity(Activity& a, int _id, const string& _description, bool _d){
    removeActivity(a);
    a.setId(_id);
    a.setDescription(_description);
    a.setDone(_d);
    addActivity(a);
}

void ActivityList::saveList(const string& fileName) {
    ofstream documento(fileName);
    for(Activity item : this->activitiesToDo){
        int id = item.getId();
        string description = item.getDescription();
        bool done = item.getDone();
        documento << id << ' ' << description << " "<< "(" << (!done ? "Non completato" : "Completato") << ")" <<endl ;
    }
    documento.close();
}

void ActivityList::readList(const string& fileName, int n) {
    size = 0;
    activitiesToDo.clear();
    ifstream documento (fileName);
    if(!filesystem::exists(fileName)){
       cout << "Il file richiesto non esiste, provare con un altro nome.";
    } else {
        cout << "Ecco la tua todo list!" << endl;
       for(int i =1; i< n+1; i++){
            int _id;
            string _description;
            string _done;
            bool d;
            documento >> _id;
            getline(documento, _description, '(');
            getline(documento, _done, ')');
            _done == "Non completato" ? d=false : d=true;
            Activity a (_id, _description, d);
            addActivity(a);
            cout << _id << " " << _description << " " << "(" << _done << ")" << endl;
        }

        documento.close();
    }

}











