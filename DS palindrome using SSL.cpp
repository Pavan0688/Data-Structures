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

bool isPalindrome(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        return true;
    }

    int size = 0;
    struct Node* current = head;
    while (current != NULL) {
        size++;
        current = current->next;
    }
    int* arr = (int*)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    current = head;
    for (int i = 0; i < size; i++) {
        arr[i] = current->data;
        current = current->next;
    }
    for (int i = 0, j = size - 1; i < j; i++, j--) {
        if (arr[i] != arr[j]) {
            free(arr);
            return false;
        }
    }

    free(arr);
    return true;
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

    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(2);
    head->next->next->next->next = createNode(1);

    bool isPalin = isPalindrome(head);

    if (isPalin) {
        printf("The linked list is a palindrome.\n");
    } else {
        printf("The linked list is not a palindrome.\n");
    }

    freeLinkedList(head);

    return 0;
}

