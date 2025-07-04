// get means it tells the value at the given index in the array
// This is a simple program to get the value at a given index in an array

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

int get(struct Array arr, int index)
{
    if (index >= 0 && index < arr.length)
    {
        printf("\nthe element at given index (%d) is %d", index, arr.A[index]);
    }
    return -1; // Return -1 if index is out of
}

void set(struct Array *arr, int index, int value)
{
    if (index >= 0 && index < arr->length)
    {
        arr->A[index] = value;
    }
}

int search(struct Array arr, int key)
{
    for (int i = 0; i < arr.length; i++)
    {
        if (key == arr.A[i])
        {
            printf("\nyes the element you are searching for is present in array and it is in the index  = %d \n", i);
            return i;
        }
    }
    return -1; // Return -1 if key is not found
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
    struct Array arr = {{2, 4, 6, 8, 9, 12, 15}, 10, 7};
    set(&arr, 0, 0);
    display(arr);
    get(arr, 2);
    search(arr, 4);
    append(&arr, 20);
    display(arr);
    return 0;
}