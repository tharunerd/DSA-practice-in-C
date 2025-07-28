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

void reverse(struct Array *arr)
{
    int *b = (int *)malloc(arr->length * sizeof(int));
    for (int i = arr->length - 1, j = 0; i >= 0; i--, j++)
        b[j] = arr->A[i];
    for (int i = 0; i < arr->length; i++)
        arr->A[i] = b[i];
    free(b);
}

int main()
{
    struct Array arr = {{2, 4, 6, 8, 9, 12, 15}, 10, 7};
    display(arr);
    reverse(&arr);
    display(arr);
    return 0;
}
