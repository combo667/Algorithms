#include <stdio.h>

int main(int argc, char const *argv[])
{
    int rows, cols;
    int i, j;
    printf("Input number of rows!\n");
    scanf("%d", &rows);
    printf("Input number of cols!\n");
    scanf("%d", &cols);

    for (i = 0; i < rows; i++)
    {
        for (j = 1; j <= (rows - i); j++)
        {
            printf(" * ");
        }
        printf("\n");
    }

    return 0;
}
