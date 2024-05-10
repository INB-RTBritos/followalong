#include<iostream>
using namespace std;

struct Node {
    int value; // Data member
    Node *next; // next pointer
}*head = NULL, *current = NULL;

// Prototype for linked list operation
void AppendNode(int);

int main() {
    int val;

    do {
        cout << "Enter a value: ";
        cin >> val;
        if (val < 0) break;
        AppendNode(val);
    } while (true);
}

// Function Definition
void AppendNode(int newValue) {
    Node *newNode = new Node; // create a new node

    newNode->value = newValue;
    newNode->next = NULL;

    // empty list
    if (!head) { // same as head == NULL
        head = newNode; 
    }

    // not empty list
    else {
        // traverse the list to find the last node
        current = head;

        while (current->next) {
            current = current->next;
        }
        current->next = newNode; // if last node is reached, append the new node
    }
    cout << "New node is appended...";
}