#ifndef TODOLIST_ACTIVITYLIST_H
#define TODOLIST_ACTIVITYLIST_H
#include <string>
#include <list>
#include "Activity.h"
using namespace std;

class ActivityList {
public:
    list <Activity> activitiesToDo;
    void addActivity(int id, string a);
    void saveList(string file);
    void readList(string file, int n);
};


#endif //TODOLIST_ACTIVITYLIST_H
