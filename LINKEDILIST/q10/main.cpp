#include <iostream>
#include <conio.h>

// Node structure for the doubly linked list
struct Node {
    int data;
    Node* next;
    Node* prev;
};

// Function to insert a node at the end of the doubly linked list
void insertAtEnd(Node** head, int newData) {
    // Allocate memory for new node
    Node* newNode = new Node();
    newNode->data = newData;
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

// Function to delete the last node of the doubly linked list
void deleteLastNode(Node** head) {
    // If list is empty
    if (*head == NULL) {
        cout << "List is empty. Cannot delete." << endl;
        return;
    }

    // If only one node is present
    if ((*head)->next == NULL) {
        delete *head;
        *head = NULL;
        return;
    }

    // Find the last node
    Node* last = *head;
    while (last->next != NULL) {
        last = last->next;
    }

    // Change the next of the second last node to NULL
    last->prev->next = NULL;

    // Free the memory of the last node
    delete last;
}

// Function to delete a node before a specified position
void deleteBeforePosition(Node** head, int position) {
    // If list is empty
    if (*head == NULL) {
        cout << "List is empty. Cannot delete." << endl;
        return;
    }

    // If position is invalid
    if (position <= 1) {
        cout << "Cannot delete before the first position." << endl;
        return;
    }

    // If there is only one node
    if ((*head)->next == NULL) {
        cout << "There is no node before the first position." << endl;
        return;
    }

    // If we want to delete before the second node, we delete the first node
    if (position == 2) {
        Node* temp = *head;
        *head = (*head)->next;
        (*head)->prev = NULL;
        delete temp;
        cout << "Node before position " << position << " deleted." << endl;
        return;
    }

    Node* current = *head;
    int count = 1;

    // Traverse to the node at the specified position
    while (current != NULL && count < position) {
        current = current->next;
        count++;
    }

    // If position is out of range
    if (current == NULL) {
        cout << "Position is out of range." << endl;
        return;
    }

    // Delete the node before the current node
    Node* temp = current->prev->prev;
    temp->next = current;
    delete current->prev;
    current->prev = temp;

    cout << "Node before position " << position << " deleted." << endl;
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

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);

    cout << "Created DLL is: ";
    printList(head);

    deleteLastNode(&head);
    cout << "\nDoubly linked list after deleting last node: ";
    printList(head);

    deleteBeforePosition(&head, 3);
    cout << "\nDoubly linked list after deleting node before position 3: ";
    printList(head);

    getch();
    return 0;
}