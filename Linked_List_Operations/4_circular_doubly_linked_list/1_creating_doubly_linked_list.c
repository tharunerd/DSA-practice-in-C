// creating circular doubly linked list in C
#include <stdio.h>
#include <stdlib.h>
// Define the structure for a node in the circular doubly linked list
struct Node {
    int data;               // Data part of the node
    struct Node* next;      // Pointer to the next node
    struct Node* prev;      // Pointer to the previous node
};
// Function to create a new node with given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); // Allocate memory for a new node
    newNode->data = data; // Set the data of the new node
    newNode->next = NULL; // Initialize the next pointer to NULL
    newNode->prev = NULL; // Initialize the previous pointer to NULL
    return newNode; // Return the newly created node
}
// Function to create a circular doubly linked list with a single node
struct Node* createCircularDoublyLinkedList(int data) {
    struct Node* newNode = createNode(data); // Create a new node
    newNode->next = newNode; // Point next to itself
    newNode->prev = newNode; // Point prev to itself
    return newNode; // Return the newly created circular doubly linked list
}
// Function to insert a new node at the end of the circular doubly linked list
void insertAtEnd(struct Node** head_ref, int new_data) {
    struct Node* new_node = createNode(new_data); // Create a new node
    if (*head_ref == NULL) { // If the list is empty
        *head_ref = new_node; // Make the new node the head
        new_node->next = new_node; // Point next to itself
        new_node->prev = new_node; // Point prev to itself
        return;
    }
    struct Node* last = (*head_ref)->prev; // Start from the last node
    last->next = new_node; // Link the new node at the end
    new_node->prev = last; // Set the previous pointer of the new node
    new_node->next = *head_ref; // Link the new node to the head
    (*head_ref)->prev = new_node; // Update the previous pointer of the head
}
// Function to print the circular doubly linked list
void printCircularDoublyLinkedList(struct Node* head) {
    if (head == NULL) return; // If the list is empty
    struct Node* current = head; // Start from the head of the list
    do {
        printf("%d ", current->data); // Print the data of the current node
        current = current->next; // Move to the next node
    } while (current != head); // Continue until we come back to the head
    printf("\n"); // Print a newline at the end
}
// Main function to demonstrate the creation of a circular doubly linked list
int main() {
    struct Node* head = createCircularDoublyLinkedList(1); // Create a circular doubly linked list with a single node
    insertAtEnd(&head, 2); // Insert a new node with data 2 at the end
    insertAtEnd(&head, 3); // Insert a new node with data 3 at the end
    printf("Circular Doubly Linked List: ");
    printCircularDoublyLinkedList(head); // Print the circular doubly linked list
    return 0; // Return success
}
// This code creates a circular doubly linked list and demonstrates insertion and printing operations.
// The `createNode` function allocates memory for a new node and initializes its data and pointers.
