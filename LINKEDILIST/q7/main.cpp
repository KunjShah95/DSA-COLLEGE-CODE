#include <iostream.h>
#include <conio.h>

// Node structure for the linked list
struct Node {
    int data;
    Node* next;
};

// Function to insert a node at the front of the linked list
void insertAtFront(Node** head, int newData) {
    // Create a new node
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = *head;

    // Move the head to point to the new node
    *head = newNode;
}

// Function to insert a node at the end of the linked list
void insertAtEnd(Node** head, int newData) {
    // Create a new node
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = NULL;

    // If the linked list is empty, then make the new node as head
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    // Else traverse till the last node
    Node* last = *head;
    while (last->next != NULL) {
        last = last->next;
    }

    // Change the next of last node
    last->next = newNode;
}

// Function to insert a node in ascending order
void insertInOrder(Node** head, int newData) {
    // Create a new node
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = NULL;

    // If the list is empty or the new node is smaller than the head, insert at the front
    if (*head == NULL || newData < (*head)->data) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    // Locate the node before the point of insertion
    Node* current = *head;
    while (current->next != NULL && current->next->data < newData) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

// Function to print the linked list
void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;
    clrscr();

    // Insert nodes at the front
    insertAtFront(&head, 3);
    insertAtFront(&head, 1);
    cout << "Linked list after inserting 3 and 1 at the front: ";
    printList(head);

    // Insert nodes at the end
    insertAtEnd(&head, 5);
    insertAtEnd(&head, 7);
    cout << "Linked list after inserting 5 and 7 at the end: ";
    printList(head);

    // Insert nodes in ascending order
    insertInOrder(&head, 4);
    insertInOrder(&head, 2);
    cout << "Linked list after inserting 4 and 2 in ascending order: ";
    printList(head);
    getch();

    return 0;
}