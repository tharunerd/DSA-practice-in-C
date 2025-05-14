#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void TOH(int n, char source, char target, char auxiliary)
{
    if (n == 1)
    {
        printf("Move disk 1 from %c to %c\n", source, target);
        return;
    }
    TOH(n - 1, source, auxiliary, target);
    printf("Move disk %d from %c to %c\n", n, source, target);
    TOH(n - 1, auxiliary, target, source);
}

int main()
{
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    TOH(n, 'A', 'C', 'B'); // A, B and C are names of rods
    return 0;
}