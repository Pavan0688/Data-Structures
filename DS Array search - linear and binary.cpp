#include <stdio.h>

int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i; 
        }
    }
    return -1; 
}

int binarySearch(int arr[], int low, int high, int key) {
    while (low <= high) {
        int mid = (low + high) / 2;

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
    int arr[] = {5, 2, 8, 1, 6, 3, 7, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 6;

    int linearResult = linearSearch(arr, n, key);

    if (linearResult != -1) {
        printf("Element %d found at index %d using linear search.\n", key, linearResult);
    } else {
        printf("Element %d not found in the array using linear search.\n", key);
    }

    int temp, i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    int binaryResult = binarySearch(arr, 0, n - 1, key);

    if (binaryResult != -1) {
        printf("Element %d found at index %d using binary search.\n", key, binaryResult);
    } else {
        printf("Element %d not found in the array using binary search.\n", key);
    }

    return 0;
}

