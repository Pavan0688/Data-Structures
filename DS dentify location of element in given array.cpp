#include <stdio.h>

int findElementIndex(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; 
        }
    }
    return -1; 
}

int main() {
    int numbers[] = {10, 20, 30, 40, 50};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    int targetElement;

    printf("Enter the element you want to find: ");
    scanf("%d", &targetElement);

    int foundIndex = findElementIndex(numbers, size, targetElement);

    if (foundIndex != -1) {
        printf("Element %d found at index %d.\n", targetElement, foundIndex);
    } else {
        printf("Element %d not found in the array.\n", targetElement);
    }

    return 0;
}

