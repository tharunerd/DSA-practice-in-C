#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int A[20];
    int size;
    int length;
};

void display(struct Array arr)
{
    for (int i = 0; i < arr.length; i++)
        printf("%d ", arr.A[i]);
    printf("\n");
}

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

void set_union(struct Array arr1, struct Array arr2)
{
    int i = 0, j = 0, k = 0;
    struct Array arr3 = {{0}, arr1.size + arr2.size, 0};

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

void intersection(struct Array arr1, struct Array arr2)
{
    int i = 0, j = 0, k = 0;
    struct Array arr3 = {{0}, arr1.size + arr2.size, 0};

    while (i < arr1.length && j < arr2.length)
    {
        if (arr1.A[i] < arr2.A[j])
            i++;
        else if (arr1.A[i] > arr2.A[j])
            j++;
        else
        {
            arr3.A[k++] = arr1.A[i++];
            j++;
        }
    }

    arr3.length = k;
    display(arr3);
}

void difference(struct Array arr1, struct Array arr2)
{
    int i = 0, j = 0, k = 0;
    struct Array arr3 = {{0}, arr1.size + arr2.size, 0};

    while (i < arr1.length && j < arr2.length)
    {
        if (arr1.A[i] < arr2.A[j])
            arr3.A[k++] = arr1.A[i++];
        else if (arr1.A[i] > arr2.A[j])
            j++;
        else
        {
            i++;
            j++;
        }
    }

    for (; i < arr1.length; i++)
        arr3.A[k++] = arr1.A[i];

    arr3.length = k;
    display(arr3);
}

void symmetric_difference(struct Array arr1, struct Array arr2)
{
    int i = 0, j = 0, k = 0;
    struct Array arr3 = {{0}, arr1.size + arr2.size, 0};

    while (i < arr1.length && j < arr2.length)
    {
        if (arr1.A[i] < arr2.A[j])
            arr3.A[k++] = arr1.A[i++];
        else if (arr1.A[i] > arr2.A[j])
            arr3.A[k++] = arr2.A[j++];
        else
        {
            i++;
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

int main()
{
    struct Array arr1 = {{2, 3, 4, 5, 6}, 20, 5};
    struct Array arr2 = {{3, 4, 5, 6, 7}, 20, 5};

    printf("Array 1:\n");
    display(arr1);
    printf("Array 2:\n");
    display(arr2);

    check_sorted(arr1);
    check_sorted(arr2);

    printf("Union:\n");
    set_union(arr1, arr2);

    printf("Intersection:\n");
    intersection(arr1, arr2);

    printf("Difference:\n");
    difference(arr1, arr2);

    printf("Symmetric Difference:\n");
    symmetric_difference(arr1, arr2);

    return 0;
}