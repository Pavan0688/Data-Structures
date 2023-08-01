#include <stdio.h>

void fibonacci(int n) {
    int prev = 0, curr = 1;
    
    printf("Fibonacci series up to %d terms:\n", n);
    printf("%d ", prev);
    
    for (int i = 1; i < n; i++) {
        printf("%d ", curr);
        int next = prev + curr;
        prev = curr;
        curr = next;
    }
    
    printf("\n");
}

int main() {
    int num;
    printf("Enter the number of terms in the Fibonacci series: ");
    scanf("%d", &num);
    
    if (num <= 0) {
        printf("Invalid input. Number of terms should be greater than 0.\n");
    } else {
        fibonacci(num);
    }
    
    return 0;
}

