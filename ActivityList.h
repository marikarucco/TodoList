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
    ActivityList () : name(), activitiesToDo(){};
    explicit ActivityList(const string& name) : name(name) {};

    [[nodiscard]] string getName() const{
        return name;
    }
    void setName(const string& n){
        name = n;
    }
    [[nodiscard]] list<Activity> getActivitiesToDo () const{
        return activitiesToDo;
    };
    void addActivity(const Activity& a);
    void removeActivity(const Activity& a);
    [[nodiscard]] int getSize() const;
    void getListSorted();
    [[nodiscard]] bool searchActivity(const Activity& a) const;
    [[nodiscard]] Activity searchActivityByDescription(const string& d) const;
    void modifyActivity(Activity& a, int id, const string& description, bool done, int duration);
    [[nodiscard]] int getNumActivitiesToDo() const;
    [[nodiscard]] list<Activity> getListOfUndone () const;
    void saveList(const string& file) const;
    void readList(const string& file, int n);

};


#endif //TODOLIST_ACTIVITYLIST_H
