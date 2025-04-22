//sorting the elements in ascending order
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
        printf("%d  ", arr.A[i]);
    printf("\n");
}

void sort_assending(struct Array *arr)
{
    int i, j, temp;
    for (i = 0; i < arr->length - 1; i++)
    {
        for (j = i + 1; j < arr->length; j++)
        {
            if (arr->A[i] > arr->A[j])
            {
                temp = arr->A[i];
                arr->A[i] = arr->A[j];
                arr->A[j] = temp;
            }
        }
    }
}

void sort_descending(struct Array *arr)
{
    int i, j, temp;
    for (i = 0; i < arr->length - 1; i++)
    {
        for (j = i + 1; j < arr->length; j++)
        {
            if (arr->A[i] < arr->A[j])
            {
                temp = arr->A[i];
                arr->A[i] = arr->A[j];
                arr->A[j] = temp;
            }
        }
    }
}

int main()
{
    struct Array arr = {{2, 4, 6, 8, 16, 12, 15}, 10, 7};
    display(arr); // 2 4 6 8 16 12 15
    sort(&arr); 
    display(arr); // 2 4 6 8 12 15 16
    return 0;
}
