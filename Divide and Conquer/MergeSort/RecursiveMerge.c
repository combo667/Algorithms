//Recursive Merge Sort!!!

#include <stdio.h>
#define max 50

void merge(int A[], int low, int mid, int high) //2 Way merging is being used
{
    int i = low, j = mid + 1, k = low;

    int B[100];

    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }

    for (; i <= mid; ++i)
        B[k++] = A[i];
    for (; j <= high; ++j)
        B[k++] = A[j];

    for (i = low; i <= high; i++) //copying back the elements from B to A
        A[i] = B[i];
}

void MergeSort(int A[], int low, int high)
{
    int mid = 0;
    if (low < high)
    {
        mid = (low + high) / 2;
        MergeSort(A, low, mid);
        MergeSort(A, mid + 1, high);
        merge(A, low, mid, high);
    }
}

int main(int argc, char const *argv[])
{
    int A[max];
    int n = 0;
    printf("Input the array size!\n");
    scanf("%d", &n);

    printf("Input the elements!\n");
    for (int x = 0; x < n; x++)
    {
        scanf("%d", &A[x]);
    }

    MergeSort(A, 0, n - 1);
    printf("The sorted List is :\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", A[i]);
    }

    return 0;
}
