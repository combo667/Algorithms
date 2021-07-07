#include <stdio.h>
int main(int argc, char const *argv[])
{
    int terms = 0;
    int sum = 0;
    int count = 54;
    scanf("%d", &terms);

    for (int i = 1; i <= terms; i++)
    {
        sum += count;
        printf("for i=%2d  sum=%d\n", i, sum);
        count -= 3;
    }

    return 0;
}
