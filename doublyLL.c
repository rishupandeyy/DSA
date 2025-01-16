#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the front of the list
void insertAtHead(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    *head = newNode;
}

// Function to insert a node at the end of the list
void insertAtTail(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Function to delete a node from the list
void deleteNode(struct Node** head, struct Node* delNode) {
    if (*head == NULL || delNode == NULL) return;
    
    if (*head == delNode) *head = delNode->next;
    if (delNode->next != NULL) delNode->next->prev = delNode->prev;
    if (delNode->prev != NULL) delNode->prev->next = delNode->next;
    
    free(delNode);
}

// Function to display the list from head to tail
void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    struct Node* head = NULL;
    
    insertAtHead(&head, 10);
    insertAtHead(&head, 20);
    insertAtTail(&head, 30);
    insertAtTail(&head, 40);
    
    printf("Doubly linked list: ");
    displayList(head);
    
    deleteNode(&head, head->next);  // Deletes the second node (20)
    
    printf("After deletion: ");
    displayList(head);
    
    return 0;
}
