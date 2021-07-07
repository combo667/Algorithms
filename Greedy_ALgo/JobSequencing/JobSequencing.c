/* Example: JOB SCHEDULING GREEDY METHOD

Input 

The Jobs are :
JobName    Job_Dead     Job_Pro
6           2           80
3           6           70
4           6           65
2           5           60
5           4           25
8           2           22
1           4           20
7           2           10

Output:

Job Sequence is :
-> J8  -> J6  -> J5  -> J2  -> J4  -> J3
Net Profit is :322

Input Vector:
1 4 20 2 5 60 3 6 70 4 6 65 5 4 25 6 2 80 7 2 10 8 2 22 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node
{
    int job_num;
    int job_deadline;
    int job_profit;
} node;

void input(node *, int);
void output(node *, int);

void merge(node[], int, int, int);

void MergeSort(node[], int, int);       //O(nlogn)
void JobScheduling(node[], int);    //O(N * M)           //Total Time COmplexity=O(N^2)
int max_deadline(node[], int);
 
int main(int argc, char const *argv[])
{
    int jobs = 0;
    node *array = NULL;
    printf("Input the number of Jobs in Queue!\n");
    scanf("%d", &jobs);
    array = (node *)malloc(sizeof(node) * (jobs + 1));
    input(array, jobs);
    MergeSort(array, 0, jobs - 1);
    output(array, jobs);
    JobScheduling(array, jobs);

    free(array);
    array = NULL;

    return 0;
}

void input(node *array, int jobs)
{
    int i = 0;
    printf("Input the Jobs!\n");
    for (i = 0; i < jobs; i++)
    {
        printf("Input the Job Number!\n");
        scanf("%d", &array[i].job_num);
        printf("Input the Job Deadline!\n");
        scanf("%d", &array[i].job_deadline);
        printf("Input the Job Profit!\n");
        scanf("%d", &array[i].job_profit);
    }
}

void output(node *array, int num)
{
    int i = 0;
    printf("The Jobs are :\n");
    printf("JobNum    Job_Dead     Job_Pro\n");
    for (i = 0; i < num; i++)
    {
        printf("%d           %d           %d\n", array[i].job_num, array[i].job_deadline, array[i].job_profit);
    }
}

void merge(node A[], int low, int mid, int high) //2 Way merging is being used
{
    int i = low, j = mid + 1, k = low;

    node B[100];

    while (i <= mid && j <= high)
    {
        if (A[i].job_profit > A[j].job_profit)
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

void MergeSort(node A[], int low, int high)
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

int max_deadline(node Array[], int num)
{
    int max = INT_MIN;
    for (int i = 0; i < num; i++)
    {
        if (Array[i].job_deadline > max)
            max = Array[i].job_deadline;
    }
    return max;
}

void JobScheduling(node Array[], int num)
{
    int max_dead = max_deadline(Array, num);

    int i = 0, j = 0;
    int profit = 0;

    int *solution = (int *)malloc(sizeof(int) * (max_dead + 1));

    for (i = 0; i <= max_dead; i++)
    {
        solution[i] = -1;
    }

    for (i = 0; i < num; i++)
    {
        if ((solution[Array[i].job_deadline]) == -1)
        {
            solution[Array[i].job_deadline] = Array[i].job_num;
            profit = profit + Array[i].job_profit;
        }
        else
        {
            j = Array[i].job_deadline;
            while (j > 0 && (solution[j] > -1))
            {
                --j;
            }
            if (j > 0)
            {
                solution[j] = Array[i].job_num;
                profit = profit + Array[i].job_profit;
            }
        }
    }

    printf("\nJob Sequence is :\n");
    for (i = 1; i <= max_dead; i++)
    {
        if (solution[i] > -1)
            printf("-> J%d  ", solution[i]);
    }
    printf("\nNet Profit is :%d\n", profit);

    free(solution);
    solution = NULL;
}
