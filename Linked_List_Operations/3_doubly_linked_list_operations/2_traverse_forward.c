// a c program for doubly linked list traversal in forward and backward direction
#include <stdio.h>
#include <stdlib.h>
// Define the structure for a node in the doubly linked list
struct Node {
    int data;               // Data part of the node
    struct Node* next;     // Pointer to the next node
    struct Node* prev;     // Pointer to the previous node
};
// Function to create a new node with given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); // Allocate memory for a new node
    newNode->data = data; // Set the data of the new node
    newNode->next = NULL; // Initialize the next pointer to NULL
    newNode->prev = NULL; // Initialize the previous pointer to NULL
    return newNode; // Return the newly created node
}
// Function to traverse the doubly linked list in forward direction
void traverseForward(struct Node* head) {
    struct Node* current = head; // Start from the head of the list
    while (current != NULL) { // Traverse until the end of the list
        printf("%d ", current->data); // Print the data of the current node
        current = current->next; // Move to the next node
    }
    printf("\n"); // Print a newline at the end
}
void traverseBackward(struct Node* head) {
    struct Node* current = head; // Start from the head of the list
    // Move to the last node
    while (current->next != NULL) {
        current = current->next;
    }
    // Traverse backward
    while (current != NULL) {
        printf("%d ", current->data); // Print the data of the current node
        current = current->prev; // Move to the previous node
    }
    printf("\n"); // Print a newline at the end
}

// Function to insert a new node at the end of the doubly linked list
void insertAtEnd(struct Node** head_ref, int new_data) {
    struct Node* new_node = createNode(new_data); // Create a new node
    if (*head_ref == NULL) { // If the list is empty
        *head_ref = new_node; // Make the new node the head
        return;
    }
    struct Node* last = *head_ref; // Start from the head
    while (last->next != NULL) { // Traverse to the last node
        last = last->next;
    }
    last->next = new_node; // Link the new node at the end
    new_node->prev = last; // Set the previous pointer of the new node
}
// Main function to demonstrate the traversal of a doubly linked list
int main() {
    struct Node* head = NULL; // Initialize the head of the list
    // Insert some nodes at the end of the list
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    
    printf("Doubly Linked List in Forward Direction:\n");
    traverseForward(head); // Traverse and print the list in forward direction
    printf("Doubly Linked List in Backward Direction:\n");
    traverseBackward(head); // Traverse and print the list in backward direction
    
    return 0; // Return success
}
