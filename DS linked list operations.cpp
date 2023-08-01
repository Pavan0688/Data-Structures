#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int data) { 
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
void deleteNode(struct Node** head, int key) {
    if (*head == NULL) {
        printf("Linked list is empty!\n");
        return;
    }
	struct Node* prev = NULL;
    struct Node* current = *head;
	if (current != NULL && current->data == key) {
        *head = current->next;
        free(current);
        return;
    }
	while (current != NULL && current->data != key) {
        prev = current;
        current = current->next;
    }
	if (current == NULL) {
        printf("Key not found in the linked list!\n");
        return;
    }
	prev->next = current->next;
    free(current);
}
void display(struct Node* head) {
    struct Node* current = head;
    if (current == NULL) {
        printf("Linked list is empty!\n");
        return;
    }
	printf("Linked list elements: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
void freeLinkedList(struct Node** head) {
    struct Node* current = *head;
    struct Node* temp;
    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }
    *head = NULL;
}
int main() {
    struct Node* head = NULL;
	insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);
	display(head);
	deleteNode(&head, 3);
    display(head);
	deleteNode(&head, 5);
    display(head);
	freeLinkedList(&head);
	return 0;
}

