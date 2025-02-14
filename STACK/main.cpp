#include <iostream>
using namespace std;

void push(int a[], int &top)
{
    cout << "Enter the element: ";
    cin >> a[top + 1];
    top++;
}

void pop(int &top)
{
    top--;
}

void peek(int a[], int top)
{
    cout << "The element is: " << a[top] << endl;
}

void change(int a[], int top)
{
    cout << "Enter the element: ";
    cin >> a[top];
}

void display(int a[], int top)
{
    for (int i = 0; i <= top; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
    int a[100], size, top = -1, choice;
    cout << "Enter the size of the stack: ";
    cin >> size;

    for (int i = 0; i < size; i++)
    {
        cout << "Enter the element: ";
        cin >> a[i];
        top++;
    }

    cout << "Enter choice: 1->Push 2->Pop 3->Peek 4->Change: 5->Display 6->Exit: ";
    cin >> choice;

    while (choice != 6)
    {
        switch (choice)
        {
        case 1:
            push(a, top);
            break;
        case 2:
            pop(top);
            break;
        case 3:
            peek(a, top);
            break;
        case 4:
            change(a, top);
            break;
        case 5:
            display(a, top);
            break;
        case 6:
            break;
        default:
            cout << "Invalid choice";
        }

        cout << "Enter choice: 1->Push 2->Pop 3->Peek 4->Change: 5->Display 6->Exit: ";
        cin >> choice;
    }

    return 0;
}