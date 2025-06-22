//finding sum of pairs with sum k
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
void findPairsWithSumK(struct Array *arr, int k) {
    int left = 0;
    int right = arr->length - 1;

    while (left < right) {
        int sum = arr->A[left] + arr->A[right];
        if (sum == k) {
            printf("Pair found: (%d, %d)\n", arr->A[left], arr->A[right]);
            left++;
            right--;
        } else if (sum < k) {
            left++;
        } else {
            right--;
        }
    }
}
int main() {
    struct Array *arr = create(10);
    arr->A[0] = 1;
    arr->A[1] = 2;
    arr->A[2] = 3;
    arr->A[3] = 4;
    arr->A[4] = 5;
    arr->A[5] = 6;
    arr->A[6] = 7;
    arr->A[7] = 8;
    arr->A[8] = 9;
    arr->A[9] = 10;
    arr->length = 10;

    int k = 10; // Example sum
    findPairsWithSumK(arr, k);

    free(arr->A);
    free(arr);
    return 0;
}
