#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;          // Data part of the node
    struct node *next; // Pointer to the next node
};
// Function to create a new node with given data        

struct node *createNode(int value)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node)); // Allocate memory for a new node
    if (newNode == NULL) // Check if memory allocation was successful
    {
        printf("Memory allocation failed\n");
        exit(1); // Exit the program if memory allocation fails
    }
    newNode->data = value; // Set the data of the new node
    newNode->next = NULL;  // Initialize the next pointer to NULL
    return newNode;        // Return the newly created node
}
// Function to add a new node at the end of the linked list
struct node *addNodeAtEnd(struct node *head, int value)
{
    struct node *newNode = createNode(value); // Create a new node with the given value
    if (head == NULL) // If the list is empty, make the new node the head
    {
        return newNode;
    }
    struct node *current = head; // Start from the head of the list
    while (current->next != NULL) // Traverse to the last node
    {
        current = current->next; // Move to the next node
    }
    current->next = newNode; // Link the last node to the new node
    return head;            // Return the head of the list
}
// Function to print the linked list
void printList(struct node *head)
{
    struct node *current = head; // Start from the head of the list
    while (current != NULL) // Traverse the list until the end
    {
        printf("%d -> ", current->data); // Print the data of the current node
        current = current->next;          // Move to the next node
    }
    printf("NULL\n"); // Indicate the end of the list
}

void sum_of_nodes(struct node *head)
{
    int sum = 0; // Initialize sum to 0
    struct node *current = head; // Start from the head of the list
    while (current != NULL) // Traverse the list until the end
    {
        sum += current->data; // Add the data of the current node to sum
        current = current->next; // Move to the next node
    }
    printf("Sum of nodes: %d\n", sum); // Print the total sum of nodes
}

// Main function to demonstrate the linked list operations
int main()
{
    struct node *head = NULL; // Initialize the head of the list to NULL

    // Add nodes to the linked list
    head = addNodeAtEnd(head, 1); // Add node with data 1
    head = addNodeAtEnd(head, 2); // Add node with data 2
    head = addNodeAtEnd(head, 3); // Add node with data 3
    head = addNodeAtEnd(head, 5);

    printList(head); // Print the linked list
    sum_of_nodes(head); // Print the sum of nodes
    return 0; // Return success
}


