// sparse matrix using linked list
#include <stdio.h>
#include <stdlib.h>


struct node {
    int row;
    int col;
    int value;
    struct node* next;
};
struct node* createNode(int row, int col, int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->row = row;
    newNode->col = col;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}
struct node* insertNode(struct node* head, int row, int col, int value) {
    struct node* newNode = createNode(row, col, value);
    if (head == NULL) {
        return newNode;
    }
    struct node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}
struct node* createSparseMatrix(int rows, int cols) {
    struct node* head = NULL;
    int value;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter value for [%d][%d] (0 for no value): ", i, j);
            scanf("%d", &value);
            if (value != 0) {
                head = insertNode(head, i, j, value);
            }
        }
    }
    return head;
}
void displaySparseMatrix(struct node* head) {
    struct node* temp = head;
    printf("Row\tCol\tValue\n");
    while (temp != NULL) {
        printf("%d\t%d\t%d\n", temp->row, temp->col, temp->value);
        temp = temp->next;
    }
}
int main() {
    int rows, cols;
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    struct node* sparseMatrix = createSparseMatrix(rows, cols);
    displaySparseMatrix(sparseMatrix);

    // Free the allocated memory
    struct node* temp;
    while (sparseMatrix != NULL) {
        temp = sparseMatrix;
        sparseMatrix = sparseMatrix->next;
        free(temp);
    }

    return 0;
}
// This code creates a sparse matrix using a linked list in C.
// It allows the user to input values for the matrix and stores only non-zero values in the linked list.
// The sparse matrix is then displayed in a structured format.



