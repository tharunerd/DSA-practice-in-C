// checking for loops in a linked list
#include <stdio.h>      
#include <stdlib.h>
#include <stdbool.h>
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
bool hasLoop(struct Node* head) {
    struct Node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;          // Move slow by 1 step
        fast = fast->next->next;   // Move fast by 2 steps
        if (slow == fast) {        // If they meet, there is a loop
            return true;
        }
    }
    return false;                 // No loop found
}
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main() {
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    
    // Creating a loop for testing
    head->next->next->next->next = head->next; // 4 points to 2

    if (hasLoop(head)) {
        printf("The linked list has a loop.\n");
    } else {
        printf("The linked list does not have a loop.\n");
    }

    // Free memory (not shown for simplicity)
    
    return 0;
}
