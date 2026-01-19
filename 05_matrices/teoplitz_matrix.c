#include <stdio.h>
#include <stdlib.h>

// Toeplitz matrix structure
struct Toeplitz {
    int *A;
    int n;
};

// Set value at (i, j)
void Set(struct Toeplitz *t, int i, int j, int x) {
    if (i <= j)
        t->A[j - i] = x;           // First row elements
    else
        t->A[t->n + (i - j) - 1] = x; // First column elements (excluding A[0])
}

// Get value at (i, j)
int Get(struct Toeplitz t, int i, int j) {
    if (i <= j)
        return t.A[j - i];
    else
        return t.A[t.n + (i - j) - 1];
}

// Display the matrix
void Display(struct Toeplitz t) {
    int i, j;
    for (i = 1; i <= t.n; i++) {
        for (j = 1; j <= t.n; j++) {
            printf("%d ", Get(t, i, j));
        }
        printf("\n");
    }
}

int main() {
    struct Toeplitz t;
    int i, j, x;
    printf("Enter dimension: ");
    scanf("%d", &t.n);
    t.A = (int *)malloc(2 * t.n - 1 * sizeof(int));
    printf("Enter first row:\n");
    for (i = 1; i <= t.n; i++) {
        scanf("%d", &x);
        Set(&t, 1, i, x);
    }
    printf("Enter first column (excluding first element):\n");
    for (i = 2; i <= t.n; i++) {
        scanf("%d", &x);
        Set(&t, i, 1, x);
    }
    printf("\nToeplitz Matrix:\n");
    Display(t);
    free(t.A);
    return 0;
}