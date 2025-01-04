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

    int p;
    cout << "Enter the element to be searched: ";
    cin >> p;

    bool found = false; // Flag to indicate if the element is found
    for (int i = 0; i < n; i++)
    {
        if (p == a[i])
        {
            cout << "Number found at index " << i << ": " << p << endl;
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Number not found in the array." << endl;
    }

    return 0;
}
