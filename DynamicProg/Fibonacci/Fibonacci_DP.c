//Fibonacci Implementation using Bottom Up Approach Dp
#include <stdio.h>
#include <stdlib.h>

int Fib_DP(int);

int main(int argc, char const *argv[])
{
    int n = 0;
    printf("Fibonacci Series!\n");
    printf("0,1,1,2,3,5,8,21,......\n");
    printf("Input the term that You wish to calculate!\n");
    scanf("%d", &n);
    printf("The %d Term is %d .\n", n, Fib_DP(n));
    return 0;
}

int Fib_DP(int n)
{
    int i = 0;
    int temp = 0;
    int *Fib_Table = (int *)calloc(n, sizeof(int));
    Fib_Table[0] = 0;
    Fib_Table[1] = 1;

    for (i = 2; i <= n; i++)        //O(n) time
    {
        Fib_Table[i] = Fib_Table[i - 1] + Fib_Table[i - 2];
    }

    temp = Fib_Table[n];

    free(Fib_Table);
    Fib_Table = NULL;

    return temp;
}
