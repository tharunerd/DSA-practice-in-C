// polynomial representation in C using linked list
#include <stdio.h>
#include <stdlib.h>

struct node {
    int coeff; // Coefficient of the term
    int exp;   // Exponent of the term
    struct node* next; // Pointer to the next term
};
    struct node* createNode(int coeff, int exp) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

struct node* insertTerm(struct node* head, int coeff, int exp) {
    struct node* newNode = createNode(coeff, exp);
    if (head == NULL || head->exp < exp) {
        newNode->next = head;
        return newNode;
    }
    struct node* temp = head;
    while (temp->next != NULL && temp->next->exp >= exp) {
        temp = temp->next;
    }
    if (temp->exp == exp) {
        temp->coeff += coeff; // Combine like terms
        free(newNode);
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
    }
    return head;
}

struct node* createPolynomial() {
    struct node* head = NULL;
    int coeff, exp;
    while (1) {
        printf("Enter coefficient and exponent (0 0 to stop): ");
        scanf("%d %d", &coeff, &exp);
        if (coeff == 0 && exp == 0) {
            break;
        }
        head = insertTerm(head, coeff, exp);
    }
    return head;
}
    int main() {
    printf("Enter polynomial terms (coefficient and exponent). Enter '0 0' to finish:\n");
    printf("Example: 3 2 for 3x^2, 4 1 for 4x^1, etc.\n");
    printf("You can enter terms in any order, and like terms will be combined.\n"); 
    struct node* polynomial = createPolynomial();
    printf("The polynomial is:\n");
    struct node* temp = polynomial;
    while (temp != NULL) {
        printf("%dx^%d ", temp->coeff, temp->exp);
        if (temp->next != NULL) {
            printf("+ ");
        }
        temp = temp->next;
    }
    printf("\n");
    return 0;
}


