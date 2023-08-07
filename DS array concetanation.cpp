#include <stdio.h>
#include <stdlib.h>

int* concatenateArrays(const int arr1[], int size1, const int arr2[], int size2) {
    int newSize = size1 + size2;
    int* concatenatedArray = (int*)malloc(newSize * sizeof(int));

    if (concatenatedArray == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    for (int i = 0; i < size1; i++) {
        concatenatedArray[i] = arr1[i];
    }

    for (int i = 0; i < size2; i++) {
        concatenatedArray[size1 + i] = arr2[i];
    }

    return concatenatedArray;
}

int main() {
    int arr1[] = {1, 2, 3};
    int arr2[] = {4, 5, 6};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    int* result = concatenateArrays(arr1, size1, arr2, size2);

    printf("Concatenated Array: ");
    for (int i = 0; i < size1 + size2; i++) {
        printf("%d ", result[i]);
    }
    free(result);

    return 0;
}

