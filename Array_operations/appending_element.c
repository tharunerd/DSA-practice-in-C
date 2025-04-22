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

void append(struct Array *arr, int value)
{
    if (arr->length < arr->size)
    {
        arr->A[arr->length++] = value;
    }
}

int main()
{

    struct Array arr = {{1, 2, 3, 4, 5, 6}, 10, 6};

    display(arr);
    append(&arr, 7);
    display(arr);
}