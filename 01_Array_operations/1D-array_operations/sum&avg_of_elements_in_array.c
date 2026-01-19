#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int A[10];
    int size;
    int length;
};

void display(struct Array arr)
{
    for (int i = 0; i < arr.length; i++)
        printf("%d -> %d \n", arr.A[i], i);
    printf("\n");
}

int sum(struct Array arr)
{
    int sum = 0;
    for (int i = 0; i < arr.length; i++)
    {
        sum += arr.A[i];
    }
    return sum; // Return the sum instead of printing it
}

float average(struct Array arr)
{
    return (float)sum(arr) / arr.length; // Return the average instead of printing it
}

int main()
{
    struct Array arr = {{2, 4, 6, 8, 9, 12, 15}, 10, 7};
    int totalSum = sum(arr);
    float avg = average(arr); // Correctly call the average function

    printf("Sum: %d\n", totalSum);
    printf("Average: %f\n", avg);

    return 0;
}
