#include <iostream>
#include <conio.h>

// Node structure for the doubly linked list
struct Node {
    int data;
    Node* next;
    Node* prev;
};

// Function to insert a node at the front of the doubly linked list
void insertAtFront(Node** head, int newData) {
    // Allocate memory for new node
    Node* newNode = new Node();

    // Assign data to new node
    newNode->data = newData;

    // Make next of new node as head and previous as NULL
    newNode->next = (*head);
    newNode->prev = NULL;

    // Change prev of head node to new node
    if ((*head) != NULL)
        (*head)->prev = newNode;

    // Move the head to point to the new node
    (*head) = newNode;
}

// Function to insert a node at the end of the doubly linked list
void insertAtEnd(Node** head, int newData) {
    // Allocate memory for new node
    Node* newNode = new Node();

    // Assign data to new node
    newNode->data = newData;

    // Make next of new node as NULL
    newNode->next = NULL;

    // If the linked list is empty, then make the new node as head
    if (*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }

    // Else traverse till the last node
    Node* last = *head;
    while (last->next != NULL)
        last = last->next;

    // Change the next of last node
    last->next = newNode;

    // Make last node as previous of new node
    newNode->prev = last;
}

// Function to print the doubly linked list
void printList(Node* node) {
    Node* last;
    cout << "\nTraversal in forward direction \n";
    while (node != NULL) {
        cout << " " << node->data << " ";
        last = node;
        node = node->next;
    }

    cout << "\nTraversal in reverse direction \n";
    while (last != NULL) {
        cout << " " << last->data << " ";
        last = last->prev;
    }
}

// Driver program to test above functions
int main() {
    Node* head = NULL;
    clrscr();

    // Insert nodes at the front
    insertAtFront(&head, 7);

    // Insert node at the end.
    insertAtEnd(&head, 6);

    // Insert node at the front.
    insertAtFront(&head, 1);

    // Insert node at the end.
    insertAtEnd(&head, 4);

    cout << "Created DLL is: ";
    printList(head);

    getch();
    return 0;
}