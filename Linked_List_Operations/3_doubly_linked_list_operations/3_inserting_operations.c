// inserting data in doubly linked list
 #include <stdio.h>
#include <stdlib.h>

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

// Function to insert a new node at the beginning of the doubly linked list
void insertAtBeginning(struct Node** head_ref, int new_data) {
    struct Node* new_node = createNode(new_data); // Create a new node
    new_node->next = *head_ref; // Link the new node to the current head
    if (*head_ref != NULL) { // If the list is not empty
        (*head_ref)->prev = new_node; // Set the previous pointer of the current head
    }
    *head_ref = new_node; // Update head to point to the new node
}
// Function to insert a new node after a given node in the doubly linked list
void insertAfter(struct Node* prev_node, int new_data) {
    if (prev_node == NULL) { // Check if the previous node is NULL
        printf("The given previous node cannot be NULL.\n");
        return;
    }
    struct Node* new_node = createNode(new_data); // Create a new node
    new_node->next = prev_node->next; // Link the new node to the next of prev_node
    prev_node->next = new_node; // Link prev_node to the new node
    new_node->prev = prev_node; // Set the previous pointer of the new node
    if (new_node->next != NULL) { // If there is a next node
        new_node->next->prev = new_node; // Set the previous pointer of the next node
    }
}

// Function to insert a new node before a given node in the doubly linked list
void insertbefore(struct Node** head_ref, struct Node* next_node, int new_data) {
    if (next_node == NULL) { // Check if the next node is NULL
        printf("The given next node cannot be NULL.\n");
        return;
    }
    struct Node* new_node = createNode(new_data); // Create a new node
    new_node->next = next_node; // Link the new node to the next node
    new_node->prev = next_node->prev; // Link the new node to the previous of next node
    if (next_node->prev != NULL) { // If there is a previous node
        next_node->prev->next = new_node; // Set the next pointer of the previous node
    } else {
        *head_ref = new_node; // If there is no previous node, update head
    }
    next_node->prev = new_node; // Set the previous pointer of the next node
}


// Function to insert a new node at a given index in the doubly linked list
void insertAtIndex(struct Node** head_ref, int index, int new_data) {
    if (index < 0) { // Check if the index is negative
        printf("Index cannot be negative.\n");
        return;
    }
    if (index == 0) { // If index is 0, insert at the beginning
        insertAtBeginning(head_ref, new_data);
        return;
    }
    struct Node* new_node = createNode(new_data); // Create a new node
    struct Node* current = *head_ref; // Start from the head
    for (int i = 0; current != NULL && i < index - 1; i++) { // Traverse to the node before the index
        current = current->next;
    }
    if (current == NULL) { // If we reached the end of the list
        printf("Index out of bounds. Inserting at the end.\n");
        insertAtEnd(head_ref, new_data);
        return;
    }
    new_node->next = current->next; // Link the new node to the next of current
    current->next = new_node; // Link current to the new node
    new_node->prev = current; // Set the previous pointer of the new node
    if (new_node->next != NULL) { // If there is a next node
        new_node->next->prev = new_node; // Set the previous pointer of the next node
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
// Main function to demonstrate the insertion operations in a doubly linked list
int main() {
    struct Node* head = NULL; // Initialize the head of the list

    // Insert elements at the end
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    printf("List after inserting at end:\n");
    printList(head);

    // Insert an element at the beginning
    insertAtBeginning(&head, 5);
    printf("List after inserting at beginning:\n");
    printList(head);

    // Insert an element after a given node
    insertAfter(head->next, 15); // Insert after the second node (20)
    printf("List after inserting after a node:\n");
    printList(head);

    // Insert an element at a specific index
    insertAtIndex(&head, 2, 12); // Insert at index 2
    printf("List after inserting at index 2:\n");
    printList(head);

    // Insert an element before a given node
    insertbefore(&head, head->next->next, 18); // Insert before the
    printf("List after inserting before a node:\n");
    printList(head);
    return 0; // Return success
}
// This code demonstrates how to insert nodes in a doubly linked list at various positions:

