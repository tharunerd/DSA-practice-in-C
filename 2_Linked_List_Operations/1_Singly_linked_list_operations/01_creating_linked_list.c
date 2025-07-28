#include <stdio.h>
#include <stdlib.h>
// Define the structure for a node in the linked list
struct Node
{
    int data;          // Data part of the node
    struct Node *next; // Pointer to the next node
};

// Function to create a new node with given data
struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node)); // Allocate memory for a new node
    newNode->data = value; // Set the data of the new node
    newNode->next = NULL;  // Initialize the next pointer to NULL
    return newNode;        // Return the newly created node
}

void printList(struct Node *head)
{
    struct Node *current = head; // Start from the head of the list
    while (current != NULL) // Traverse the list until the end
    {
        printf("%d -> ", current->data); // Print the data of the current node
        current = current->next;          // Move to the next node
    }
}

int main()
{
    struct Node *head = createNode(1); // Create the first node with data 1
    struct Node *second = createNode(2); // Create the second node with data 2
    struct Node *third = createNode(3);  // Create the third node with data 3

    // Link the nodes together to form a linked list
    head->next = second; // Link first node with second node
    second->next = third; // Link second node with third node

    printList(head); // Print the linked list

    return 0; // Return success
}