#ifndef TODOLIST_ACTIVITYLIST_H
#define TODOLIST_ACTIVITYLIST_H
#include <string>
#include <list>
#include <utility>
#include "Activity.h"
using namespace std;

class ActivityList {
private:
    string name;
    list <Activity> activitiesToDo;
public:
    explicit ActivityList(const string& name) : name(name) {};

    string getName() const{
        return name;
    }
    void setName(const string& n){
        name = n;
    }

    void addActivity(const Activity& a);
    void removeActivity(const Activity& a);
    int getSize() const;
    void getListSorted();
    bool searchActivity(const Activity& a) const;
    Activity searchActivityByDescription(const string& d) const;
    void modifyActivity(Activity& a, int id, const string& description, bool done, int duration);
    int getNumActivitiesToDo() const;
    list<Activity> getListOfUndone () const;
    void saveList(const string& file) const;
    void readList(const string& file, int n);

};


#endif //TODOLIST_ACTIVITYLIST_H
