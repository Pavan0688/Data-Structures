#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode* next;
};

struct ListNode* createNode(int data) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct ListNode* mergeLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* mergedList = NULL;
    struct ListNode* tail = NULL;

    if (list1 == NULL)
        return list2;
    if (list2 == NULL)
        return list1;

    if (list1->data <= list2->data) {
        mergedList = list1;
        list1 = list1->next;
    } else {
        mergedList = list2;
        list2 = list2->next;
    }

    tail = mergedList;

    while (list1 != NULL && list2 != NULL) {
        if (list1->data <= list2->data) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }

    if (list1 != NULL)
        tail->next = list1;
    if (list2 != NULL)
        tail->next = list2;

    return mergedList;
}

void printList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct ListNode* list1 = createNode(1);
    list1->next = createNode(3);
    list1->next->next = createNode(5);

    struct ListNode* list2 = createNode(2);
    list2->next = createNode(4);
    list2->next->next = createNode(6);

    printf("List 1: ");
    printList(list1);

    printf("List 2: ");
    printList(list2);

    struct ListNode* mergedList = mergeLists(list1, list2);

    printf("Merged List: ");
    printList(mergedList);

    return 0;
}

