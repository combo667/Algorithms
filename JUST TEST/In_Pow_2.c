/*

 Whether a positive number can be represented in powers of 2 or not.
Suppose  input = 32     Yes     2^5
Suppose input = 30  No

 */

#include <stdio.h>

void powers_of_2(int);

int main(int argc, char const *argv[])
{
    int num = 0;
    printf("Input any positive Number!\n");
    scanf("%d", &num);

    (num > 0) ? powers_of_2(num) : printf("Input must be a positive number!\n");

    return 0;
}

void powers_of_2(int num)
{
    (((num) & (num - 1)) == 0) ? printf("YES !\n") : printf("NO !\n");
}
