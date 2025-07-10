// creating circular linked list in C
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void createCircularLinkedList(struct Node** head_ref, int data) {
    struct Node* newNode = createNode(data);
    if (*head_ref == NULL) {
        *head_ref = newNode;
        newNode->next = *head_ref; // Point to itself
    } else {
        struct Node* temp = *head_ref;
        while (temp->next != *head_ref) {
            temp = temp->next; // Traverse to the last node
        }
        temp->next = newNode; // Link the new node at the end
        newNode->next = *head_ref; // Make it circular
    }
}

void printCircularLinkedList(struct Node* head) {
    if (head == NULL) return;
    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");
}
int main() {
    struct Node* head = NULL;

    // Create a circular linked list with elements 1, 2, 3
    createCircularLinkedList(&head, 1);
    createCircularLinkedList(&head, 2);
    createCircularLinkedList(&head, 3);

    printf("Circular Linked List:\n");
    printCircularLinkedList(head);

    // Free memory (not shown for simplicity)
    
    return 0;
}
