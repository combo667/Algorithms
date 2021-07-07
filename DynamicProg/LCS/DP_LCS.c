#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 25

void LCS_DP(char *X, char *Y, int, int);
void Deallocate(int **, int);
int max(int, int);

int main(int argc, char const *argv[])
{
    int temp = 0;
    char str1[MAX],str2[MAX];
    printf("Input the first String!\n");
    scanf("%[^\n]%*c", str1);
    printf("Input the second String!\n");
    scanf("%[^\n]%*c", str2);

   LCS_DP(str1, str2, strlen(str1), strlen(str2));

    return 0;
}

void LCS_DP(char *X, char *Y, int m, int n)                         //O(n^2)    polynomial time
{   

    int i = 0, j = 0, temp = 0;
    char *lcs = NULL;
    int count = 0;
    int **DP_TABLE = (int **)malloc(sizeof(int *) * (m + 1));
    for (i = 0; i <= m; i++)                                              // O(m)
    {
        DP_TABLE[i] = (int *)malloc(sizeof(int) * (n + 1));
    }

    for (i = 0; i <= m; i++)                                                 //O(m)
    {
        DP_TABLE[i][0] = 0;
    }
    for (i = 0; i <= n; i++)                                        //O(n)
    {
        DP_TABLE[0][i] = 0;
    }

    for (i = 1; i <= m; i++)                                                         //O(m*n)
    {
        for (j = 1; j <= n; j++)
        {
            if (X[i - 1] == Y[j - 1])
            {

                DP_TABLE[i][j] = 1 + DP_TABLE[i - 1][j - 1];
            }
            else
                DP_TABLE[i][j] = max(DP_TABLE[i][j - 1], DP_TABLE[i - 1][j]);
        }
    }

    temp = DP_TABLE[m][n];
    count = temp;

    lcs = (char *)malloc(sizeof(char) * temp);
    lcs[count] = '\0';

    //Printing the LCS String

    i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (X[i - 1] == Y[j - 1])
        {
            lcs[count - 1] = X[i - 1];
            --i, --j, --count;
        }
        else if (DP_TABLE[i - 1][j] > DP_TABLE[i][j - 1])
            --i;
        else
            --j;
    }

    printf("The Longest Common Subsequence b/t (%s , %s) is %s whose length = %d.\n", X, Y, lcs, temp);

    Deallocate(DP_TABLE, m);
    DP_TABLE = NULL;
}

int max(int x, int y)
{
    return x > y ? x : y;
}

void Deallocate(int **table, int size)
{
    for (int i = 0; i <= size; i++)
    {
        free(table[i]);
        table[i] = NULL;
    }
    free(table);
    table = NULL;
}

