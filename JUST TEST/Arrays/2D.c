#include <stdio.h>

void print_Using_2_Loops(int (*)[]);
void print_Using_1_Loop(int (*)[]);

int main(int argc, char const *argv[])
{

    int B[][3] = {1, 2, 3, 4, 5, 6};

    print_Using_1_Loop(&B[0]);
    return 0;
}

void print_Using_2_Loops(int (*ptr)[3])
{

    for (int j = 0; j < 2; j++)
    {
        for (int i = 0; i < 3; i++)
        {
            //printf("%d  ", ptr[j][i]);    //alteranate easy way
            printf("%d  ", *(*(ptr + j) + i)); //same thing using pointers
        }
        printf("\n");
    }
}

void print_Using_1_Loop(int (*ptr)[3])
{

    for (int i = 0; i < 6; i++)
    {
        printf("%d  ", *((*ptr) + i));
    }
}
