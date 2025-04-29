#include <stdio.h>
#include <stdlib.h>

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
void set(struct Array *arr, int index, int value)
{
    if (index >= 0 && index < arr->length)
    {
        arr->A[index] = value;
    }
}

int main()
{

    struct Array arr = {{1, 2, 3, 4, 5, 6}, 10, 6};

    display(arr);
    set(&arr, 0, 0);
    display(arr);
}