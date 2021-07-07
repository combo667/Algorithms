#include <stdio.h>

void print_Using_1_Loop(int (*)[3][2]);
void print_Using_3_Loops(int (*ptr)[3][2]);

int main(int argc, char const *argv[])
{
    int a[2][3][2] = {{{10, 20}, {30, 40}, {50, 60}}, {{70, 80}, {90, 100}, {110, 120}}};

    print_Using_3_Loops(&a[0]);
    return 0;
}

void print_Using_1_Loop(int (*ptr)[3][2])
{
    for (int i = 0; i < 12; i++)
    {
        printf("%d  ", *((*(*ptr)) + i));
    }
    printf("\n");
}

void print_Using_3_Loops(int (*ptr)[3][2])
{
    for (int k = 0; k < 2; k++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int i = 0; i < 2; i++)
            {
                //printf("%d  ", ptr[k][j][i]);     //trivial way
                printf("%d  ", *(*(*(ptr + k) + j) + i));   //same thing using pointers
            }
            printf("\n");
        }

        printf("-------------------------\n");
    }

    printf("\n");
}
