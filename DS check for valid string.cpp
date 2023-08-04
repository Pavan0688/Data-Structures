#include <stdio.h>
#include <stdbool.h>


bool isValidString(const char* str) {
    if (str == NULL) 
        return false;

    for (int i = 0; str[i] != '\0'; i++) {

        if (!(str[i] >= 'a' && str[i] <= 'z') && !(str[i] >= 'A' && str[i] <= 'Z') && !(str[i] >= '0' && str[i] <= '9')) {
            return false;
        }
    }
    
    return true;
}

int main() {
    char inputString[100];

    printf("Enter a string: ");
    scanf("%s", inputString);

    if (isValidString(inputString)) {
        printf("The string is valid.\n");
    } else {
        printf("The string is not valid.\n");
    }

    return 0;
}

