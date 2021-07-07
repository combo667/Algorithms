#include <stdio.h>

int main(int argc, char const *argv[])
{
    int b[5] = {10, 20, 30, 40, 50};            //1D Array
    int a[2][3] = {{10, 20, 30}, {40, 50, 60}}; //2D Array

    printf("1D Array\n");
    printf("address of &b=%u\n", &b);
    printf("address of &b+1=%u\n", &b+1);
    printf("simply b  represents address=%u\n", b);
    printf("simply b+1  represents address=%u\n", b + 1);
    printf("address of &b[0]=%u\n", &b[0]);
    printf("This represents the value ! i.e b[0]=%u\n", b[0]);

    printf("\n\n2D Array\n");
    printf("address of &a=%u\n", &a);
    printf("address of &a+1=%u\n", &a+1);
    printf("address of a=%u\n", a);
    printf("address of a+1=%u\n", a+1);
    printf("address of a+2=%u\n", a+2);
    printf("simply a[0]  represents address=%u\n", a[0]);
    printf("simply a[0]+1  represents address=%u\n", a[0]+1);
    printf("address of &a[0]=%u\n", &a[0]);
    printf("address of &a[0]+1=%u\n", &a[0]+1);
    printf("address of &a[0][0]=%u\n", &a[0][0]);
    printf("address of &a[0][0]+1=%u\n", &a[0][0]+1);
    printf("This represents the value ! i.e  a[0][0]=%u\n", a[0][0]);
    return 0;
}
