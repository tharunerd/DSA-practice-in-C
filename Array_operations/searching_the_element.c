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

int search(struct Array arr, int key)
{
    for (int i = 0; i < arr.length; i++)
    {
        if (key == arr.A[i])
        {
            printf("yes the element you are searching for is present in the array and it is in the index  = ");
            return i;
        }
    }
    return -1; // Return -1 if key is not found
}

int main()
{
    struct Array arr = {{2, 4, 6, 8, 9, 12, 15}, 10, 7};
    printf("%d", search(arr, 4));
}
