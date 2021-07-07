#include <stdio.h>

void print_Using_4_Loops(int (*)[][2][2]);
void print_Using_1_Loop(int (*)[][2][2]);

int main(int argc, char const *argv[])
{

    int B[2][2][2][2] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};

    print_Using_1_Loop(&B[0]);
    return 0;
}

void print_Using_4_Loops(int (*ptr)[2][2][2])
{

    for (int l = 0; l < 2; l++)
    {
        for (int k = 0; k < 2; k++)
        {
            for (int j = 0; j < 2; j++)
            {
                for (int i = 0; i < 2; i++)
                {
                    //printf("%d  ", ptr[l][k][j][i]);      //Easy Way
                    printf("%d ", *(*(*(*(ptr + l) + k) + j) + i)); //Alternate Way
                }
                printf("\n");
            }
            printf("---------------------\n");
        }

        printf("XXXXXXXXXXXXXXXXXXXXXXXXXX\n");
    }
}

void print_Using_1_Loop(int (*ptr)[2][2][2])
{

    for (int i = 0; i < 16; i++)
    {
        printf("%d  ", *((*(*(*ptr))) + i));
    }
}


