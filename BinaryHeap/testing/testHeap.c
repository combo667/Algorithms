#include <stdio.h>
#include <stdlib.h>
#define max 10

int size = 0;

void Heapify(int[], int, int);
void insert(int[], int);
void print_Array(int[]);
void swap(int*, int*);
int delete_Root(int[]);

int main(int argc, char const *argv[])
{
    int array[max];
    int element;

    insert(array, 10);
    insert(array, 20);
    insert(array, 30);
    insert(array, 40);
    insert(array, 50);
    insert(array, 60);
    insert(array, 70);

    print_Array(array);

    element = delete_Root(array);
    printf("Deleted element is :%d\n", element);
    element = delete_Root(array);
    printf("Deleted element is :%d\n", element);

    print_Array(array);

    return 0;
}

void Heapify(int array[], int i, int n)
{

    int largest = i;
    int left = (2 * i) + 1;
    int right = (2 * i) + 2;

    if (left < n && array[left] > array[largest])
        largest = left;
    if (right < n && array[right] > array[largest])
        largest = right;
    if (largest != i)
    {
        swap(&array[largest], &array[i]);
        Heapify(array, n, largest);
    }
}

void insert(int array[], int element)
{
    if (size == 0)
    {
        array[0] = element;
        size++;
    }
    else
    {
        array[size] = element;
        size++;
        for (int i = (size / 2) - 1; i >= 0; i--)
        {
            Heapify(array, i, size);
        }
    }
}

void print_Array(int array[])
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

int delete_Root(int array[])
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
