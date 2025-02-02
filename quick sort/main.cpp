#include <iostream>
using namespace std;

int Partition(int A[], int start, int end)
{ // Fixed array parameter
    int pivot = A[end];
    int pindex = start;
    for (int i = start; i < end; i++)
    { // Fixed loop condition (i < end)
        if (A[i] <= pivot)
        {
            swap(A[i], A[pindex]);
            pindex++;
        }
    }
    swap(A[pindex], A[end]);
    return pindex;
}

void QuickSort(int A[], int start, int end)
{ // Changed return type to void
    if (start < end)
    {
        int pindex = Partition(A, start, end);
        QuickSort(A, start, pindex - 1);
        QuickSort(A, pindex + 1, end);
    }
}

int main()
{
    int A[] = {5, 2, 9, 1, 7, 6, 8};
    int n = sizeof(A) / sizeof(A[0]);
    QuickSort(A, 0, n - 1);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    return 0;
}