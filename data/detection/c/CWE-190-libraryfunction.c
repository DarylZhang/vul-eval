#include <stdio.h>
#include <stdlib.h>

int calculateTotal(char *input) {
    // CWE-190: Integer overflow risk here
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
    int result = calculateTotal(input);
    printf("Final total: %d\n", result);
    return 0;
}