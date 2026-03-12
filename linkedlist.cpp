#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

// Display
void display() {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// Insert at Beginning
void insertAtBeginning(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

// Insert at End
void insertAtEnd(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if(head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Insert at Position
void insertAtPosition(int value, int pos) {
    Node* newNode = new Node();
    newNode->data = value;

    if(pos == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;
    for(int i=1; i<pos-1 && temp!=NULL; i++) {
        temp = temp->next;
    }

    if(temp == NULL) {
        cout<<"Invalid Position\n";
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete Beginning
void deleteAtBeginning() {
    Node* temp = head;
    head = head->next;
    delete temp;
}

// Delete End
void deleteAtEnd() {
    Node* temp = head;

    while(temp->next->next != NULL) {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = NULL;
}

// Delete Position
void deleteAtPosition(int pos) {
    Node* temp = head;

    for(int i=1;i<pos-1;i++) {
        temp = temp->next;
    }

    Node* del = temp->next;
    temp->next = del->next;
    delete del;
}

int main() {

    cout<<"Insertion Operations\n";

    insertAtBeginning(10);
    cout<<"After inserting 10 at beginning:\n";
    display();

    insertAtBeginning(5);
    cout<<"After inserting 5 at beginning:\n";
    display();

    insertAtEnd(20);
    cout<<"After inserting 20 at end:\n";
    display();

    insertAtPosition(15,3);
    cout<<"After inserting 15 at position 3:\n";
    display();


    cout<<"\nDeletion Operations\n";

    deleteAtBeginning();
    cout<<"After deleting from beginning:\n";
    display();

    deleteAtEnd();
    cout<<"After deleting from end:\n";
    display();

    deleteAtPosition(2);
    cout<<"After deleting from position 2:\n";
    display();

}
