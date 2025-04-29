#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Define the maximum size of the stack

typedef struct
{
    int items[MAX];
    int top;
} Stack;

// Function to initialize the stack
void initStack(Stack *s)
{
    s->top = -1;
}

// Function to check if the stack is empty
int isEmpty(Stack *s)
{
    return s->top == -1;
}

// Function to check if the stack is full
int isFull(Stack *s)
{
    return s->top == MAX - 1;
}

// Function to push an element onto the stack
void push(Stack *s, int item)
{
    if (isFull(s))
    {
        printf("Stack is full!\n");
    }
    else
    {
        s->items[++(s->top)] = item;
    }
}

// Function to pop an element from the stack
int pop(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty!\n");
        return -1;
    }
    else
    {
        return s->items[(s->top)--];
    }
}

// Function to peek at the top element of the stack
int peek(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty!\n");
        return -1;
    }
    else
    {
        return s->items[s->top];
    }
}

int main()
{
    Stack s;
    initStack(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    printf("Top element: %d\n", peek(&s));
    printf("Popped element: %d\n", pop(&s));
    printf("Top element after pop: %d\n", peek(&s));

    return 0;
}
