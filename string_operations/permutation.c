#include<stdio.h>
#include<string.h>
#include<stdlib.h>


void perm(char *str, int l, int r)
{
    if (l == r) {
        printf("%s\n", str);
    } else {
        for (int i = l; i <= r; i++) {
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
int main()
{
    char str[] = "ABC";
    int n = strlen(str);
    printf("All permutations of the string are:\n");
    perm(str, 0, n - 1);
    return 0;
}