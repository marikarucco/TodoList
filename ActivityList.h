#ifndef TODOLIST_ACTIVITYLIST_H
#define TODOLIST_ACTIVITYLIST_H
#include <string>
#include <list>
#include <utility>
#include "Activity.h"
using namespace std;

class ActivityList {
private:
    int size;
    string name;
public:
    list <Activity> activitiesToDo = list <Activity>();
    void addActivity(const Activity& a);
    void removeActivity(const Activity& a);
    bool searchActivity(const Activity& a);
    void modifyActivity(Activity& a, int _id, const string& _description, bool d_);
    int getActivitiesToDo();
    void saveList(const string& file);
    void readList(const string& file, int n);
    ActivityList(){
        size = 0;
        name = "";
    }
    explicit ActivityList(const string& _name){
        size = 0;
        name = _name;
    }
    int getSize() {
        return ActivityList::size;
    }
    string getName(){
        return ActivityList::name;
    }
};


#endif //TODOLIST_ACTIVITYLIST_H
