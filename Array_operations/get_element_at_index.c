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
        printf("%d", arr.A[index]);
    }
    return -1; // Return -1 if index is out of
}

int main()
{
    struct Array arr = {{2, 4, 6, 8, 9, 12, 15}, 10, 7};
    get(arr, 4);
}