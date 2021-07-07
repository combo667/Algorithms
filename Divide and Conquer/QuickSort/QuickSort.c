#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

void Swap(int *, int *);
int Partition(int[], int, int);
void QuickSort(int[], int, int);
void PrintArray(int[], int);
int *input(int);

int main(int argc, char const *argv[])
{
    int size = 0, *Array = NULL;
    printf("Input the size of the Array to be Created!\n");
    scanf("%d", &size);
    Array = input(size);
    QuickSort(Array, 0, size);
    PrintArray(Array, size);
    free(Array);
    Array = NULL;

    return 0;
}

void Swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int Partition(int Array[], int low, int high)
{
    int pivot = Array[low];
    int i = low;
    int j = high;

    while (i < j)
    {
        do
        {
            ++i;

        } while (Array[i] <= pivot);

        do
        {
            --j;
        } while (Array[j] > pivot);

        if (i < j)
            Swap(&Array[i], &Array[j]);
    }

    Swap(&Array[low], &Array[j]);

    return j;
}

void QuickSort(int Array[], int low, int high)
{

    int j = 0;
    if (low < high)
    {
        j = Partition(Array, low, high);
        QuickSort(Array, low, j);
        QuickSort(Array, j + 1, high);
    }
}

void PrintArray(int Array[], int size)
{
    printf("The Sorted List is :\n");

    for (int i = 0; i < size; i++)
    {
        printf("%d  ", Array[i]);
    }

    printf("\n");
}

int *input(int size)
{
    int *array = NULL;
    array = (int *)malloc(sizeof(int) * size + 1);
    array[size] = INT_MAX;

    printf("Input the elements one by one!\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &array[i]);
    }

    return array;
}