//creating stacks using linked list in C
// This code implements a stack using a linked list in C. 
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Stack {
    struct Node* top;
};
struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = NULL;
    return stack;
}
void push(struct Stack* stack, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}
int pop(struct Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack underflow\n");
        return -1; // Indicating stack is empty
    }
    struct Node* temp = stack->top;
    int poppedData = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return poppedData;
}
void display(struct Stack* stack) {
    struct Node* current = stack->top;
    if (current == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
void freeStack(struct Stack* stack) {
    struct Node* current = stack->top;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(stack);
}
int main() {
    struct Stack* stack = createStack();
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    display(stack);
    
    printf("Popped element: %d\n", pop(stack));
    display(stack);
    
    freeStack(stack);
    return 0;
}
