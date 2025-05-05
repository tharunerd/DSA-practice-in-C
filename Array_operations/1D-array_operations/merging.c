#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int A[20]; // Increased size to accommodate merged array
    int size;
    int length;
};

void display(struct Array *arr)
{
    for (int i = 0; i < arr->length; i++)
        printf("%d -> %d \n", arr->A[i], i);
    printf("\n");
}

void merge(struct Array *arr1, struct Array *arr2, struct Array *arr3)
{
    int i = 0, j = 0, k = 0;

    arr3->size = arr1->size + arr2->size;
    arr3->length = arr1->length + arr2->length;
    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else
            arr3->A[k++] = arr2->A[j++];
    }
    for (; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];
    for (; j < arr2->length; j++)
        arr3->A[k++] = arr2->A[j];
}

int main()
{
    struct Array arr1 = {{2, 3, 4, 5, 6}, 10, 5};
    struct Array arr2 = {{1, 7, 8, 9, 10}, 10, 5};
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    merge(&arr1, &arr2, arr3);
    display(arr3);
    free(arr3); // Free allocated memory
    return 0;
}
