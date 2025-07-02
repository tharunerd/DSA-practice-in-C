// // symmetrical matrix
// A symmetrical matrix (more commonly called a symmetric matrix) is a square matrix that is equal to its transpose.
// This means that for every element at position (i, j), the value is the same as at position (j, i):
// 

#include <stdio.h>
#include <stdlib.h>

    int
    main() {
    int n, i, j, symmetric = 1;
    printf("Enter Dimension: ");
    scanf("%d", &n);
    int **A = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
        A[i] = (int *)malloc(n * sizeof(int));

    printf("Enter all elements:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &A[i][j]);

    // Check symmetry
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (A[i][j] != A[j][i]) {
                symmetric = 0;
                break;
            }
        }
        if (!symmetric) break;
    }

    if (symmetric)
        printf("The matrix is symmetric.\n");
    else
        printf("The matrix is NOT symmetric.\n");

    // Free memory
    for (i = 0; i < n; i++)
        free(A[i]);
    free(A);

    return 0;
}
// This program checks if a matrix is symmetrical by comparing elements across the diagonal.