#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = NULL;
void display() {
    Node* temp = head;
    if (temp == NULL) {
        cout << "List is empty\n";
        return;
    }

    cout << "Doubly Linked List: ";
    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

void insertAtPosition(int value, int pos) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (pos == 1) {
        if (head != NULL)
            head->prev = newNode;

        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Position out of range\n";
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;
}

void deleteAtPosition(int pos) {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    Node* temp = head;

    if (pos == 1) {
        head = temp->next;
        if (head != NULL)
            head->prev = NULL;

        delete temp;
        return;
    }

    for (int i = 1; i < pos && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Position out of range\n";
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    delete temp;
}

int main() {
    int choice, value, pos;

    while (true) {
        cout << "\n1. Insert\n2. Delete\n3. Display\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                cout << "Enter position: ";
                cin >> pos;
                insertAtPosition(value, pos);
                break;

            case 2:
                cout << "Enter position to delete: ";
                cin >> pos;
                deleteAtPosition(pos);
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                cout << "Invalid choice\n";
        }
    }
}