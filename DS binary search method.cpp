#include <stdio.h>

int binarySearch(int arr[], int size, int key) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            return mid; 
        } else if (arr[mid] < key) {
            low = mid + 1; 
        } else {
            high = mid - 1; 
        }
    }

    return -1; 
}

int main() {
    int arr[] = {5, 10, 15, 20, 25, 30, 35, 40};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key;

    printf("Enter the number to search: ");
    scanf("%d", &key);

    int index = binarySearch(arr, size, key);

    if (index != -1) {
        printf("%d found at index %d.\n", key, index);
    } else {
        printf("%d not found in the array.\n", key);
    }

    return 0;
}

