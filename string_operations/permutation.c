#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void perm(char *str, int l, int r)
{
    if (l == r)
    {
        printf("%s\n", str);
    }
    else
    {
        for (int i = l; i <= r; i++)
        {
            // Swap the characters at positions l and i
            char temp = str[l];
            str[l] = str[i];
            str[i] = temp;

            // Recursively call perm() for the next position
            perm(str, l + 1, r);

            // Backtrack to restore the original string
            temp = str[l];
            str[l] = str[i];
            str[i] = temp;
        }
    }
}

int factorial(int n)
{
    if (n == 0 || n == 1)
        return 1;                // Base case: 0! = 1! = 1
    return n * factorial(n - 1); // Recursive case
}

int main()
{
    char str[] = "ABCD";
    int n = strlen(str);

    int comb = factorial(n);
    printf("All permutations of the string are:\n");
    printf("total number of permutations = %d\n", comb);

    // printf("%d\n",comb);
    perm(str, 0, n - 1);
    return 0;
}