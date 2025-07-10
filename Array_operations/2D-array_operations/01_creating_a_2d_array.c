#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int *A;
    int rows;
    int cols;
};

void display(struct Array arr)
{
    for (int i = 0; i < arr.rows; i++)
    {
        for (int j = 0; j < arr.cols; j++)
            printf("%d ", arr.A[i * arr.cols + j]);
        printf("\n");
    }
}

void create(struct Array *arr, int rows, int cols)
{
    arr->rows = rows;
    arr->cols = cols;
    arr->A = (int *)malloc(rows * cols * sizeof(int));
}

void set_value(struct Array *arr, int i, int j, int value)
{
    if (i >= 0 && i < arr->rows && j >= 0 && j < arr->cols)
        arr->A[i * arr->cols + j] = value;
    else
        printf("Index out of bounds\n");
}

void get_value(struct Array arr, int i, int j)
{
    if (i >= 0 && i < arr.rows && j >= 0 && j < arr.cols)
        printf("%d\n", arr.A[i * arr.cols + j]);
    else
        printf("Index out of bounds\n");
}

void free_memory(struct Array *arr)
{
    free(arr->A);
    arr->A = NULL;
}

int main()
{
    struct Array arr;
    create(&arr, 3, 4); // Create a 3x4 array

    // Set values in the array
    set_value(&arr, 0, 0, 1);
    set_value(&arr, 0, 1, 2);
    set_value(&arr, 0, 2, 3);
    set_value(&arr, 0, 3, 4);
    set_value(&arr, 1, 0, 5);
    set_value(&arr, 1, 1, 6);
    set_value(&arr, 1, 2, 7);
    set_value(&arr, 1, 3, 8);
    set_value(&arr, 2, 0, 9);
    set_value(&arr, 2, 1, 10);
    set_value(&arr, 2, 2, 11);
    set_value(&arr, 2, 3, 12);

    display(arr); // Display the array

    printf("value at 2nd row 3rd column is ");
    get_value(arr, 1, 2); // Get value at (1,2)

    free_memory(&arr); // Free allocated memory
    return 0;
}

// Output:
// 1 2 3 4
// 5 6 7 8
// 9 10 11 12
// value at 2nd row 3rd column is 7