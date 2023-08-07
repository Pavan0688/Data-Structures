#include <stdio.h>
#include <string.h>

int main() {
    const char haystack[] = "This is a haystack string.";
    const char needle[] = "haystack";

    char *result = strstr(haystack, needle);

    if (result != NULL) {
        printf("Substring found at index: %ld\n", result - haystack);

    } else {
        printf("Substring not found.\n");
    }

    return 0;
}

