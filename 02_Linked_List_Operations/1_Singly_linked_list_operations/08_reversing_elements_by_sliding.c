// reversing using sliding window technique
#include <stdio.h>  
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
// Function to push a new node with given data at the end of the list
void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref; // Used to traverse to the last node
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node; // If list is empty, make the new node the head
        return;
    }

    while (last->next != NULL) {
        last = last->next; // Traverse to the last node
    }
    last->next = new_node; // Link the new node at the end
}   

// Function to reverse the linked list using sliding window technique
void reverse(struct Node** head_ref) {
    struct Node* current = *head_ref;
    struct Node* prev = NULL;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next; // Store the next node
        current->next = prev; // Reverse the link
        prev = current; // Move prev to current
        current = next; // Move to the next node
    }
    *head_ref = prev; // Update head to the new first node
}   
// Function to print the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    // Create a linked list: 1->2->3->4->5
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    push(&head, 5);

    printf("Original Linked List:\n");
    printList(head);

    reverse(&head);

    printf("Reversed Linked List:\n");
    printList(head);

    return 0;
}
// This code defines a singly linked list and provides functions to push new nodes at the end,

