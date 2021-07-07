//FRACTIONAL KNAPSACK PROGRAM

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Item
{
    int item_num;
    double price;
    double weight;
} item;

typedef struct final_item
{
    int item_number;
    int count;
} finalitem;

void input(int, item *);
void print(int, item *);
void frac_greedy_pw(item *, int);
void merge(item[], int, int, int);
void MergeSort(item[], int, int);

int main(int argc, char const *argv[])
{
    int items = 0;

    printf("Input the number of items!\n");
    scanf("%d", &items);
    item *obj = (item *)malloc(sizeof(item) * items);
    input(items, obj);

    MergeSort(obj, 0, items - 1);

    print(items, obj);
    printf("\n");

    frac_greedy_pw(obj, items);

    free(obj);

    return 0;
}

void input(int num, item *object)
{
    printf("Input the items!\n");
    for (int i = 0; i < num; i++)
    {
        printf("ITEM %d:\n", i + 1);
        printf("Input the item number!\n");
        scanf("%d", &object[i].item_num);
        printf("Input the item price!\n");
        scanf("%lf", &object[i].price);
        printf("Input the item Weight!\n");
        scanf("%lf", &object[i].weight);
    }
}

void print(int num, item *obj)
{
    printf("The sorted item list based on Prices is:\n");
    printf("It.No\t\tIt.Price\t\tIt.Wt\n");
    for (int i = 0; i < num; i++)
    {
        printf("%d\t\t %.2lf\t\t\t%.2lf\n", obj[i].item_num, obj[i].price, obj[i].weight);
    }
}

void frac_greedy_pw(item *obj, int num)
{
    int i = 0;
    double weight = 0.0, capacity = 0.0;
    double profit = 0.0;
    printf("Input the capacity of the bag!\n");
    scanf("%lf", &capacity);
    double *temp = (double *)malloc(sizeof(double) * num);

    for (i = 0; i < num; i++)
    {
        temp[i] = 0.0;
    }

    for (i = 0; i < num; i++)
    {
        if ((weight + obj[i].weight) <= capacity)
        {
            temp[i] = 1.0;
            weight = weight + obj[i].weight;
            profit = profit + obj[i].price;
        }
        else
        {
            temp[i] = (double)((capacity - weight) / obj[i].weight);
            weight = capacity;
            profit = (double)(profit + (temp[i] * obj[i].price));
            break;
        }
    }

    printf("The items included are:\n");
    printf("ItemNo\t\tIncluded/Not\t\tProfit\n");
    for (i = 0; i < num; i++)
    {
        printf("%d\t\t%.2lf\t\t\t %.2lf\n", obj[i].item_num, temp[i], (temp[i] * obj[i].price));
    }

    printf("\nNet Profit:   %.2lf\n", profit);

    free(temp);
}

void merge(item A[], int low, int mid, int high) //2 Way merging is being used
{
    int i = low, j = mid + 1, k = low;

    item B[100];

    while (i <= mid && j <= high)
    {
        if (A[i].price > A[j].price)
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

void MergeSort(item A[], int low, int high)
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