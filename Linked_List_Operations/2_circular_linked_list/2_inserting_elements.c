// inserting elements in a circular linked list
#include <stdio.h>  
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void insertAtBeginning(struct Node** head_ref, int new_data) {
    struct Node* new_node = createNode(new_data);
    if (*head_ref == NULL) {
        *head_ref = new_node;
        new_node->next = *head_ref; // Point to itself
    } else {
        struct Node* temp = *head_ref;
        while (temp->next != *head_ref) {
            temp = temp->next; // Traverse to the last node
        }
        temp->next = new_node; // Link the new node at the end
        new_node->next = *head_ref; // Make it circular
        *head_ref = new_node; // Update head to point to the new node
    }
}
void insertAtEnd(struct Node** head_ref, int new_data) {
    struct Node* new_node = createNode(new_data);
    if (*head_ref == NULL) {
        *head_ref = new_node;
        new_node->next = *head_ref; // Point to itself
    } else {
        struct Node* temp = *head_ref;
        while (temp->next != *head_ref) {
            temp = temp->next; // Traverse to the last node
        }
        temp->next = new_node; // Link the new node at the end
        new_node->next = *head_ref; // Make it circular
    }
}
void insertAfter(struct Node* prev_node, int new_data) {
    if (prev_node == NULL) {
        printf("The given previous node cannot be NULL.\n");
        return;
    }
    struct Node* new_node = createNode(new_data);
    new_node->next = prev_node->next; // Link the new node to the next of prev_node
    prev_node->next = new_node; // Link prev_node to the new node
}

void insert_at_given_index(struct Node** head_ref, int index, int new_data) {
    if (index < 0) {
        printf("Index cannot be negative.\n");
        return;
    }
    struct Node* new_node = createNode(new_data);
    if (index == 0) {
        insertAtBeginning(head_ref, new_data);
        return;
    }
    struct Node* temp = *head_ref;
    for (int i = 0; i < index - 1 && temp->next != *head_ref; i++) {
        temp = temp->next; // Traverse to the node before the desired index
    }
    new_node->next = temp->next; // Link the new node to the next of temp
    temp->next = new_node; // Link temp to the new node
}

void printCircularLinkedList(struct Node* head) {
    if (head == NULL) return;
    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");
}
int main() {
    struct Node* head = NULL;

    // Insert elements at the beginning
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 1);
    printf("Circular Linked List after inserting at beginning:\n");
    printCircularLinkedList(head);

    // Insert elements at the end
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);
    printf("Circular Linked List after inserting at end:\n");
    printCircularLinkedList(head);
    // Insert at a specific index
    insert_at_given_index(&head, 2, 10); // Insert 10 at index 2
    printf("Circular Linked List after inserting 10 at index 2:\n");

    // Insert after a specific node (in this case, after node with data 2)
    struct Node* temp = head;
    while (temp->data != 2 && temp->next != head) {
        temp = temp->next; // Find the node with data 2
    }
    if (temp->data == 2) {
        insertAfter(temp, 6); // Insert 6 after node with data 2
        printf("Circular Linked List after inserting after node with data 2:\n");
        printCircularLinkedList(head);
    } else {
        printf("Node with data 2 not found.\n");
    }

    return 0;
}
// Note: Freeing memory is not shown for simplicity, but it is recommended to free the nodes when done.