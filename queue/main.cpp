#include <iostream>
using namespace std;

class Queue
{
private:
    int *A;
    int front;
    int rear;
    int MAX_SIZE;

public:
    Queue(int size)
    {
        MAX_SIZE = size;
        A = new int[MAX_SIZE];
        front = -1;
        rear = -1;
    }

    ~Queue()
    {
        delete[] A;
    }

    bool isEmpty()
    {
        return (front == -1 && rear == -1);
    }

    bool isFull()
    {
        return (rear == MAX_SIZE - 1);
    }

    void enqueue(int x)
    {
        if (isFull())
        {
            cout << "Queue is full" << endl;
            return;
        }
        else if (isEmpty())
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear++;
        }
        A[rear] = x;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        else if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front++;
        }
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        for (int i = front; i <= rear; i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    int MAX_SIZE;
    cout << "Enter the size of the queue: ";
    cin >> MAX_SIZE;

    Queue q(MAX_SIZE);

    int choice, value;
    while (true)
    {
        cout << "\nQueue Operations Menu:" << endl;
        cout << "1. Insert (Enqueue)" << endl;
        cout << "2. Delete (Dequeue)" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert: ";
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
            cout << "Exiting program." << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}
