// creating stacks using array in C
// This code implements a stack using an array in C.

#include <stdio.h>
#include <stdlib.h>
#define MAX 100 // Maximum size of the stack
struct Stack {
    int top;
    int items[MAX];
};
struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1; // Initialize top to -1 indicating stack is empty
    return stack;
}
void push(struct Stack* stack, int data) {
    if (stack->top == MAX - 1) {
        printf("Stack overflow\n");
        return; // Stack is full
    }
    stack->items[++stack->top] = data; // Increment top and add data
}
int pop(struct Stack* stack) {
    if (stack->top == -1) {
        printf("Stack underflow\n");
        return -1; // Indicating stack is empty
    }
    return stack->items[stack->top--]; // Return top item and decrement top
}
void display(struct Stack* stack) {
    if (stack->top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->items[i]);
    }
    printf("\n");
}
void freeStack(struct Stack* stack) {
    free(stack); // Free the allocated memory for the stack
}

int main() {
    struct Stack* stack = createStack();
    push(stack, 10);
    push(stack, 20);
    display(stack);
    printf("Popped element: %d\n", pop(stack));
    display(stack);
    freeStack(stack);
    return 0;
}


