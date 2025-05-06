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

    // chech if the array is sorted or not

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
    void binary_search(struct Array arr, int value)
    {
        int low = 0, high = arr.length - 1, mid;
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (value == arr.A[mid])
            {
                printf("Element found at index %d\n", mid);
                return;
            }
            else if (value < arr.A[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        printf("Element not found\n");
    }

    // takes the array of type struct Array as reference and index, value as paremeter

    void binary_search_recursive(struct Array arr, int low, int high, int value)
    {
        if (low > high)
        {
            printf("Element not found\n");
            return;
        }
        int mid = (low + high) / 2;
        if (value == arr.A[mid])
        {
            printf("Element found at index %d\n", mid);
            return;
        }
        else if (value < arr.A[mid])
            binary_search_recursive(arr, low, mid - 1, value);
        else
            binary_search_recursive(arr, mid + 1, high, value);
    }

    int main ()
    {
        struct Array arr = {{2, 4, 6, 8, 9, 12, 15}, 10, 7};
        display(arr);
        check_sorted(arr);
        binary_search(arr, 9); // Element found at index 4
        binary_search(arr, 5); // Element not found
        binary_search_recursive(arr, 0, arr.length - 1, 12); // Element found at index 5
        binary_search_recursive(arr, 0, arr.length - 1, 10); // Element not found

        return 0;
    }