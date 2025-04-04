#include <iostream.h>
#include <conio.h>
#include <stdlib.h>

struct Node {
    int data;
    Node* next;
};

Node* top = NULL;

void push(int value) {
    Node* newNode = new Node();
    if (newNode == NULL) {
        cout << "Stack Overflow" << endl;
        getch();
        exit(1);
    }
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    cout << value << " pushed to stack" << endl;
}

void pop() {
    if (top == NULL) {
        cout << "Stack Underflow" << endl;
        return;
    }
    Node* temp = top;
    top = top->next;
    cout << temp->data << " popped from stack" << endl;
    delete temp;
}

void display() {
    if (top == NULL) {
        cout << "Stack is empty" << endl;
        return;
    }
    Node* temp = top;
    cout << "Stack elements are: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    clrscr();
    push(10);
    push(20);
    push(30);
    display();
    pop();
    display();
    getch();
    return 0;
}