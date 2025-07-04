// finding min and max element in single scan of an array
#include <stdio.h>
#include <limits.h>
#include <stddef.h>


struct array {
    int *data;
    size_t size;
};  

void find_min_max(const struct array *arr, int *min, int *max) {
    if (arr->size == 0) {
        *min = INT_MAX;
        *max = INT_MIN;
        return;
    }

    *min = arr->data[0];
    *max = arr->data[0];

    for (size_t i = 1; i < arr->size; i++) {
        if (arr->data[i] < *min) {
            *min = arr->data[i];
        }
        if (arr->data[i] > *max) {
            *max = arr->data[i];
        }
    }
}


int main ()
{

    struct array arr;
    int data[] = {3, 5, 1, 8, 2};
    arr.data = data;
    arr.size = sizeof(data) / sizeof(data[0]);

    int min, max;
    find_min_max(&arr, &min, &max);

    printf("Minimum: %d\n", min);
    printf("Maximum: %d\n", max);

    return 0;
}