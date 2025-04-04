#include <iostream.h>
#include <conio.h>

// Node structure for the linked list
struct Node {
    int data;
    Node* next;
};

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

// Function to delete the first node of the linked list
void deleteFirstNode(Node** head) {
    if (*head == NULL) {
        cout << "List is empty. Cannot delete." << endl;
        return;
    }

    Node* temp = *head;
    *head = (*head)->next;
    delete temp;
    cout << "First node deleted." << endl;
}

// Function to delete a node before a specified position
void deleteBeforePosition(Node** head, int position) {
    if (*head == NULL) {
        cout << "List is empty. Cannot delete." << endl;
        return;
    }

    if (position <= 1) {
        cout << "Cannot delete before the first position." << endl;
        return;
    }

    if (position == 2) {
        deleteFirstNode(head);
        return;
    }

    Node* current = *head;
    Node* previous = NULL;
    int count = 1;

    while (current != NULL && count < position - 1) {
        previous = current;
        current = current->next;
        count++;
    }

    if (current == NULL || current->next == NULL) {
        cout << "Position is out of range." << endl;
        return;
    }

    Node* temp = current->next;
    current->next = current->next->next;
    delete temp;

    cout << "Node before position " << position << " deleted." << endl;
}

// Function to delete a node after a specified position
void deleteAfterPosition(Node** head, int position) {
    if (*head == NULL) {
        cout << "List is empty. Cannot delete." << endl;
        return;
    }

    Node* current = *head;
    int count = 1;

    while (current != NULL && count < position) {
        current = current->next;
        count++;
    }

    if (current == NULL || current->next == NULL) {
        cout << "Position is out of range or no node after the specified position." << endl;
        return;
    }

    Node* temp = current->next;
    current->next = current->next->next;
    delete temp;

    cout << "Node after position " << position << " deleted." << endl;
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

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);

    cout << "Linked list: ";
    printList(head);

    deleteFirstNode(&head);
    cout << "Linked list after deleting the first node: ";
    printList(head);

    deleteBeforePosition(&head, 3);
    cout << "Linked list after deleting the node before position 3: ";
    printList(head);

    deleteAfterPosition(&head, 2);
    cout << "Linked list after deleting the node after position 2: ";
    printList(head);

    getch();
    return 0;
}