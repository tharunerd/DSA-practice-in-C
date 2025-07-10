// finding duplicate elements in a linked list
#include <stdio.h>  
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
// Function to push a new node with given data at the beginning of the list
void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void findduplicates(struct Node* head) {
    struct Node* current = head;
    struct Node* next_next;

    // Traverse the list
    while (current != NULL && current->next != NULL) {
        // If current node's data is equal to the next node's data
        if (current->data == current->next->data) {
            // Store the next node
            next_next = current->next->next;
            // Free the duplicate node
            free(current->next);
            // Unlink the duplicate node
            current->next = next_next;
        } else {
            // Move to the next node
            current = current->next;
        }
    }
}

void printDuplicates(struct Node* head) {
    struct Node* current = head;
    int lastDuplicate = -1; // Assumes all list values are non-negative; adjust as needed

    while (current != NULL && current->next != NULL) {
        if (current->data == current->next->data && current->data != lastDuplicate) {
            printf("%d ", current->data);
            lastDuplicate = current->data;
        }
        current = current->next;
    }
    printf("\n");
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}
int main() {
    struct Node* head = NULL;

    // Create a linked list 1->2->2->3->4->4->5
    push(&head, 5);
    push(&head, 4);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 2);
    push(&head, 1);

    printf("Created Linked List: ");
    printList(head);

    printf("Duplicate elements are: ");
    printDuplicates(head);

    return 0;
}
