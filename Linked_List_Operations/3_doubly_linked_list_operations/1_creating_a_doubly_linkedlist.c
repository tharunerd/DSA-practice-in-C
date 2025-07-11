#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
    struct node* prev;
};

struct node* createNode(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node)); // Allocate memory for a new node
    if (newNode == NULL) { // Check if memory allocation was successful
        printf("Memory allocation failed\n");
        exit(1); // Exit the program if memory allocation fails
    }
    newNode->data = value; // Set the data of the new node
    newNode->next = NULL;  // Initialize the next pointer to NULL
    newNode->prev = NULL;  // Initialize the previous pointer to NULL
    return newNode;        // Return the newly created node
}

void printList(struct node* head) {
    struct node* current = head; // Start from the head of the list
    while (current != NULL) { // Traverse the list until the end
        printf("%d <-> ", current->data); // Print the data of the current node
        current = current->next;          // Move to the next node
    }
    printf("NULL\n"); // Indicate the end of the list
}

int main() {
    struct node* head = createNode(1); // Create the head node with value 1
    struct node* second = createNode(2); // Create the second node with value 2
    struct node* third = createNode(3); // Create the third node with value 3

    // Link the nodes together to form a doubly linked list
    head->next = second; // Link head to second
    second->prev = head; // Link second back to head
    second->next = third; // Link second to third
    third->prev = second; // Link third back to second

    printList(head); // Print the doubly linked list

    return 0; // Return success
}