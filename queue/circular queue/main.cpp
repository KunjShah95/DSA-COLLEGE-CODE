#include <iostream>
using namespace std;

int *A, N;
int f = -1, r = -1;

void Enqueue(int x)
{
    if ((r + 1) % N == f)
    {
        cout << "Queue is full" << endl;
        return;
    }
    else if (f == -1 && r == -1)
    {
        f = 0;
        r = 0;
    }
    else
    {
        r = (r + 1) % N;
    }
    A[r] = x;
    cout << x << " enqueued" << endl;
}

void Dequeue()
{
    if (f == -1)
    {
        cout << "Queue is empty" << endl;
        return;
    }
    cout << A[f] << " dequeued" << endl;

    if (f == r)
    {
        f = -1;
        r = -1;
    }
    else
    {
        f = (f + 1) % N;
    }
}

void Display()
{
    if (f == -1)
    {
        cout << "Queue is empty" << endl;
        return;
    }
    cout << "Queue elements: ";
    int i = f;
    while (true)
    {
        cout << A[i] << " ";
        if (i == r)
            break;
        i = (i + 1) % N;
    }
    cout << endl;
}

int main()
{
    cout << "Enter the size of the queue: ";
    cin >> N;
    A = new int[N];

    int choice, x;
    while (true)
    {
        cout << "\nEnter choice: 1->Enqueue 2->Dequeue 3->Display 4->Exit: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> x;
            Enqueue(x);
            break;
        case 2:
            Dequeue();
            break;
        case 3:
            Display();
            break;
        case 4:
            cout << "Exiting..." << endl;
            delete[] A;
            return 0;
        default:
            cout << "Invalid choice, try again!" << endl;
        }
    }
}
