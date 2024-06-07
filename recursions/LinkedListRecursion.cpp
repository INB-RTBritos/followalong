#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next = NULL;
};

void InsertNode(Node*&, int);
void DisplayList(Node*);
Node *ReverseList(Node*, Node*);

int main() {
    int num, amount;
    Node *head = NULL;
    cout << "Enter how many Numbers to put in a list: ";
    cin >> amount;

    for (int i = 0; i < amount; i++) {
        cout << "Enter a number: ";
        cin >> num;
        InsertNode(head, num);
    }

    cout << "Original Linked List: ";
    DisplayList(head);

    head = ReverseList(head, NULL);
    cout << "Reversed Order Linked List: ";
    DisplayList(head);
}

void InsertNode(Node*& head, int data) {
    Node *current = NULL, *newNode = NULL;
    newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    if (!head){
    head = newNode;
    }
    else {
         current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
} 

void DisplayList(Node* head) {
    if (!head) {
        cout << "List is currently empty.";
    }

    while (head){
        cout << head->data << " ";
        head = head->next;
    }
    cout << "\n";
}

Node *ReverseList(Node *current, Node *previous = NULL) {
    Node *nextNode = NULL;
    if (!current) 
    return previous;

  
    nextNode = current->next;
    current->next = previous;
    return ReverseList(nextNode, current);
    
}