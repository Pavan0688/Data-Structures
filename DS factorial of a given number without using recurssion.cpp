#include <stdio.h>

unsigned long long int factorial(int n) {
    unsigned long long int result = 1;
    
    if (n < 0) {
        return 0; 
    }
    
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    
    return result;
}

int main() {
    int num;
    printf("Enter a number to find its factorial: ");
    scanf("%d", &num);
    
    unsigned long long int fact = factorial(num);
    printf("Factorial of %d is %llu\n", num, fact);
    
    return 0;
}

