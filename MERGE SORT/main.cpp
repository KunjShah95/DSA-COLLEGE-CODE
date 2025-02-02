#include <iostream>
using namespace std;

void Merge(int left[], int nL, int right[], int nR, int A[])
{
    int i = 0, j = 0, k = 0;

    // Merging the two sorted halves
    while (i < nL && j < nR)
    {
        if (left[i] <= right[j])
        {
            A[k] = left[i];
            i++;
        }
        else
        {
            A[k] = right[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of left[]
    while (i < nL)
    {
        A[k] = left[i];
        i++;
        k++;
    }

    // Copy remaining elements of right[]
    while (j < nR)
    {
        A[k] = right[j];
        j++;
        k++;
    }
}

void MergeSort(int A[], int n)
{
    if (n < 2)
        return;

    int mid = n / 2;

    // Creating left and right subarrays
    int left[mid];
    int right[n - mid];

    for (int i = 0; i < mid; i++)
        left[i] = A[i];

    for (int i = mid; i < n; i++)
        right[i - mid] = A[i];

    MergeSort(left, mid);
    MergeSort(right, n - mid);
    Merge(left, mid, right, n - mid, A);
}

int main()
{
    int A[] = {12, 101, 113, 5, 6, 7};
    int n = sizeof(A) / sizeof(A[0]);

    MergeSort(A, n);

    cout << "Sorted array is: ";
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    return 0;
}
