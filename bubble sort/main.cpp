#include <iostream>
using namespace std;
int main()
{
    int a[100];
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int k = 0; k < n; k++)
    {
        int flag = 0;
        for (int i = 0; i < n - k - 1; i++)
        {
            if (a[i] > a[i + 1])
            {
                swap(a[i], a[i + 1]);
                flag = 1;
            }
        }
        if (flag == 0)
        {
            break;
        }
    }
    cout << "The sorted array is: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}