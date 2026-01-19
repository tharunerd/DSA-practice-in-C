// creating sparse matrix
// A sparse matrix is a matrix in which most of the elements are zero.
// Sparse matrices are often stored in a more memory-efficient way, such as using a list of non-zero elements or a coordinate list (COO) format.    
#include <stdio.h>
#include <stdlib.h>

// Structure for a sparse matrix in COO format
struct SparseMatrix {
    int *values;      // Non-zero values
    int *rowIndex;    // Row indices for non-zero values
    int *colIndex;    // Column indices for non-zero values
    int nonZeroCount; // Number of non-zero elements
    int capacity;     // Maximum number of non-zero elements
    int rows;         // Total rows in the matrix
    int cols;         // Total columns in the matrix
};

// Initialize the sparse matrix with given size and capacity
void initSparseMatrix(struct SparseMatrix *mat, int rows, int cols, int capacity) {
    mat->rows = rows;
    mat->cols = cols;
    mat->capacity = capacity;
    mat->nonZeroCount = 0;
    mat->values = (int *)malloc(capacity * sizeof(int));
    mat->rowIndex = (int *)malloc(capacity * sizeof(int));
    mat->colIndex = (int *)malloc(capacity * sizeof(int));
}

// Add a non-zero element to the sparse matrix
void addElement(struct SparseMatrix *mat, int row, int col, int value) {
    if (value != 0 && mat->nonZeroCount < mat->capacity) {
        mat->values[mat->nonZeroCount] = value;
        mat->rowIndex[mat->nonZeroCount] = row;
        mat->colIndex[mat->nonZeroCount] = col;
        mat->nonZeroCount++;
    }
}

// Get the value at a specific position (row, col)
int getElement(const struct SparseMatrix *mat, int row, int col) {
    for (int i = 0; i < mat->nonZeroCount; i++) {
        if (mat->rowIndex[i] == row && mat->colIndex[i] == col)
            return mat->values[i];
    }
    return 0;
}

// Display the full matrix (including zeros)
void displayFullMatrix(const struct SparseMatrix *mat) {
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            printf("%d ", getElement(mat, i, j));
        }
        printf("\n");
    }
}

// Display the sparse matrix in COO format
void displayCOO(const struct SparseMatrix *mat) {
    printf("Row Col Value\n");
    for (int i = 0; i < mat->nonZeroCount; i++) {
        printf("%3d %3d %5d\n", mat->rowIndex[i], mat->colIndex[i], mat->values[i]);
    }
}

// Free the memory used by the sparse matrix
void freeSparseMatrix(struct SparseMatrix *mat) {
    free(mat->values);
    free(mat->rowIndex);
    free(mat->colIndex);
}

int main() {
    struct SparseMatrix mat;
    int rows, cols, nz, value, row, col;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);
    printf("Enter number of non-zero elements: ");
    scanf("%d", &nz);

    initSparseMatrix(&mat, rows, cols, nz);

    printf("Enter each non-zero element as: row col value (0-based indices)\n");
    for (int i = 0; i < nz; i++) {
        scanf("%d %d %d", &row, &col, &value);
        addElement(&mat, row, col, value);
    }

    printf("\nSparse Matrix (COO format):\n");
    displayCOO(&mat);

    printf("\nFull Matrix:\n");
    displayFullMatrix(&mat);

    freeSparseMatrix(&mat);
    return 0;
}
// This program allows the user to create a sparse matrix by entering non-zero elements and their positions.
// It stores the non-zero elements in a compact format and displays them. The user can enter
// the number of rows and columns, followed by the non-zero elements in the format "row col value".
// The program continues to accept input until the user enters -1 -1 -1, at which point it displays the sparse matrix representation.
// The sparse matrix is represented using three arrays: one for the values, one for the row indices, and one for the column indices.
// The program also includes functions to initialize the sparse matrix, set elements, get elements, display the matrix, and free allocated memory.
// This approach is efficient for storing and manipulating sparse matrices, as it only uses memory for the non-zero elements.
// Sparse matrices are commonly used in various applications, such as scientific computing, machine learning, and graph algorithms,
// where the majority of elements are often zero, allowing for significant memory savings and performance improvements.
// The program can be extended to include additional functionalities, such as matrix addition, multiplication, or transposition,
// depending on the specific requirements of the application.
