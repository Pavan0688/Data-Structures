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

struct Node* getIntersection(struct Node* list1, struct Node* list2) {

    bool* visited = (bool*)calloc(sizeof(bool), sizeof(bool));

    struct Node* current = list1;
    while (current != NULL) {
        visited[(size_t)current] = true;
        current = current->next;
    }

    current = list2;
    while (current != NULL) {
        if (visited[(size_t)current]) {
            free(visited);
            return current; 
        }
        current = current->next;
    }

    free(visited); 
    return NULL; 
}

void freeLinkedList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
   
    struct Node* list1 = createNode(1);
    list1->next = createNode(2);
    list1->next->next = createNode(3);
    list1->next->next->next = createNode(4);

    struct Node* list2 = createNode(6);
    list2->next = createNode(7);
    list2->next->next = createNode(8);
    list2->next->next->next = list1->next->next; 
    struct Node* intersectionNode = getIntersection(list1, list2);

    if (intersectionNode != NULL) {
        printf("Intersection found at node with data: %d\n", intersectionNode->data);
    } else {
        printf("No intersection found.\n");
    }

    freeLinkedList(list1);
    freeLinkedList(list2);

    return 0;
}

