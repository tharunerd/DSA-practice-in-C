#include<stdio.h>
#include<stdlib.h>

int power(int m, int n)
{
    if (n == 0)
        return 1;
    return m * power(m, n - 1);
}   

int pow_n/2 (int m, int n){
    if(n == 0)
        return 1;
    if (n % 2 == 0)
        return pow(m * m, n / 2);
    else
        return m * pow(m * m, (n - 1) / 2);
}

int main()
{
    int m, n;
    printf("Enter the base and exponent: ");
    scanf("%d %d", &m, &n);
    printf("%d^%d = %d\n", m, n, power(m, n));
    printf("%d^%d = %d\n", m, n, pow_n/2(m, n)); // Using the optimized version
    return 0;
}

