/* PROGRAM TO MERGE 2 SORTED LISTS
 */

#include <stdio.h>
#include <stdlib.h>

void input(int **, int);
void print_elements(int *, int);
int *merge_lists(int *, int *, int, int);

int main(int argc, char const *argv[])
{

    int *list1 = NULL, *list2 = NULL,*list3=NULL;
    int size1 = 0, size2 = 0;
    printf("Input the size of the list 1 to be created!\n");
    scanf("%d", &size1);
    printf("Input the size of the list 2 to be created!\n");
    scanf("%d", &size2);
    list1 = (int *)malloc(sizeof(int) * size1);
    list2 = (int *)malloc(sizeof(int) * size2);
    printf("Input elemets in list1:\n");
    input(&list1, size1);
    printf("Input elemets in list2:\n");
    input(&list2, size2);


    printf("The merged list is :\n");
    list3=merge_lists(list1,list2,size1,size2);
    print_elements(list3,size1+size2);

    free(list1);
    free(list2);
    free(list3);
    return 0;
}

void input(int **list, int size)
{

    printf("INput the elements:\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", (*list + i));
    }
}

void print_elements(int *list, int n)
{

    for (int i = 0; i < n; i++)
    {
        printf("%d  ", list[i]);
    }
    printf("\n");
}

int *merge_lists(int *list1, int *list2, int m, int n)
{
    int *list3 = NULL;
    int size3 = m + n;
    list3 = (int *)malloc(sizeof(int) * size3);
    int i = 0, j = 0, k = 0;

    while (i < m && j < n)
    {
        if (list1[i] < list2[j])
            list3[k++] = list1[i++];
        else
            list3[k++] = list2[j++];
    }

    for (; i < m; ++i)
        list3[k++] = list1[i];
    for (; j < n; ++j)
        list3[k++] = list2[j];

    return list3;
}