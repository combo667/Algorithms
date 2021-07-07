#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int min = INT_MAX;
int max = INT_MIN;

void find_MinMax(int array[], int low, int high);
void input(int *, int);

int main(int argc, char const *argv[])
{
    int *array = NULL;
    int size;

    printf("Input the size of the Array !\n");
    scanf("%d", &size);

    array = (int *)malloc(sizeof(int) * size);

    input(array, size);

    find_MinMax(array, 0, size - 1);

    printf("Maximum Element = %d\nMinimum Element = %d\n", max, min);

    free(array);
    array = NULL;

    return 0;
}

void find_MinMax(int array[], int low, int high)
{
    int local_min = INT_MAX;
    int local_max = INT_MIN;

    if (low == high) //if array has only 1 element
        max = min = array[low];
    else if (high - low == 1) //if array has 2 elements only
    {
        if (array[low] < array[high])
        {
            max = array[high];
            min = array[low];
        }
        else
        {
            max = array[low];
            min = array[high];
        }
    }

    else
    {
        int mid = (high + low) / 2;

        find_MinMax(array, low, mid);

        local_max = max;
        local_min = min;

        find_MinMax(array, mid + 1, high);
    }

    if (local_min < min)
        min = local_min;
    if (local_max > max)
        max = local_max;
}

void input(int *array, int size)
{
    printf("Input the elements!\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &array[i]);
    }
}