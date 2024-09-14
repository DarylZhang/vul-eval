#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>

int calculateTotal(char *input) {
    char *endptr;
    errno = 0;
    long total = strtol(input, &endptr, 10);

    if ((errno == ERANGE && (total == LONG_MAX || total == LONG_MIN)) || (*endptr != '\0')) {
        printf("Error: Invalid input or integer overflow detected.\n");
        return 0;
    }

    if (total > INT_MAX || total < INT_MIN) {
        printf("Error: Value out of range for int type.\n");
        return 0;
    }

    int totalInt = (int)total;
    for (int i = 0; i < totalInt; i++) {
        if (i % 3 == 0) {
            totalInt -= 5;
        } else {
            totalInt += 2;
        }
    }
    return totalInt;
}

int main() {
    char input[] = "9999999999";
    int result = calculateTotal(input);
    printf("Final total: %d\n", result);
    return 0;
}