#include <stdio.h>
#include <limits.h>

unsigned int computeSum(unsigned int n) {
    unsigned int sum = 0;
    for (unsigned int i = 0; i <= n; i++) {
        sum += i;
        if (i % 3 == 0) {
            sum -= 5;
        } else {
            sum += 2;
        }
    }
    return sum;
}

int main() {
    unsigned int n = UINT_MAX;

    if (n == UINT_MAX) {
        printf("Warning: Input too large, adjusting value to prevent overflow.\n");
        n = UINT_MAX - 1;
    }

    printf("Sum: %u\n", computeSum(n));
    return 0;
}