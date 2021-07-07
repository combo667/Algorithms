#include <stdio.h>

/* int main(int argc, char const *argv[])
{
    int a = 0;
    printf("INput the value\n");
    scanf("%d", &a);

    switch (a)
    {
    case 1 ... 5:           ...ellipses
        printf("GATE");
        break;
    case 6 ... 8:
        printf("2021");
        break;

    default:
        printf("2022");
        break;
    }
    return 0;
} */


int main(int argc, char const *argv[])
{
    char a = 'a';
    printf("INput the value\n");
    scanf("%c", &a);

    switch (a)
    {
    case 'A' ... 'Z':
        printf("UPPERCASE");
        break;
    case 'a' ... 'z':
        printf("LOWERCASE");
        break;

    default:
        printf("None");
        break;
    }
    return 0;
}
