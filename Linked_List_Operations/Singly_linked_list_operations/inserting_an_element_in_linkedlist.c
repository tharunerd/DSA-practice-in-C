#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    int data;          // Data part of the node
    struct node *next; // Pointer to the next node
};

void insertAtBeginning(struct node **head_ref, int new_data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node)); // Allocate memory for a new node
    new_node->data = new_data; // Set the data of the new node
    new_node->next = (*head_ref); // Link the new node to the current head
    (*head_ref) = new_node; // Update the head to point to the new node
}

void insert_anywhere(struct node **head_ref, int new_data, int position)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node)); // Allocate memory for a new node
    new_node->data = new_data; // Set the data of the new node
    if (position == 0) // If position is 0, insert at the beginning
    {
        new_node->next = (*head_ref); // Link the new node to the current head
        (*head_ref) = new_node; // Update the head to point to the new node
        return;
    }
    struct node *temp = *head_ref; // Start from the head of the list
    for (int i = 0; temp != NULL && i < position - 1; i++) // Traverse to the position before where we want to insert
        temp = temp->next;
    if (temp == NULL) // If we reached the end of the list before reaching the desired position
    {
        printf("The previous node is null\n");
        return;
    }
    new_node->next = temp->next; // Link the new node to the next node
    temp->next = new_node; // Link the previous node to the new node
}


int main ()

{
    struct node *head = NULL; // Initialize the head of the list to NULL
    insertAtBeginning(&head, 1); // Insert 1 at the beginning
    insertAtBeginning(&head, 2); // Insert 2 at the beginning
    insertAtBeginning(&head, 3); // Insert 3 at the beginning
    printf("Linked list after inserting elements at the beginning:\n");
    struct node *temp = head; // Start from the head of the list
    while (temp != NULL) // Traverse the list until the end
    {
        printf("%d -> ", temp->data); // Print the data of the current node
        temp = temp->next; // Move to the next node
    }
    printf("NULL\n"); // Indicate the end of the list

    insert_anywhere(&head, 4, 1); // Insert 4 at position 1
    printf("Linked list after inserting element at position 1:\n");
    temp = head; // Start from the head of the list
    while (temp != NULL) // Traverse the list until the end
    {
        printf("%d -> ", temp->data); // Print the data of the current node
        temp = temp->next; // Move to the next node
    }
    printf("NULL\n"); // Indicate the end of the list

    return 0; // Return success
}