#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }

    if (key < root->data) {
        return search(root->left, key);
    }

    return search(root->right, key);
}

struct Node* findMin(struct Node* root) {
    if (root == NULL) {
        return NULL;
    }

    while (root->left != NULL) {
        root = root->left;
    }

    return root;
}

struct Node* findMax(struct Node* root) {
    if (root == NULL) {
        return NULL;
    }

    while (root->right != NULL) {
        root = root->right;
    }

    return root;
}

void inorderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }

    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

int main() {
    struct Node* root = NULL;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    int key = 60;
    struct Node* searchResult = search(root, key);
    if (searchResult != NULL) {
        printf("Element %d found in the BST.\n", key);
    } else {
        printf("Element %d not found in the BST.\n", key);
    }

    struct Node* minElement = findMin(root);
    if (minElement != NULL) {
        printf("Minimum element in the BST: %d\n", minElement->data);
    } else {
        printf("BST is empty.\n");
    }

    struct Node* maxElement = findMax(root);
    if (maxElement != NULL) {
        printf("Maximum element in the BST: %d\n", maxElement->data);
    } else {
        printf("BST is empty.\n");
    }


    printf("Inorder traversal of the BST: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}

