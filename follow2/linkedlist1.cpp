#include<iostream>
using namespace std;

struct Node {
    int value; // Data member
    Node *next;// next pointer 
}*head = NULL, *current = NULL, *previous = NULL, *nextNode = NULL;

// Prototype for linked list operation
void AppendNode(int);
void DisplayList();
void InsertNode(int);
void DeleteNode(int);
void DestroyList();


int main() {
    int val;

    while (true) {
        cout << "Enter a value: ";
        cin >> val;
        if (val < 0) break;
        InsertNode(val);
    }
    DisplayList();
    // delete per value
    while (true){
        cout << "\nEnter value to be delete: ";
        cin >> val;
        if (val < 0) break;
        DeleteNode(val);
        DisplayList();
    }
    // delete whole list
    DestroyList();
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
void DeleteNode(int valueToDelete) {
    bool found = false;
    if (!head) {
        cout << "List is empty...";
    }
    else {
        if (head->value == valueToDelete) {
            // if the value to be deleted is the first node
            // temporarily set the current node to point to the 2nd node in the list
            current = head->next;
            // delete the current first node
            delete head;
            // set the second node as the new first node
            head = current;
            found = true;
        }
        else {
            // traverse the list until the value to be deleted is found
            current = head;
            while (current->value != valueToDelete) {
                previous = current;
                current = current->next;
            }
            // if the value to be deleted is found 
            if (current) {
                // break the link of node that will be deleted
                previous->next= current->next;
                // delete the node
                delete current;
                found = true;
            }
        }
        if (found) 
        cout << "value is now deleted...\n";
        else 
        cout << "values is not in the list...\n";
    }
}

void DestroyList() {
    if(!head) {
        cout << "list is empty...\n";
    }
    else {
        // traverse the list up to the last node
        current = head;
        while(current) {
            // get the next node to be deleted
            nextNode = current->next;
            // delete the current node
            delete current;
            // assign the next node to be deleted
            current = current->next;
        }
        cout << "The list is now destroyed...\n";
        head = NULL;
    }
}