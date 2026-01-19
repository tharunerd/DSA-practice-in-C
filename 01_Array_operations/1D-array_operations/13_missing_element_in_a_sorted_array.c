#finding missing element in a sorted array
//     arr->A[3] = 4;
#include <stdio.h>
#include <stdlib.h>
struct Array {
    int *A;
    int size;
    int length;
};
struct Array *create(int size) {
    struct Array *arr = (struct Array *)malloc(sizeof(struct Array));
    arr->size = size;
    arr->length = 0;
    arr->A = (int *)malloc(arr->size * sizeof(int));
    return arr;
}
int findMissingElementinsotredarray(struct Array *arr) {
    int total = (arr->length + 1) * (arr->length + 2) / 2; // Sum of first n natural numbers
    for (int i = 0; i < arr->length; i++) {
        total -= arr->A[i];
    }
    return total;
}

int find_missing_element_in_non_sorted_array(struct Array *arr) {
    int max = arr->A[0];
    int min = arr->A[0];
    for (int i = 1; i < arr->length; i++) {
        if (arr->A[i] > max) {
            max = arr->A[i];
        }
        if (arr->A[i] < min) {
            min = arr->A[i];
        }
    }
    int expectedSum = (max * (max + 1)) / 2 - ((min - 1) * min) / 2;
    int actualSum = 0;
    for (int i = 0; i < arr->length; i++) {
        actualSum += arr->A[i];
    }
    return expectedSum - actualSum;
}
int main() {
    // Example usage for finding missing element in a sorted array
    // For a sorted array, the missing element is calculated based on the sum of first n
    struct Array *arr = create(10);
    arr->A[0] = 1;
    arr->A[1] = 2;
    arr->A[2] = 3;
    arr->A[3] = 5; // Missing element is 4
    arr->length = 4;

    int missingElement = findMissingElement(arr);
    printf("The missing element is: %d\n", missingElement);

    // Example usage for finding missing element in a non-sorted array
    struct Array *arr2 = create(10);
    arr2->A[0] = 3;
    arr2->A[1] = 7;     
    arr2->A[2] = 1;
    arr2->A[3] = 2;     // Missing element is 4\
    arr2->A[4] = 5;
    arr2->length = 5;
    int missingElement2 = find_missing_element_in_non_sorted_array(arr2);
    printf("The missing element in non-sorted array is: %d\n", missingElement2);
    free(arr->A);
    free(arr);
    return 0;
}
//     arr->length = 5;
