#include <stdio.h>
#include <stdlib.h>

typedef struct HEAP
{
    int *Array;
    int size;
} heap;

void Heapify(int **, int, int);
void print_Array(heap *);
void swap(int *, int *);
int delete_Root(heap **);
heap *create_Heap(int);
void Build_Heap(heap **);

int main(int argc, char const *argv[])
{
    heap *h = NULL;
    int size, element;
    printf("INput the number of elements!\n");
    scanf("%d", &size);

    h = create_Heap(size);

    Build_Heap(&h);

    print_Array(h);

    /* element = delete_Root(&h);
    printf("Deleted Element=%d\n", element); */
    //print_Array(h);

    free(h->Array);
    h->Array = NULL;
    free(h);
    h = NULL;

    return 0;
}

void Heapify(int **array, int i, int size)
{

    int largest = i;
    int left = (2 * i) + 1;
    int right = (2 * i) + 2;

    if (left < size && (*array)[left] > (*array)[largest])
        largest = left;
    if (right < size && (*array)[right] > (*array)[largest])
        largest = right;
    if (largest != i)
    {
        swap(&(*array)[largest], &(*array)[i]);
        Heapify(array, largest, size);
    }
}

void print_Array(heap *h)
{
    printf("The elements are:\n");
    for (int i = 0; i < h->size; i++)
    {
        printf("%d  ", h->Array[i]);
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

int delete_Root(heap **h)
{
    int element = 0;
    swap(&(*h)->Array[0], &(*h)->Array[(*h)->size - 1]);
    element = (*h)->Array[(*h)->size - 1];

    (*h)->size--;
    for (int i = ((*h)->size / 2) - 1; i >= 0; i--)
    {
        Heapify(&(*h)->Array, i, (*h)->size);
    }

    return element;
}

void Build_Heap(heap **h)
{
    int i = ((*h)->size / 2) - 1;

    for (; i >= 0; i--)
    {
        Heapify(&(*h)->Array, i, (*h)->size);
    }
}

heap *create_Heap(int n)
{
    heap *h = (heap *)malloc(sizeof(heap));
    h->Array = (int *)malloc(sizeof(int) * n);
    h->size = n;

    printf("INput the elements!\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &h->Array[i]);
    }

    return h;
}