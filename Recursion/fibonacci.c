#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int fibonacci(int n)
{
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int n;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    printf("Fibonacci series:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", fibonacci(i));
    }
    printf("\n");
    return 0;
}
// This program calculates the Fibonacci series using recursion. The user is prompted to enter the number of terms, and the program prints the Fibonacci series up to that number of terms.