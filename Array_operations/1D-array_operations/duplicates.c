// just a simple program to find duplicates in an array
// using bubble sort

#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int *A;
    int size;
    int length;
};
struct Array *create(int size)
{
    struct Array *arr = (struct Array *)malloc(sizeof(struct Array));
    arr->size = size;
    arr->length = 0;
    arr->A = (int *)malloc(arr->size * sizeof(int));
    return arr;
}

void swap(struct Array *arr, int i, int j)
{
    int temp = arr->A[i];
    arr->A[i] = arr->A[j];
    arr->A[j] = temp;
}
void sort(struct Array *arr)
{
    for (int i = 0; i < arr->length - 1; i++)
    {
        for (int j = 0; j < arr->length - i - 1; j++)
        {
            if (arr->A[j] > arr->A[j + 1])
            {
                swap(arr, j, j + 1);
            }
        }
    }
}
void duplicates(struct Array *arr)
{
    sort(arr);
    printf("duplicates are:\n");
    for (int i = 0; i < arr->length-1; i++)
    {
        if (arr->A[i] == arr->A[i + 1])
            printf("\n%d", arr->A[i]);
    }

}

int main()
{
    struct Array *arr = create(10);
    arr->A[0] = 2;
    arr->A[1] = 2;
    arr->A[2] = 3;
    arr->A[3] = 4;
    arr->A[4] = 5;
    arr->A[5] = 6;
    arr->A[6] = 7;
    arr->A[7] = 8;
    arr->A[8] = 9;
    arr->A[9] = 10;
    arr->length = 10;

    duplicates(arr);


    free(arr->A); // Free the dynamically allocated memory for the array
    free(arr);    // Free the dynamically allocated memory for the struct
}
// Output: duplicates are: 2