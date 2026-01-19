// deleting operstions in doubly linked list

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

// function to delete the first node with a given value from the doubly linked list
void deleteNodeByValue(struct Node** head_ref, int value) {
    struct Node* current = *head_ref; // Start from the head of the list
    while (current != NULL) { // Traverse the list
        if (current->data == value) { // If the current node has the value to delete
            if (current->prev != NULL) { // If there is a previous node
                current->prev->next = current->next; // Update the next pointer of the previous node
            } else { // If there is no previous node, it means we are deleting the head
                *head_ref = current->next; // Update head to the next node
            }
            if (current->next != NULL) { // If there is a next node
                current->next->prev = current->prev; // Update the previous pointer of the next node
            }
            free(current); // Free the memory allocated for the deleted node
            return; // Exit after deleting the first occurrence
        }
        current = current->next; // Move to the next node
    }
}

void deleteNodeByIndex(struct Node** head_ref, int index) {
    if (*head_ref == NULL || index < 0) { // Check if the list is empty or index is negative
        return;
    }
    
    struct Node* current = *head_ref; // Start from the head of the list
    for (int i = 0; current != NULL && i < index; i++) { // Traverse to the node at the given index
        current = current->next;
    }
    
    if (current == NULL) { // If we reached the end of the list without finding the index
        return;
    }
    
    // Now 'current' points to the node to be deleted
    if (current->prev != NULL) { // If there is a previous node
        current->prev->next = current->next; // Update the next pointer of the previous node
    } else { // If there is no previous node, it means we are deleting the head
        *head_ref = current->next; // Update head to the next node
    }
    
    if (current->next != NULL) { // If there is a next node
        current->next->prev = current->prev; // Update the previous pointer of the next node
    }
    
    free(current); // Free the memory allocated for the deleted node
}

void deleteAllNodes(struct Node** head_ref) {
    struct Node* current = *head_ref; // Start from the head of the list
    struct Node* next_node; // Pointer to store the next node
    
    while (current != NULL) { // Traverse the list
        next_node = current->next; // Store the next node
        free(current); // Free the memory allocated for the current node
        current = next_node; // Move to the next node
    }
    
    *head_ref = NULL; // Set head to NULL after deleting all nodes
}
void deleteLastNode(struct Node** head_ref) {
    if (*head_ref == NULL) { // Check if the list is empty
        return;
    }
    
    struct Node* current = *head_ref; // Start from the head of the list
    while (current->next != NULL) { // Traverse to the last node
        current = current->next;
    }
    
    // Now 'current' points to the last node
    if (current->prev != NULL) { // If there is a previous node
        current->prev->next = NULL; // Update the next pointer of the previous node to NULL
    } else { // If there is no previous node, it means we are deleting the head
        *head_ref = NULL; // Set head to NULL
    }
    
    free(current); // Free the memory allocated for the last node
}


// Function to delete a node from the doubly linked list
void deleteNode(struct Node** head_ref, struct Node* del) {
    if (*head_ref == NULL || del == NULL) { // Check if the list or node to delete is NULL
        return;
    }
    
    if (*head_ref == del) { // If the node to delete is the head
        *head_ref = del->next; // Update head to the next node
    }
    
    if (del->next != NULL) { // If there is a next node
        del->next->prev = del->prev; // Update the previous pointer of the next node
    }
    
    if (del->prev != NULL) { // If there is a previous node
        del->prev->next = del->next; // Update the next pointer of the previous node
    }
    
    free(del); // Free the memory allocated for the deleted node
}
// Function to print the doubly linked list
void printList(struct Node* node) {
    while (node != NULL) { // Traverse the list
        printf("%d ", node->data); // Print the data of the current node
        node = node->next; // Move to the next node
    }
    printf("\n"); // Print a newline at the end
}
