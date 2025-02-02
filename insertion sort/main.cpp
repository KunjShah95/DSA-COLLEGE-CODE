#include <iostream>
using namespace std;
void Insertionsort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int value = a[i];
        int x = i;
        while (x > 0 && a[x - 1] > value)
        {
            a[x] = a[x - 1];

            x = x - 1;
        }
        a[x] = value;
    }
}
int main()
{
    int n, a[100];
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    Insertionsort(a, n);
    cout << "The sorted array is: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}
