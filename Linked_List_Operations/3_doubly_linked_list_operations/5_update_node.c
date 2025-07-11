// update a node in a doubly linked list
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

// function to update a node's data by index in the doubly linked list
void updatebyindex(struct Node** head_ref, int index, int new_data) {
    if (*head_ref == NULL || index < 0) { // Check if the list is empty or index is negative
        printf("List is empty or index is invalid.\n");
        return;
    }
    struct Node* current = *head_ref; // Start from the head of the list
    for (int i = 0; current != NULL && i < index; i++) { // Traverse to the node at the given index
        current = current->next;
    }
    if (current == NULL) { // If we reached the end of the list without finding the index
        printf("Index out of bounds.\n");
        return;
    }
    current->data = new_data; // Update the data of the node at the given index
}

// Function to update a node's data in the doubly linked list
void updateNode(struct Node* node, int new_data) {
    if (node == NULL) { // Check if the node is NULL
        printf("Node is NULL. Cannot update.\n");
        return;
    }
    node->data = new_data; // Update the data of the node
}
// Function to print the doubly linked list
void printList(struct Node* node) {
    while (node != NULL) { // Traverse the list
        printf("%d ", node->data); // Print the data of the current node
        node = node->next; // Move to the next node
    }
    printf("\n"); // Print a newline at the end
}
// Main function to demonstrate the update operation in a doubly linked list
int main() {
    struct Node* head = createNode(10); // Create the first node with data 10
    struct Node* second = createNode(20); // Create the second node with data 20
    struct Node* third = createNode(30);  // Create the third node with data 30

    // Link the nodes together to form a doubly linked list
    head->next = second; 
    second->prev = head; 
    second->next = third; 
    third->prev = second;

    printf("Original List: ");
    printList(head); // Print the original list

    updateNode(second, 25); // Update the data of the second node to 25
    printf("Updated List: ");
    printList(head); // Print the updated list

    updatebyindex(&head, 1, 35); // Update the data of the node at index 1 to 35
    printf("List after updating index 1: ");
    printList(head); // Print the list after updating by index

    return 0; // Return success
}
// Output:
// Original List: 10 20 30
// Updated List: 10 25 30
