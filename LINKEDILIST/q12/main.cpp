#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* front = NULL;
Node* rear = NULL;

void enqueue(int value) {
    Node* newNode = new Node();
    if (newNode == NULL) {
        cout << "Queue Overflow" << endl;
        getch();
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    if (rear == NULL) {
        front = newNode;
        rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    cout << value << " enqueued to queue" << endl;
}

void dequeue() {
    if (front == NULL) {
        cout << "Queue Underflow" << endl;
        return;
    }
    Node* temp = front;
    front = front->next;
    if (front == NULL) {
        rear = NULL;
    }
    cout << temp->data << " dequeued from queue" << endl;
    delete temp;
}

void display() {
    if (front == NULL) {
        cout << "Queue is empty" << endl;
        return;
    }
    Node* temp = front;
    cout << "Queue elements are: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    clrscr();
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    dequeue();
    display();
    getch();
    return 0;
}