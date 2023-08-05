#include <stdio.h>
#include <stdlib.h>

int compareAscending(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int compareDescending(const void* a, const void* b) {
    return (*(int*)b - *(int*)a);
}

int main() {
    int arr[] = {5, 2, 8, 1, 6, 3, 7, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    qsort(arr, n, sizeof(int), compareAscending);

    printf("Array in ascending order: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

  
    qsort(arr, n, sizeof(int), compareDescending);

    printf("Array in descending order: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

