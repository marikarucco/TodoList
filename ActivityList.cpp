#include "ActivityList.h"
#include <fstream>
#include <filesystem>
#include <iostream>
#include <string>
using namespace std;


void ActivityList::addActivity(const Activity& a) {
    this->activitiesToDo.push_back(a);
}

void ActivityList::removeActivity(const Activity& a) {
    activitiesToDo.remove(a);
}

int ActivityList::getSize() const {
    return int(activitiesToDo.size());
}

void ActivityList::getListSorted() {
    activitiesToDo.sort();
}


bool ActivityList::searchActivity(const Activity& a) const {
    bool found = false;
    for(const Activity& item : activitiesToDo){
        if(item != a){
            found = false;
        }else{
            found = true;
            break;
        }
    }
    return found;
}

Activity ActivityList::searchActivityByDescription(const string& d) const{
    Activity a;
    for(const Activity& item : activitiesToDo){
        if(item.getDescription() == d){
            a = item;
            break;
        }
    }
    return a;
}

int ActivityList::getNumActivitiesToDo() const {
    int count = 0;
    for(const Activity& item : activitiesToDo){
        if(!item.getDone()){
            count++;
        }
    }
    return count;
}

list<Activity> ActivityList::getListOfUndone() const {
    list <Activity> todo = list <Activity>();
    for(const Activity& item : activitiesToDo){
        if(!item.getDone()){
            todo.push_back(item);
        }
    }
    return todo;
}

void ActivityList::modifyActivity(Activity& a, int id, const string& description, bool done, int duration){
    removeActivity(a);
    Activity b(id, description, done, duration);
    addActivity(b);
}

void ActivityList::saveList(const string& fileName) const {
    ofstream document(fileName);
    for(const Activity& item : this->activitiesToDo){
        int id = item.getId();
        string description = item.getDescription();
        bool done = item.getDone();
        int duration = item.getDuration();
        document << id << " " << description << " " << "(" << (!done ? "Non completato" : "Completato")
        << ")" << " " << duration << " " << "minuti "<< endl ;
    }
    document.close();
}

void ActivityList::readList(const string& fileName, int n) {
    activitiesToDo.clear();
    ifstream document (fileName);
    if(!filesystem::exists(fileName)){
       cout << "Il file richiesto non esiste, provare con un altro nome.";
    } else {
        cout << "Ecco la tua todo list!" << endl;
       for(int i =1; i< n+1; i++){
            int id;
            string description;
            string done;
            bool d;
            int duration;
            string minuti;
            document >> id;
            getline(document, description, '(');
            getline(document, done, ')');
            document >> duration;
            getline(document, minuti, '\n');
            done == "Non completato" ? d=false : d=true;
            Activity a (id, description, d, duration);
            addActivity(a);
            cout << id << " " << description << " " << "(" << done << ")" << " " << duration << minuti << endl;

        }

        document.close();
    }

}


























