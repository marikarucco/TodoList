#ifndef TODOLIST_ACTIVITY_H
#define TODOLIST_ACTIVITY_H
#include <string>
using namespace std;

class Activity {

private:
    int id;
    string description;

public:
    Activity() {}

    Activity(int id, const string description)
    {
        this->id = id;
        this->description = description;
    }

    void setId(int id) {
        this->id = id;
    }


    int getId(){
        return this->id;
    }

    void setDescription(const string description) {
        this->description = description;
    }

    string getDescription()
    {
        return this->description;
    }

};


#endif //TODOLIST_ACTIVITY_H
