#include <stdio.h>

int searchRegNo(int arr[], int size, int targetRegNo) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == targetRegNo) {
            return i;
        }
    }
    return -1; 
}

int main() {
    int regNumbers[] = {12345, 56789, 98765, 43210, 67890};
    int size = sizeof(regNumbers) / sizeof(regNumbers[0]);
    int targetRegNo;

    printf("Enter the reg no you want to search for: ");
    scanf("%d", &targetRegNo);

    int foundIndex = searchRegNo(regNumbers, size, targetRegNo);

    if (foundIndex != -1) {
        printf("Reg no %d found at index %d.\n", targetRegNo, foundIndex);
    } else {
        printf("Reg no %d not found in the array.\n", targetRegNo);
    }

    return 0;
}

