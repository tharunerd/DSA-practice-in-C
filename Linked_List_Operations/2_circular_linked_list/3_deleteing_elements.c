// deleting_operations in circular linked list 
#include <stdio.h>
#include <stdlib.h>
// Define the structure for a node in the circular linked list
struct Node {
    int data;               // Data part of the node
    struct Node* next;      // Pointer to the next node
};
// Function to create a new node with given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); // Allocate memory for a new node
    newNode->data = data; // Set the data of the new node
    newNode->next = NULL; // Initialize the next pointer to NULL
    return newNode; // Return the newly created node
}
// Function to delete a node from the circular linked list
void deleteNode(struct Node** head_ref, struct Node* del) {
    if (*head_ref == NULL || del == NULL) { // Check if the list or node to delete is NULL
        return;
    }
    
    if (*head_ref == del) { // If the node to delete is the head
        if (del->next == del) { // If there is only one node in the list
            *head_ref = NULL; // Set head to NULL
        } else {
            struct Node* temp = *head_ref; // Temporary pointer to traverse the list
            while (temp->next != *head_ref) { // Find the last node
                temp = temp->next;
            }
            temp->next = del->next; // Update the last node's next pointer
            *head_ref = del->next; // Update head to the next node
        }
    } else {
        struct Node* current = *head_ref; // Start from the head of the list
        while (current->next != del && current->next != *head_ref) { // Traverse to find the node to delete
            current = current->next;
        }
        if (current->next == del) { // If we found the node to delete
            current->next = del->next; // Update the next pointer of the previous node
        }
    }
    
    free(del); // Free the memory allocated for the deleted node
}   
// Function to delete all nodes in the circular linked list
void deleteAllNodes(struct Node** head_ref) {
    if (*head_ref == NULL) { // Check if the list is empty
        return;
    }
    
    struct Node* current = *head_ref; // Start from the head of the list
    struct Node* next_node; // Pointer to store the next node
    
    do {
        next_node = current->next; // Store the next node
        free(current); // Free the memory allocated for the current node
        current = next_node; // Move to the next node
    } while (current != *head_ref); // Continue until we come back to the head
    
    *head_ref = NULL; // Set head to NULL after deleting all nodes
}

// Function to delete the last node in the circular linked list
void deleteLastNode(struct Node** head_ref) {
    if (*head_ref == NULL) { // Check if the list is empty
        return;
    }
    
    struct Node* current = *head_ref; // Start from the head of the list
    if (current->next == *head_ref) { // If there is only one node in the list
        free(current); // Free the memory allocated for the node
        *head_ref = NULL; // Set head to NULL
        return;
    }
    
    while (current->next->next != *head_ref) { // Traverse to find the second last node
        current = current->next;
    }
    
    free(current->next); // Free the memory allocated for the last node
    current->next = *head_ref; // Update the next pointer of the second last node to point to head
}

// Function to print the circular linked list
void printList(struct Node* head) {
    if (head == NULL) { // Check if the list is empty
        printf("List is empty.\n");
        return;
    }
    
    struct Node* current = head; // Start from the head of the list
    do {
        printf("%d -> ", current->data); // Print the data of the current node
        current = current->next; // Move to the next node
    } while (current != head); // Continue until we come back to the head
    printf("(head)\n"); // Indicate that we are back at the head
}

// Main function to demonstrate the deletion operations in a circular linked list
int main() {
    struct Node* head = createNode(1); // Create the first node with data 1
    head->next = head; // Point to itself to make it circular

    struct Node* second = createNode(2); // Create the second node with data 2
    head->next = second; // Link first node to second node
    second->next = head; // Make it circular

    struct Node* third = createNode(3); // Create the third node with data 3
    second->next = third; // Link second node to third node
    third->next = head; // Make it circular

    printf("Circular Linked List before deletion:\n");
    printList(head); // Print the list before deletion

    deleteNode(&head, second); // Delete the second node
    printf("Circular Linked List after deleting second node:\n");
    printList(head); // Print the list after deletion

    deleteLastNode(&head); // Delete the last node
    printf("Circular Linked List after deleting last node:\n");
    printList(head); // Print the list after deletion

    deleteAllNodes(&head); // Delete all nodes
    printf("Circular Linked List after deleting all nodes:\n");
    printList(head); // Print the list after deletion

    return 0; // Return success
}

