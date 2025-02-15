#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

struct node *Head;

void insert(int);
void print();

int main()
{
    Head = NULL;
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    print();

    return 0;
}

void insert(int x)
{
    struct node *t = new node; // Using 'new' instead of malloc
    t->data = x;
    t->next = Head;
    Head = t;
}

void print()
{
    struct node *t = Head;
    cout << "List is: ";
    while (t != NULL)
    {
        cout << t->data << " ";
        t = t->next;
    }
    cout << endl;
}
