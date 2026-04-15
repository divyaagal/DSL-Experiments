#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Stack class
class Stack {
private:
    Node* head;

public:
    Stack() {
        head = NULL;
    }

    // Push operation (Insert at end)
    void push(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        cout << value << " pushed into stack\n";
    }

    // Pop operation (Delete from end)
    void pop() {
        if (head == NULL) {
            cout << "Stack Underflow\n";
            return;
        }

        if (head->next == NULL) {
            cout << head->data << " popped from stack\n";
            delete head;
            head = NULL;
            return;
        }

        Node* temp = head;
        Node* prev = NULL;

        while (temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }

        cout << temp->data << " popped from stack\n";
        delete temp;
        prev->next = NULL;
    }

    // Display stack
    void display() {
        if (head == NULL) {
            cout << "Stack is empty\n";
            return;
        }

        Node* temp = head;
        cout << "Stack elements: ";
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

// Main function
int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    s.display();

    s.pop();
    s.display();

    s.pop();
    s.display();

    return 0;
}
