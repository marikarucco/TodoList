#include <iostream>
#include <string>
#include "ActivityList.h"
using namespace std;

int main() {
    int n;
    ActivityList lista;
    cout << "Inserire il numero di task da svolgere: " << endl;
    cin >> n;
    for (int i=1; i< n+1; i++){
        string activityDescription;
        cout << "Inserire task numero " << i << ":" << endl;
        cin >> activityDescription;
        lista.addActivity(i, activityDescription);
    }
    lista.saveList("mytodolist.txt");
    lista.readList("mytodolist.txt", n);
}
