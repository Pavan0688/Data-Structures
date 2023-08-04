#include <stdio.h>
#include <limits.h>

int reverse(int x) {
    int sign = x < 0 ? -1 : 1;
    int abs_x = x * sign;
    int reversed = 0;

    while (abs_x > 0) {
        if (reversed > INT_MAX / 10 || (reversed == INT_MAX / 10 && abs_x % 10 > INT_MAX % 10)) {
            return 0;
        }

        reversed = reversed * 10 + abs_x % 10;
        abs_x /= 10;
    }

    return reversed * sign;
}

int main() {
    int num = 12345;
    int reversed_num = reverse(num);

    printf("Original number: %d\n", num);
    printf("Reversed number: %d\n", reversed_num);

    return 0;
}

