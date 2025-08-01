Queue using Array
#include <stdio.h>
#include <stdlib.h>
struct Queue    // Structure to represent a queue
{
 int size;
 int front;
 int rear;
 int *Q;
};

void create(struct Queue *q,int size) // Function to create a queue
{
 q->size=size;
 q->front=q->rear=-1;
 q->Q=(int *)malloc(q->size*sizeof(int));
}

void enqueue(struct Queue *q,int x) // Function to add an element to the queue 
{
 if(q->rear==q->size-1)
 printf("Queue is Full");
 else
 {
 q->rear++;
 q->
 Q[q->rear]=x;
 }
}

int dequeue(struct Queue *q) // Function to remove an element from the queue
{
 int x=-1;
 if(q->front==q->rear)
 printf("Queue is Empty\n");
 else
 {
 q->front++;
 x=q->Q[q->front];
 }
 return x;
}

void Display(struct Queue q)    // Function to display the elements in the queue
{
 int i;

 for(i=q.front+1;i<=q.rear;i++)
 printf("%d ",q.Q[i]);
 printf("\n");
}

int main()
{
 struct Queue q;
 create(&q,5);

 enqueue(&q,10);
 enqueue(&q,20);
 enqueue(&q,30);
 Display(q);

 printf("%d ",dequeue(&q));
 return 0;
}
