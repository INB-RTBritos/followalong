#include<iostream>
using namespace std;

struct Node {
    int value; // Data member
    Node *next;// next pointer 
}*head = NULL, *current = NULL, *previous = NULL;

// Prototype for linked list operation
void AppendNode(int);
void DisplayList();
void InsertNode(int);


int main() {
    int val;

    do {
        cout << "Enter a value: ";
        cin >> val;
        if (val < 0) break;
        InsertNode(val);
    } while (true);
    DisplayList();
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
    cout << "\nNew node is appended...\n\n";
}

void DisplayList() {

    if (!head) {
        cout << "\n\nThe list is empty\n\n";
    }
    else {
        // traverse the list up to the last node
        current = head;
        while (current) { // same as current != NULL
            cout << current->value << "\n";
            // moves to the next node
            current = current->next;
        }
        cout << "\nEnd of list...\n\n";
    }
}

void InsertNode(int newValue) {
    Node *newNode = new Node; // Create a new Node
    newNode->value = newValue; // Store data to the data member
    newNode->next = NULL; // Set the next pointer to NULL

    if (!head) {
        head = newNode;
    } 
    else {
        // traverse the list to find the correct position where the new node will be inserted
        current = head;
        // loop will stop if the new value is lesser than the current node
        // or the end of the list is reached
        while (current && current->value < newValue) {
            previous = current;
            current = current->next;
        }
        // insert node
        if (!previous) {
            head = newNode;
            newNode->next = current;
        }
        else {
            // break the link so that the new node can be inserted
            previous->next = newNode;
            // reconnect the link
            newNode->next = current;
        }
    }
}