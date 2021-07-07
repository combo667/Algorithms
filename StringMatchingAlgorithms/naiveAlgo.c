//NAIVE'S ALGORITHM 


/* Input the Text!
hellojubeshhowareyoujubesh
Input the pattern!
jubesh
Searching Done!
Pattern Occurs at shift 5.
Pattern Occurs at shift 20. */

#include <stdio.h>
#include <string.h>
#define max 50

int main(int argc, char const *argv[])
{
    char text[max];
    char pattern[max / 2];
    int i = 0, j = 0, m = 0, n = 0, p = 0, alpha = 0, flag = 0;

    printf("Input the Text!\n");
    scanf("%s", text);
    printf("Input the pattern!\n");
    scanf("%s", pattern);
    m = strlen(text);
    n = strlen(pattern);
    printf("Searching Done!\n");
    alpha = m - n + 1;

    for (i = 0; i < alpha; i++) //runs for O(m-n+1)
    {
        p = i;
        while (j < n && (text[p] == pattern[j]))
        {
            p++, j++;
        }
        //runs for O(n) ,which is pattern size

        if (j == n)
            flag = printf("Pattern Occurs at shift %d.\n", i);

        j = 0;
    } //Time Complexity = O((m-n+1)n)

    if (flag == 0)
        printf("No matching pattern found!\n");
    return 0;
}
