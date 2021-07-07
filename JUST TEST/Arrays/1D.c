#include <stdio.h>

void print(int *);

int main(int argc, char const *argv[])
{
    int b[5] = {10, 20, 30, 40, 50};

    int B[][3] = {1, 2, 3, 4, 5, 6};

    print(b);

    return 0;
}

void print(int *ptr)
{
    for (int i = 0; i < 5; i++)
    {
        printf("%d  ", *(ptr + i));
    }
    printf("\n");
}
