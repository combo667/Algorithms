#include <stdio.h>

int main(int argc, char const *argv[])
{
    int num;
    int i;
    printf("INput the multiplicand!\n");
    scanf("%d", &num);

    printf("The Table is :\n");

    for (int i = 1; i <= 100; i++)
    {
        printf("%d  *   %3d  =   %3d\n", num, i, i * num);
    }
    printf("\n");
    return 0;
}
