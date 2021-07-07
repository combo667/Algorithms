
/* 

5:  00000101
1's complement of 5 : 11111010
computer understands this as 2's comp as the first bit is 1
also computer understands that the number is a -ve number
so computer does its 2's comp again

2's(11111010)   =  00000110 =  -6

 */


#include <stdio.h>
int main(int argc, char const *argv[])
{
    int x = 5;          
    int y = ~x;
    printf("%d", y);
    return 0;
}
