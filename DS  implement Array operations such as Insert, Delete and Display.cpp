#include <stdio.h>

#define MAX_SIZE 100
void display(int arr[], int size) {
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int insert(int arr[], int size, int position, int element) {
    if (size >= MAX_SIZE) {
        printf("Array is full, cannot insert element.\n");
        return size;
    }

    if (position < 0 || position > size) {
        printf("Invalid position to insert.\n");
        return size;
    }

    for (int i = size; i > position; i--) {
        arr[i] = arr[i - 1];
    }

    arr[position] = element;
    return size + 1;
}
int deleteElement(int arr[], int size, int position) {
    if (size == 0) {
        printf("Array is empty, cannot delete element.\n");
        return size;
    }

    if (position < 0 || position >= size) {
        printf("Invalid position to delete.\n");
        return size;
    }

    for (int i = position; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    return size - 1;
}

int main() {
    int arr[MAX_SIZE];
    int size = 0;
    int choice, element, position;

    do {
        printf("\nArray Operations:\n");
        printf("1. Insert an element\n");
        printf("2. Delete an element\n");
        printf("3. Display the array\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d", &element);
                printf("Enter the position to insert (0-%d): ", size);
                scanf("%d", &position);
                size = insert(arr, size, position, element);
                break;
            case 2:
                printf("Enter the position to delete (0-%d): ", size - 1);
                scanf("%d", &position);
                size = deleteElement(arr, size, position);
                break;
            case 3:
                display(arr, size);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

