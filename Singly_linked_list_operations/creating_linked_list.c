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
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node)); // Allocate memory
    newNode->data = value;                                             // Assign value to the node
    newNode->next = NULL;                                              // Initialize next as NULL
    return newNode;
}
// Function to print the linked list
void printList(struct Node *head)
{
    struct Node *current = head; // Start from the head node
    printf("Linked List: ");
    while (current != NULL)
    {
        printf("%d -> ", current->data); // Print data of current node
        current = current->next;         // Move to next node
    }
    printf("NULL\n"); // End of list
}
int main()
{
    // Step 1: Create individual nodes
    struct Node *head = createNode(10);   // First node (head)
    struct Node *second = createNode(20); // Second node
    struct Node *third = createNode(30);  // Third node
    // Step 2: Link the nodes together
    head->next = second;  // First node points to second
    second->next = third; // Second node points to third
    // Step 3: Print the linked list
    printList(head);
    return 0;
}
