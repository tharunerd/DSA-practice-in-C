//queue operations using linked list
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Queue {
    struct Node* front;
    struct Node* rear;
};
void createQueue(struct Queue* q) {
    q->front = q->rear = NULL;
}
void enqueue(struct Queue* q, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}
int dequeue(struct Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return -1; // Indicating queue is empty
    }
    struct Node* temp = q->front;
    int value = temp->data;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL; // If the queue is now empty
    }
    free(temp);
    return value;
}
void display(struct Queue q) {
    struct Node* temp = q.front;
    if (temp == NULL) {
        printf("Queue is empty\n");
        return;
    }
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main() {
    struct Queue q;
    createQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);

    printf("Queue elements: ");
    display(q);

    printf("Dequeued element: %d\n", dequeue(&q));
    printf("Queue after dequeue: ");
    display(q);

    return 0;
}
// This code implements a queue using linked lists in C.
// It includes functions to create a queue, enqueue elements, dequeue elements, and display the queue