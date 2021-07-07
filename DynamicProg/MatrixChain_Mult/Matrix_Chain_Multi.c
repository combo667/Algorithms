#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void MCM(int, int[]);
void PRINT_OPTIMAL_PARENS(int **S, int, int);
int *input(int);

int main(int argc, char const *argv[])
{
    int no_of_matrices = 0;
    int *Array = NULL;
    printf("Input the number of matrices you got!\n");
    scanf("%d", &no_of_matrices);

    Array = input(no_of_matrices + 1);

    MCM(no_of_matrices + 1, Array);

    free(Array);
    Array = NULL;

    return 0;
}

void MCM(int size, int dim[])
{
    int i = 0, j = 0, length = 0, k = 0;
    int minimum = 0, q = 0;

    int **M = (int **)malloc(sizeof(int *) * (size));
    int **S = (int **)malloc(sizeof(int *) * (size));

    for (i = 0; i < size; i++)
    {
        M[i] = (int *)malloc(sizeof(int) * size);
        S[i] = (int *)malloc(sizeof(int) * size);
    }

    for (i = 0; i < size; i++)
    {
        M[i][i] = 0;
        S[i][i] = 0;
    }

    for (length = 1; length < (size - 1); length++)
    {
        for (i = 1; i < (size - length); i++)
        {
            j = i + length;
            minimum = INT_MAX;
            for (k = i; k <= (j - 1); ++k)
            {
                q = M[i][k] + M[k + 1][j] + (dim[i - 1] * dim[k] * dim[j]);
                if (q < minimum)
                {
                    minimum = q;
                    S[i][j] = k;
                }
            }

            M[i][j] = minimum;
        }
    }

    printf("Minimised Operations Cost is :%d\n", M[1][size - 1]);

    PRINT_OPTIMAL_PARENS(S, 1, (size - 1));

    for (i = 0; i < size; i++)
    {
        free(M[i]);
        free(S[i]);
        M[i] = NULL;
        S[i] = NULL;
    }
    free(M);
    free(S);
    M = NULL;
    S = NULL;
}

void PRINT_OPTIMAL_PARENS(int **S, int i, int j)
{
    if (i == j)
        printf("A%d", i);
    else
    {
        printf("(");
        PRINT_OPTIMAL_PARENS(S, i, S[i][j]);
        PRINT_OPTIMAL_PARENS(S, S[i][j] + 1, j);
        printf(")");
    }
}

int *input(int no_of_matrix)
{
    int x = 0;
    int *array = NULL;
    array = (int *)malloc(sizeof(int) * no_of_matrix);
    printf("Input the dimensions one by one!\n");
    for (x = 0; x < no_of_matrix; x++)
    {
        scanf("%d", &array[x]);
    }

    return array;
}