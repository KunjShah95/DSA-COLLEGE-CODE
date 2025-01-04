#include <iostream>
using namespace std;

int main()
{
    int a[100];
    int n;

    cout << "Enter the size of the array: ";
    cin >> n;

    cout << "Enter the elements of the sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int p;
    cout << "Enter the element to be searched: ";
    cin >> p;

    int start = 0, end = n - 1;
    int mid;

    while (start <= end)
    {
        mid = start + (end - start) / 2; // Safer midpoint calculation

        if (a[mid] == p)
        {
            cout << "Number found at index " << mid << ": " << p << endl;
            break;
        }
        else if (p < a[mid])
        {
            end = mid - 1; // Search in the left half
        }
        else
        {
            start = mid + 1; // Search in the right half
        }
    }

    return 0;
}
