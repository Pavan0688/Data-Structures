#include <stdio.h>
#include <stdlib.h>

int compareIntegers(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}


void displayMissingElements(int arr[], int n) {
   
    qsort(arr, n, sizeof(int), compareIntegers);

    int minElement = arr[0];
    int maxElement = arr[n - 1];

    printf("Missing element(s): ");
    for (int i = minElement; i <= maxElement; i++) {
        int found = 0;
        for (int j = 0; j < n; j++) {
            if (arr[j] == i) {
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    int arr[] = {3, 7, 2, 10, 5}; 
    int n = sizeof(arr) / sizeof(arr[0]);

    displayMissingElements(arr, n);

    return 0;
}

