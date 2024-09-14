#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>

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

int main() {
    char input[] = "9999999999";

    char *ptr = input;
    while (*ptr) {
        if (!isdigit(*ptr)) {
            printf("Error: Invalid input detected.\n");
            return 0;
        }
        ptr++;
    }

    long totalCheck = atol(input);

    if (totalCheck > INT_MAX || totalCheck < INT_MIN) {
        printf("Error: Value out of range for int type.\n");
        return 0;
    }

    int result = calculateTotal(input);
    printf("Final total: %d\n", result);

    return 0;
}