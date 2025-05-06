#include<stdio.h>
#include<stdlib.h>

struct Array
{
    int A[10];
    int size;
    int length;
};

// just the arr as parameter
void display(struct Array arr)
{
    for (int i = 0; i < arr.length; i++)
        printf("%d -> %d \n", arr.A[i], i);
    printf("\n");
}

// chech if the array is sorted or not
void check_sorted(struct Array arr)
{
    for (int i = 0; i < arr.length - 1; i++)
    {
        if (arr.A[i] > arr.A[i + 1])
        {
            printf("Array is not sorted\n");
            return;
        }
    }
    printf("Array is sorted\n");
}

void union(struct Array arr1, struct Array arr2)
{
    int i = 0, j = 0, k = 0;
    struct Array arr3;
    arr3.size = arr1.size + arr2.size;
    arr3.length = 0;

    while (i < arr1.length && j < arr2.length)
    {
        if (arr1.A[i] < arr2.A[j])
            arr3.A[k++] = arr1.A[i++];
        else if (arr1.A[i] > arr2.A[j])
            arr3.A[k++] = arr2.A[j++];
        else
        {
            arr3.A[k++] = arr1.A[i++];
            j++;
        }
    }

    for (; i < arr1.length; i++)
        arr3.A[k++] = arr1.A[i];

    for (; j < arr2.length; j++)
        arr3.A[k++] = arr2.A[j];

    arr3.length = k;
    display(arr3);
}