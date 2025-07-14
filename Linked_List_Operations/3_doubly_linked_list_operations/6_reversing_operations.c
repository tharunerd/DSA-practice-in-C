// reversing the elements of a doubly linked list
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
// Function to reverse the doubly linked list
void reverseList(struct Node** head_ref) {
    struct Node* current = *head_ref; // Start from the head of the list
    struct Node* temp = NULL; // Temporary pointer to store the next node
    // Traverse the list and swap next and prev pointers
    while (current != NULL) {
        temp = current->prev; // Store the previous node
        current->prev = current->next; // Swap next and prev pointers
        current->next = temp; // Update next pointer to the stored previous node
        current = current->prev; // Move to the next node (which is now previous)
    }
    // Update head to point to the new first node
    if (temp != NULL) {
        *head_ref = temp->prev; // Set head to the last processed node
    }
}
// Function to print the doubly linked list
void printList(struct Node* node) {
    while (node != NULL) { // Traverse the list
        printf("%d ", node->data); // Print the data of the current node
        node = node->next; // Move to the next node
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
// Main function to demonstrate the reversal of a doubly linked list
int main() {
    struct Node* head = NULL; // Initialize the head of the list
    // Insert some nodes at the end of the list
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    
    printf("Original Doubly Linked List:\n");
    printList(head); // Print the original list
    
    reverseList(&head); // Reverse the doubly linked list
    
    printf("Reversed Doubly Linked List:\n");
    printList(head); // Print the reversed list
    
    return 0; // Return success
}
// This code demonstrates how to reverse a doubly linked list in C.
