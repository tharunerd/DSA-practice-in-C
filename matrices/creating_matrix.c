// Diagonal Matrix C

#include <stdio.h>

#define MAX_SIZE 10

typedef struct {
    int A[MAX_SIZE];
    int n;
} Matrix;

// Set value x at position (i, j) if it's on the diagonal
void Set(Matrix *m, int i, int j, int x) {
    if (i == j && i >= 1 && i <= m->n)
        m->A[i - 1] = x;
}

// Get value at position (i, j)
int Get(const Matrix *m, int i, int j) {
    if (i == j && i >= 1 && i <= m->n)
        return m->A[i - 1];
    return 0;
}

// Display the matrix
void Display(const Matrix *m) {
    for (int i = 1; i <= m->n; i++) {
        for (int j = 1; j <= m->n; j++) {
            if (i == j)
                printf("%d ", m->A[i - 1]);
            else
                printf("0 ");
        }
        printf("\n");
    }
}

int main() {
    Matrix m = { .n = 4 };

    Set(&m, 1, 1, 5);
    Set(&m, 2, 2, 8);
    Set(&m, 3, 3, 9);
    Set(&m, 4, 4, 12);

    printf("%d\n", Get(&m, 2, 2));
    Display(&m);

    return 0;
}