#include<iostream>
using namespace std;
#define MAX 5 
class Queue {
private:
int arr[MAX];
int front, rear;
public:
Queue() {
front = -1;
rear = -1;
}
bool isEmpty() {
return (front == -1);
}
bool isFull() {
return (rear == MAX - 1);
}
void enqueue(int value) {
if (isFull()) {
cout << "Queue is full" << endl;
return;
}
if (front == -1)
front = 0;
arr[++rear] = value;
cout << "Inserted: " << value << endl;
}
void dequeue() {
if (isEmpty()) {
cout << "Queue is empty" << endl;
return;
}
cout << "Deleted: " << arr[front] << endl;
front++;
if (front > rear) {
front = rear = -1;
}
}
void display() {
if (isEmpty()) {
cout << "Queue is empty" << endl;
return;
}
cout << "Queue Elements: ";
for (int i = front; i <= rear; i++) {
cout << arr[i] << " ";
}
cout << endl;
}
void peek() {
if (isEmpty()) {
cout << "Queue is Empty" << endl;
return;
}
cout << "Front Element: " << arr[front] << endl;
}
};
int main() {
Queue q;
int choice, value;
while (true) {
cout<< "\n**** Queue Menu ****" << endl;
cout<< "1. ENQUEUE" << endl;
cout<< "2. DEQUEUE" << endl;
cout<< "3. DISPLAY" << endl;
cout<< "4. PEEK" << endl;
cout<< "5. EXIT" << endl;
cout<< "Enter your choice: ";
cin>>choice;
switch (choice) {
case 1:
cout << "Enter value: ";
cin >> value;
q.enqueue(value);
break;
case 2:
q.dequeue();
break;
case 3:
q.display();
break;
case 4:
q.peek();
break;
case 5:
return 0;
default:
cout << "Invalid Choice" << endl;
}
}
return 0;
}
