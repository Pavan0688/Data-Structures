#include <stdio.h>

int main() {
    
    int givenElements[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    int numElements = sizeof(givenElements) / sizeof(givenElements[0]);

    if (numElements >= 5) {
        
        printf("The 5th element is: %d\n", givenElements[4]);
    } else {
        printf("The array does not have enough elements to access the 5th element.\n");
    }

    return 0;
}

