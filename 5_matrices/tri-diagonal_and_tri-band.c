#include <stdio.h>
#include <stdlib.h>

// Tri-diagonal matrix using 1D array (size: 3n-2)
struct TriDiagonal {
    int *A;
    int n;
};

void SetTriDiagonal(struct TriDiagonal *m, int i, int j, int x) {
    if (i - j == 1)
        m->A[i - 2] = x;                  // Lower diagonal
    else if (i - j == 0)
        m->A[m->n - 1 + i - 1] = x;       // Main diagonal
    else if (i - j == -1)
        m->A[2 * m->n - 1 + i - 1] = x;   // Upper diagonal
    // else do nothing (element is zero)
}

int GetTriDiagonal(struct TriDiagonal m, int i, int j) {
    if (i - j == 1)
        return m.A[i - 2];
    else if (i - j == 0)
        return m.A[m.n - 1 + i - 1];
    else if (i - j == -1)
        return m.A[2 * m.n - 1 + i - 1];
    else
        return 0;
}

void DisplayTriDiagonal(struct TriDiagonal m) {
    int i, j;
    for (i = 1; i <= m.n; i++) {
        for (j = 1; j <= m.n; j++) {
            printf("%d ", GetTriDiagonal(m, i, j));
        }
        printf("\n");
    }
}

// Tri-band matrix (bandwidth 3) using 1D array (size: 5n-6)
struct TriBand {
    int *A;
    int n;
};

void SetTriBand(struct TriBand *m, int i, int j, int x) {
    if (abs(i - j) <= 2)
        m->A[(i - 1) * 5 + (j - i + 2)] = x;
}

int GetTriBand(struct TriBand m, int i, int j) {
    if (abs(i - j) <= 2)
        return m.A[(i - 1) * 5 + (j - i + 2)];
    else
        return 0;
}

void DisplayTriBand(struct TriBand m) {
    int i, j;
    for (i = 1; i <= m.n; i++) {
        for (j = 1; j <= m.n; j++) {
            printf("%d ", GetTriBand(m, i, j));
        }
        printf("\n");
    }
}

int main() {
    // Tri-diagonal example
    printf("Tri-diagonal matrix example:\n");
    struct TriDiagonal td;
    td.n = 5;
    td.A = (int *)calloc(3 * td.n - 2, sizeof(int));
    // Example: set main diagonal to 1, upper to 2, lower to 3
    for (int i = 1; i <= td.n; i++) {
        SetTriDiagonal(&td, i, i, 1); // main
        if (i < td.n) SetTriDiagonal(&td, i, i + 1, 2); // upper
        if (i > 1) SetTriDiagonal(&td, i, i - 1, 3); // lower
    }
    DisplayTriDiagonal(td);
    free(td.A);

    // Tri-band example
    printf("\nTri-band matrix example:\n");
    struct TriBand tb;
    tb.n = 5;
    tb.A = (int *)calloc(5 * tb.n - 6, sizeof(int));
    // Example: set all band elements to (i+j)
    for (int i = 1; i <= tb.n; i++) {
        for (int j = 1; j <= tb.n; j++) {
            if (abs(i - j) <= 2)
                SetTriBand(&tb, i, j, i + j);
        }
    }
    DisplayTriBand(tb);
    free(tb.A);

    return 0;
}

