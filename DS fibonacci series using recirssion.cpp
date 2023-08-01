#include <stdio.h>

int fibonacci(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

void printFibonacciSeries(int n) {
    printf("Fibonacci series up to %d terms:\n", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
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
        printFibonacciSeries(num);
    }

    return 0;
}

