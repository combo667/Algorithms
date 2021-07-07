#include <stdio.h>

int fun(); //global declaration of function fun

int main(int argc, char const *argv[])
{
    int c = 0;

    int fun(); //local declaration of function

    c = fun();
    return 0;
}

int fun()
{
    return 1;
}
