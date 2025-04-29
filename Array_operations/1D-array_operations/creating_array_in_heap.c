#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr; // Pointer to hold the base address of the dynamically allocated array
    int n, i;

    // Ask the user for number of elements
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Dynamically allocate memory for 'n' integers using malloc
    arr = (int *)malloc(n * sizeof(int));

    // Check if memory allocation was successful
    if (arr == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1; // Exit with error
    }

    // Prompt user to enter the array elements
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Ask user for the value to insert
    int value, index;
    printf("Enter value to insert: ");
    scanf("%d", &value);

    // Ask the user at which index the value should be inserted
    printf("Enter index (0 to %d) to insert at: ", n);
    scanf("%d", &index);

    // Validate index range
    if (index < 0 || index > n)
    {
        printf("Invalid index.\n");
        free(arr); // Free the previously allocated memory
        return 1;
    }

    // Reallocate memory to increase the size of the array by 1
    arr = (int *)realloc(arr, (n + 1) * sizeof(int));

    // Shift elements to the right from the end to the given index
    for (i = n; i > index; i--)
    {
        arr[i] = arr[i - 1];
    }

    // Insert the new value at the specified index
    arr[index] = value;

    // Increment the size since we added one element
    n++;

    // Print the updated array
    printf("Array after insertion:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Free the dynamically allocated memory
    free(arr);

    return 0;
}
