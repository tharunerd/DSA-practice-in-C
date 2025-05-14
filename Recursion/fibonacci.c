#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int fibonacci(int n)
{
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

double fibonacci_double_without_recursion(double n){
    double result = 0;
    double a = 0, b = 1;
    for (int i = 0; i < n; i++) {
        result = a;
        a = b;
        b = result + b;
    }
    return result;
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

    factorial_double_without_recursion(5);
    printf("Fibonacci series without recursion:\n");
}
// This program calculates the Fibonacci series using recursion. The user is prompted to enter the number of terms, and the program prints the Fibonacci series up to that number of terms.