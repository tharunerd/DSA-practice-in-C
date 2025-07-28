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

//chech if the array is sorted or not
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


// inserting an element in sorted array 

void insert_sorted(struct Array *arr, int value)
{
    int i = arr->length - 1;
    if (arr->length == arr->size)
        return;
    while (i >= 0 && arr->A[i] > value)
    {
        arr->A[i + 1] = arr->A[i];
        i--;
    }
    arr->A[i + 1] = value;
    arr->length++;
}

int main()
{

    struct Array arr = {{1, 2, 3, 4, 5, 6}, 10, 6};

    display(arr);
    insert(&arr, 3, 8);
    display(arr);
    insert_sorted(&arr, 5);
    display(arr);
    check_sorted(arr);
    insert_sorted(&arr, 7);
}