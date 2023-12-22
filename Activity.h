#ifndef TODOLIST_ACTIVITY_H
#define TODOLIST_ACTIVITY_H
#include <string>
#include <iostream>
using namespace std;

class Activity {

private:
    int id;
    string description;
    bool done;
    int duration;

public:
    Activity(int id, const string& description, bool done, int duration) : id(id), description(description), done(done)
    {
        setDuration(duration);
    };
    bool operator == (const Activity& a) const{
        return id == a.id && description == a.description && done == a.done && duration == a.duration;
    }

    bool operator != (const Activity& a) const{
        return !operator==(a);
    }

    bool operator < (const Activity& a) const{
        return id < a.id;
    }

    void setId(int i) {
        id = i;
    }

    int getId() const{
        return Activity::id;
    }

    void setDescription(const string& d) {
        description = d;
    }

    string getDescription() const
    {
        return Activity::description;
    }

    void setDone(bool d){
        done = d;
    }

    bool getDone() const{
        return Activity::done;
    }

    void setDuration(int d){
        if(d<0)
            throw invalid_argument("Duration can't be negative");
        else
            duration = d;
    }

    int getDuration() const{
        return Activity::duration;
    }
};


#endif //TODOLIST_ACTIVITY_H
