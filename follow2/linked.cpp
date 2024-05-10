#include <iostream>
#include "list.h"
using namespace std;

int main() {
    List list;
    int val;

    while (true) {
        cout << "Enter a value: ";
        cin >> val;
        if (val < 0) break;
        list.InsertNode(val);
    }
    list.DisplayList();
    // delete per value
    while (true){
        cout << "\nEnter value to be delete: ";
        cin >> val;
        if (val < 0) break;
        list.DeleteNode(val);
        list.DisplayList();
    }
    // delete whole list
    list.DestroyList();
    list.DisplayList();
}