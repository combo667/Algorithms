#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a[7] = {10, 20, 30, 40, 50};
    void *ptr = NULL; //generic pointer

    ptr = &a[0];

    for (int i = 0; i < 7; i++)
    {
        printf("%d  ", *((int *)ptr + i));
    }

    return 0;
}
