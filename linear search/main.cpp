#include <iostream>
using namespace std;

int main()
{
    int a[100]; // assuming a maximum size of 100
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int start = 0;
    int end = n - 1;
    int p;
    cout << "Enter the element to be searched: ";
    cin >> p;

    for (int i = 0; i < n; i++)
    {
        if (p == a[i])
        {
<<<<<<< HEAD
            cout << "Number found:  " << p << endl;
            return start;
=======
            cout << "Number found at index " << i << ": " << p << endl;
>>>>>>> 58175d6e46e2f4a0bbc3b5005298b24ff5a63857
            break;
        }
        else
        {
            start++;
        }
    }
    return 0;
}
