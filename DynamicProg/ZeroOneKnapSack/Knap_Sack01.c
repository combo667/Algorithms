#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Item
{
    int item_num;
    int price;
    int weight;
} item;

typedef struct final_item
{
    int item_number;
    int count;
} finalitem;

int profit = 0;

void input(int, item *);
void print(int, item *);
finalitem *greedy_by_price(int, item *);
void printObjects(int, finalitem *);
int minimum_weight(int, item *);

int main(int argc, char const *argv[])
{
    int items = 0;
    finalitem *fp = NULL;
    printf("Input the number of items!\n");
    scanf("%d", &items);
    item *obj = (item *)malloc(sizeof(item) * items);
    input(items, obj);
    print(items, obj);
    printf("\n");

    fp = greedy_by_price(items, obj);
    printObjects(items, fp);
    printf("\nNet Profit : Rs %d.", profit);

    free(obj);
    free(fp);
    return 0;
}

void input(int num, item *object)
{
    printf("Input the items in sorted order based on Prices!\n");
    for (int i = 0; i < num; i++)
    {
        printf("ITEM %d:\n", i + 1);
        printf("Input the item number!\n");
        scanf("%d", &object[i].item_num);
        printf("Input the item price!\n");
        scanf("%d", &object[i].price);
        printf("Input the item Weight!\n");
        scanf("%d", &object[i].weight);
    }
}

void print(int num, item *obj)
{
    printf("The items are:\n");
    printf("It.No  It.Price    It.Wt\n");
    for (int i = 0; i < num; i++)
    {
        printf("%d.      Rs %d           %d Kg\n", obj[i].item_num, obj[i].price, obj[i].weight);
    }
}

finalitem *greedy_by_price(int num, item *objects)
{
    int capacity = 0, i = 0;

    int min_wt = minimum_weight(num, objects);

    finalitem *final_objects = (finalitem *)malloc(sizeof(finalitem) * num);

    printf("Input the Bag Capacity!\n");
    scanf("%d", &capacity);

    for (int i = 0; i < num; i++)
    {
        final_objects[i].count = 0;
        final_objects[i].item_number = objects[i].item_num;
    }

    while ((capacity >= min_wt) && (i < num))
    {
        if (objects[i].weight <= capacity)
        {
            final_objects[i].count++;
            capacity = capacity - objects[i].weight;
            profit = profit + objects[i].price;
        }
        i++;
    }

    return final_objects;
}

int minimum_weight(int num, item *obj)
{
    int min = INT_MAX;
    int i = 0;
    while (i < num)
    {
        if (obj[i].weight < min)
            min = obj[i].weight;

        ++i;
    }

    return min;
}

void printObjects(int num, finalitem *obj)
{
    int i = 0;
    printf("Items included in the bag are!\n");
    printf("It.No  : ");
    for (i = 0; i < num; i++)
    {
        printf("%d  ", obj[i].item_number);
    }
    printf("\n");
    printf("Count  :");
    for (i = 0; i < num; i++)
    {
        printf("%d   ", obj[i].count);
    }
}
