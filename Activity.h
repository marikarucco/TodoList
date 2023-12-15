#ifndef TODOLIST_ACTIVITY_H
#define TODOLIST_ACTIVITY_H
#include <string>
using namespace std;

class Activity {

private:
    int id;
    string description;
    bool done;
public:
    Activity() {
        id = 0;
        description = "";
        done = false;
    }

    Activity(int _id, const string& _description, bool _done)
    {
        id = _id;
        description = _description;
        done = _done;
    }

    bool operator == (const Activity& a) const{
        return id == a.id && description == a.description && done == a.done;
    }

    bool operator != (const Activity& a) const{
        return !operator==(a);
    }

    bool operator < (const Activity& a) const{
        return id < a.id;
    }

    void setId(int _id) {
        id = _id;
    }

    int getId(){
        return Activity::id;
    }

    void setDescription(const string& _description) {
        description = _description;
    }

    string getDescription()
    {
        return Activity::description;
    }

    void setDone(bool _done){
        done = _done;
    }

    bool getDone(){
        return Activity::done;
    }


};


#endif //TODOLIST_ACTIVITY_H
