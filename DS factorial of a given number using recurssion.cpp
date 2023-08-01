#include <stdio.h>

unsigned long long int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
    int num;
    printf("Enter a number to find its factorial: ");
    scanf("%d", &num);
    
    if (num < 0) {
        printf("Factorial of negative numbers is not defined.\n");
    } else {
        unsigned long long int fact = factorial(num);
        printf("Factorial of %d is %llu\n", num, fact);
    }
    
    return 0;
}

