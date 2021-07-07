#include <stdio.h>
#include <stdlib.h>

void Heapify(int[], int, int);
void print_Array(int[],int);
void swap(int *, int *);
int delete_Root(int[],int);
void Build_Heap(int **, int);

int main(int argc, char const *argv[])
{
    int *Array = NULL;
    int i = 0, element = 0;
    int size = 0;

    printf("Input the size of the array!\n");
    scanf("%d", &size);

    Array = (int *)malloc(sizeof(int) * size);

    printf("Input the elements one by one !\n");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &Array[i]);
    }

    Build_Heap(&Array, size);

    print_Array(Array, size);

    element = delete_Root(Array, size);
    printf("Deleted element=%d\n", element);

    print_Array(Array, size);

    return 0;
}

void Heapify(int array[], int i, int size)
{

    int largest = i;
    int left = (2 * i) + 1;
    int right = (2 * i) + 2;

    if (left < size && array[left] > array[largest])
        largest = left;
    if (right < size && array[right] > array[largest])
        largest = right;
    if (largest != i)
    {
        swap(&array[largest], &array[i]);
        Heapify(array, size, largest);
    }
}

void print_Array(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d  ", array[i]);
    }
    printf("\n");
}

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int delete_Root(int array[], int size)
{
    int element = 0;
    swap(&array[0], &array[size - 1]);
    element = array[size - 1];

    size -= 1;
    for (int i = (size / 2) - 1; i >= 0; i--)
    {
        Heapify(array, i, size);
    }

    return element;
}

void Build_Heap(int **Array, int size)
{
    int i = (size / 2) - 1;

    for (; i >= 0; i--)
    {
        Heapify(*Array, i, size);
    }
}