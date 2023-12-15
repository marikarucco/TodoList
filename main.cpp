#include <iostream>
#include <string>
#include "ActivityList.h"
using namespace std;

int main() {
    int n;
    ActivityList l ("lista");
    cout << "Inserire il numero di task da svolgere: " << endl;
    cin >> n;
    cin.ignore();
    for (int i=1; i< n+1; i++){
        string activityDescription;
        cout << "Inserire task numero " << i << ":" << endl;
        getline(cin, activityDescription);
        Activity a (i, activityDescription, false);
        l.addActivity(a);
    }
    string save;
    string review;
    cout << "Salvare questa lista? (y/n)" << endl;
    cin >> save;
    if(save == "y") {
        l.saveList("mytodolist.txt");
    }
    cout << "Rivedere la lista appena salvata? (y/n)" << endl;
    cin >> review;
    if(review ==  "y"){
        l.readList("mytodolist.txt", l.getSize());
    }

}
