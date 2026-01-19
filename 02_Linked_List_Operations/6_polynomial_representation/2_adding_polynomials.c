#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coeff;
    int exp;
    struct node *next;
};

struct node *createNode(int coeff, int exp)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

struct node *insertTerm(struct node *head, int coeff, int exp)
{
    struct node *newNode = createNode(coeff, exp);
    if (head == NULL || head->exp < exp)
    {
        newNode->next = head;
        return newNode;
    }
    struct node *temp = head;
    while (temp->next != NULL && temp->next->exp >= exp)
    {
        temp = temp->next;
    }
    if (temp->exp == exp)
    {
        temp->coeff += coeff;
        free(newNode);
    }
    else
    {
        newNode->next = temp->next;
        temp->next = newNode;
    }
    return head;
}

struct node *addPolynomials(struct node *poly1, struct node *poly2)
{
    struct node *result = NULL;
    while (poly1 != NULL && poly2 != NULL)
    {
        if (poly1->exp > poly2->exp)
        {
            result = insertTerm(result, poly1->coeff, poly1->exp);
            poly1 = poly1->next;
        }
        else if (poly1->exp < poly2->exp)
        {
            result = insertTerm(result, poly2->coeff, poly2->exp);
            poly2 = poly2->next;
        }
        else
        {
            result = insertTerm(result, poly1->coeff + poly2->coeff, poly1->exp);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }
    while (poly1 != NULL)
    {
        result = insertTerm(result, poly1->coeff, poly1->exp);
        poly1 = poly1->next;
    }
    while (poly2 != NULL)
    {
        result = insertTerm(result, poly2->coeff, poly2->exp);
        poly2 = poly2->next;
    }
    return result;
}

struct node *createPolynomial()
{
    struct node *head = NULL;
    int coeff, exp;
    while (1)
    {
        printf("Enter coefficient and exponent (0 0 to stop): ");
        scanf("%d %d", &coeff, &exp);
        if (coeff == 0 && exp == 0)
            break;
        head = insertTerm(head, coeff, exp);
    }
    return head;
}

void printPolynomial(struct node *poly)
{
    while (poly != NULL)
    {
        printf("%dx^%d", poly->coeff, poly->exp);
        poly = poly->next;
        if (poly != NULL)
            printf(" + ");
    }
    printf("\n");
}

int main()
{
    printf("Enter first polynomial:\n");
    struct node *poly1 = createPolynomial();

    printf("Enter second polynomial:\n");
    struct node *poly2 = createPolynomial();

    struct node *result = addPolynomials(poly1, poly2);

    printf("Resultant polynomial: ");
    printPolynomial(result);

    return 0;
}
