#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int sum(int n)
{
    if (n == 0)
        return 0;
    return n + sum(n - 1);
}

int factorial(int n)
{
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}

double power(double x, int n)
{
    if (n == 0)
        return 1;
    return x * power(x, n - 1);
}

double taylor_series(double x, int n)
{
    if (n == 0)
        return 1;
    return power(x, n) / factorial(n) + taylor_series(x, n - 1);
}

int main()
{
    double x;
    int n;
    printf("Enter the value of x: ");
    scanf("%lf", &x);
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    double result = taylor_series(x, n);
    printf("The value of e^%.2lf using Taylor series is: %.5lf\n", x, result);
    return 0;
}
// This program calculates the value of e^x using the Taylor series expansion. The user is prompted to enter the value of x and the number of terms to be used in the series. The program then computes and prints the result.