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

// takes the array of type struct Array as reference and index, value as paremeter
void insert(struct Array *arr, int index, int value)
{
    if (index >= 0 && index <= arr->length)
    {
        for (int i = arr->length; i > index; i--)
            arr->A[i] = arr->A[i - 1];
        arr->A[index] = value;
        arr->length++;
    }
}

int main()
{

    struct Array arr = {{1, 2, 3, 4, 5, 6}, 10, 6};

    display(arr);
    insert(&arr, 3, 8);
    display(arr);
}