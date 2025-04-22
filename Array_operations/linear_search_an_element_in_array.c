
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

int Linear_search(struct Array arr, int key)
{
    for (int i = 0; i < arr.length; i++)
    {
        if (key == arr.A[i])
        {
            printf("%d\n", i);
            return i; // returns the index
        }
    }
    return -1;
}

int main()
{
    struct Array arr = {{1, 2, 3, 4, 5}, 10, 5};
    display(arr);
    Linear_search(arr, 4);
    return 0;
}
