#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

int calculateTotal(char *input);

int main() {
    char input[] = "9999999999";

    char *endptr;
    errno = 0;

    // Fix CWE-190: Check for integer overflow before passing to calculateTotal
    long total_long = strtol(input, &endptr, 10);

    if (errno != 0 || *endptr != '\0' || total_long > INT_MAX || total_long < INT_MIN) {
        printf("Error: Invalid input or integer overflow occurred.\n");
        return 1;
    }

    int result = calculateTotal(input);
    printf("Final total: %d\n", result);
    return 0;
}

int calculateTotal(char *input) {

    int total = atoi(input);

    for (int i = 0; i < total; i++) {
        if (i % 3 == 0) {
            total -= 5;
        } else {
            total += 2;
        }
    }
    return total;
}