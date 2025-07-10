// deleting an elemeny from an array
#include <stdio.h>
#include <stdlib.h>
void deleteElement(int arr[], int *length, int element) {
    int i, j;
    for (i = 0; i < *length; i++) {
        if (arr[i] == element) {
            // Shift elements to the left
            for (j = i; j < *length - 1; j++) {
                arr[j] = arr[j + 1];
            }
            (*length)--; // Decrease the length of the array
            return; // Exit after deleting the first occurrence
        }
    }
    printf("Element %d not found in the array.\n", element);
}
void displayArray(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int length = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original array: ");
    displayArray(arr, length);
    
    int elementToDelete = 30;
    deleteElement(arr, &length, elementToDelete);
    
    printf("Array after deleting %d: ", elementToDelete);
    displayArray(arr, length);
    
    return 0;
}
